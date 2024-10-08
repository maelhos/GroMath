#include "node.h"
#include "GMcompiler.h"
#include "utils.h"
#include <NTL/ZZ.h>

llvm::Value* NIntConstant::codeGen(GMLLVM* ctx, Env env){
    // must be tune for later TODO: biginted... 
    // return smallest int type with smallest being 32 bit then 64 bit then ZZ
    NTL::ZZ val2; 
    sizeof(NTL::ZZ);
    int32_t val = strtol(value.c_str(), 0, 10);
    return ctx->builder->getInt32(val);;
}

llvm::Value* NSringConstant::codeGen(GMLLVM* ctx, Env env){
    const std::string val(value.substr(1, value.length() - 2));
    return ctx->builder->CreateGlobalStringPtr(parseStrSpecialChars(val));
}

llvm::Value* NDouble::codeGen(GMLLVM* ctx, Env env){
    // useless, not double in grammar ...
    return nullptr;
}

llvm::Value* NBool::codeGen(GMLLVM* ctx, Env env){
    return ctx->builder->getInt1(value);
}

llvm::Value* NIdentifier::codeGen(GMLLVM* ctx, Env env){
    // printf("NIdentifier : \"%s\" \n", name.c_str());
    auto value = env->lookup(name);
                
    // local vars
    if (auto localVar = llvm::dyn_cast<llvm::AllocaInst>(value))
        return ctx->builder->CreateLoad(localVar->getAllocatedType(),
            localVar, name.c_str());

    // global vars
    if (auto globalVar = llvm::dyn_cast<llvm::GlobalVariable>(value))
        return ctx->builder->CreateLoad(globalVar->getInitializer()->getType(), 
            globalVar, name.c_str());

    // if this called then is a variable load (because of the way the codeGen is built)
    return nullptr;
}

llvm::Value* NMethodCall::codeGen(GMLLVM* ctx, Env env){
    // special function to be done here for now just printf
    llvm::Function* fun;
    if (id.name == "printf")
        fun = ctx->module->getFunction("printf");
    else{
        auto f = env->lookup(id.name);
        fun = llvm::dyn_cast<llvm::Function>(f);
    }

    std::vector<llvm::Value*> args{};

    for (auto&& arg : arguments)
        args.push_back(arg->codeGen(ctx, env));

    if (!fun){
        printf("Identifier \"%s\" is not callable\n", id.name.c_str());
        exit(1);
    }

    return ctx->builder->CreateCall(fun, args);
}

llvm::Value* NBinaryOperator::codeGen(GMLLVM* ctx, Env env){
    // BIG TODO : operator per type + typing system ayaya
    // for now everything is an int

    return ctx->resolveOperatorInt(op, lhs.codeGen(ctx, env), rhs.codeGen(ctx, env));
}

llvm::Value* NAssignment::codeGen(GMLLVM* ctx, Env env){
    auto val = rhs.codeGen(ctx, env);
    auto varBinding = env->lookup(lhs.name);
    ctx->builder->CreateStore(val, varBinding);

    return val;
}

llvm::Value* NBlock::codeGen(GMLLVM* ctx, Env env){
    auto blockEnv = std::make_shared<Environement>(
        std::map<std::string, llvm::Value*>{}, env);

    for (auto&& stmt : statements){
        stmt->codeGen(ctx, blockEnv);
        auto blk = ctx->builder->GetInsertBlock();
        if(ctx->isCurentBlockTerminated()) break; // dont compile unreachable things ...
    }
    
    return nullptr;
}

llvm::Value* NIfStatement::codeGen(GMLLVM* ctx, Env env){
    auto condExpr = conditionExpr->codeGen(ctx, env);

    auto thenBlock  = ctx->createBB("then", ctx->fn);
    auto ifEndBlock = ctx->createBB("ifend");

    llvm::BasicBlock* elseBlock;
    if (ElseBlock) elseBlock = ctx->createBB("else");
    else elseBlock = ifEndBlock;

    ctx->builder->CreateCondBr(condExpr, thenBlock, elseBlock);
    ctx->builder->SetInsertPoint(thenBlock);

    IfBlock->codeGen(ctx, env);
    if (!ctx->isCurentBlockTerminated()) // dont insert branch if already returning...
        ctx->builder->CreateBr(ifEndBlock);

    ctx->fn->insert(ctx->fn->end(), elseBlock);
    ctx->builder->SetInsertPoint(elseBlock);

    if (ElseBlock) {
        ElseBlock->codeGen(ctx, env);
        if (!ctx->isCurentBlockTerminated()) // dont insert branch if already returning...
            ctx->builder->CreateBr(ifEndBlock);

        ctx->fn->insert(ctx->fn->end(), ifEndBlock);
        ctx->builder->SetInsertPoint(ifEndBlock);
    }

    return nullptr;
}

llvm::Value* NBreakStatement::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NContinueStatement::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NReturnStatement::codeGen(GMLLVM* ctx, Env env){
    if (RetExpr)
        ctx->builder->CreateRet(RetExpr->codeGen(ctx, env));
    else
        ctx->builder->CreateRetVoid();
        
    return nullptr;
}

llvm::Value* NWhileStatement::codeGen(GMLLVM* ctx, Env env){
    auto condBlock = ctx->createBB("cond", ctx->fn);
    ctx->builder->CreateBr(condBlock);

    auto bodyBlock = ctx->createBB("body");
    auto loopEndBlock = ctx->createBB("loopend");

    ctx->builder->SetInsertPoint(condBlock);
    auto cond = Expr->codeGen(ctx, env);
    ctx->builder->CreateCondBr(cond, bodyBlock, loopEndBlock);

    ctx->fn->insert(ctx->fn->end(), bodyBlock);
    ctx->builder->SetInsertPoint(bodyBlock);

    WhileBlock->codeGen(ctx, env);
    if (!ctx->isCurentBlockTerminated()){
        auto blk = ctx->builder->GetInsertBlock();
        ctx->builder->CreateBr(condBlock);
    }
                
    ctx->fn->insert(ctx->fn->end(), loopEndBlock);
    ctx->builder->SetInsertPoint(loopEndBlock);

    return nullptr;
}

llvm::Value* NExpressionStatement::codeGen(GMLLVM* ctx, Env env){
    // in this case only assignement and function call are interesting
    if (auto assign = dynamic_cast<NAssignment*>(&expression))
        assign->codeGen(ctx, env);

    if (auto call = dynamic_cast<NMethodCall*>(&expression))
        call->codeGen(ctx, env);

    return nullptr;
}

llvm::Value* NVariableDeclaration::codeGen(GMLLVM* ctx, Env env){
    auto varTy = ctx->extractVarType(&type);
    auto varBinding = ctx->allocVar(id.name, varTy, env);

    if (assignmentExpr)
        ctx->builder->CreateStore(assignmentExpr->codeGen(ctx, env), varBinding);

    return nullptr;
}

llvm::Value* NFunctionDeclaration::codeGen(GMLLVM* ctx, Env env){
    return ctx->compileFunction(this, env);
}

llvm::Value* NRangeIterator::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NForStatement::codeGen(GMLLVM* ctx, Env env){
    auto forEnv = std::make_shared<Environement>(
        std::map<std::string, llvm::Value*>{}, env);

    auto varTy = ctx->extractVarType(&VarDecl->type);
    auto varFor = ctx->allocVar(VarDecl->id.name, varTy, env);
    auto varForBind = llvm::dyn_cast<llvm::AllocaInst>(varFor);

    llvm::Value* incrFor;
    llvm::Value* stopFor;
    bool iter_inclusive = false;
    // init for variable

    // simple range iterator
    if (auto iter_s = dynamic_cast<NRangeIterator*>(Iter)){
        if (iter_s->start)
            ctx->builder->CreateStore(iter_s->start->codeGen(ctx, forEnv), varFor);
        else
            ctx->builder->CreateStore(ctx->builder->getInt32(0), varFor);

        if (iter_s->incr) incrFor = iter_s->incr->codeGen(ctx, forEnv);
        else incrFor = ctx->builder->getInt32(1);

        stopFor = iter_s->stop->codeGen(ctx, forEnv);
        iter_inclusive = iter_s->endInclusive;
    }
    else return nullptr;

    auto condBlock = ctx->createBB("cond", ctx->fn);
    ctx->builder->CreateBr(condBlock);

    auto bodyBlock = ctx->createBB("body");
    auto loopEndBlock = ctx->createBB("loopend");

    ctx->builder->SetInsertPoint(condBlock);

    llvm::Value* cond;
    if (iter_inclusive)
        cond = ctx->builder->CreateICmpSLE(
            ctx->builder->CreateLoad(varForBind->getAllocatedType(), varForBind), 
            stopFor);
    else
        cond = ctx->builder->CreateICmpSLT(
            ctx->builder->CreateLoad(varForBind->getAllocatedType(), varForBind), 
            stopFor);

    ctx->builder->CreateCondBr(cond, bodyBlock, loopEndBlock);

    ctx->fn->insert(ctx->fn->end(), bodyBlock);
    ctx->builder->SetInsertPoint(bodyBlock);

    ForBlock->codeGen(ctx, env);
    ctx->builder->CreateStore(ctx->builder->CreateAdd(
        ctx->builder->CreateLoad(varForBind->getAllocatedType(), varForBind),  
        incrFor), 
        varForBind);

    if (!ctx->isCurentBlockTerminated()){
        auto blk = ctx->builder->GetInsertBlock();
        ctx->builder->CreateBr(condBlock);
    }
                
    ctx->fn->insert(ctx->fn->end(), loopEndBlock);
    ctx->builder->SetInsertPoint(loopEndBlock);
    return nullptr;
}