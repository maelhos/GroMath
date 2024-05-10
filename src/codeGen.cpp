#include "node.h"
#include "GMcompiler.h"
#include "utils.h"

llvm::Value* NIntConstant::codeGen(GMLLVM* ctx, Env env){
    // must be tune for later TODO: biginted... 
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
    printf("NIdentifier : \"%s\" \n", name.c_str());
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

    for (auto&& stmt : statements)
        stmt->codeGen(ctx, blockEnv);
    
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
    ctx->builder->CreateBr(ifEndBlock);

    thenBlock = ctx->builder->GetInsertBlock();

    ctx->fn->insert(ctx->fn->end(), elseBlock);
    ctx->builder->SetInsertPoint(elseBlock);

    if (ElseBlock) {
        ElseBlock->codeGen(ctx, env);
        ctx->builder->CreateBr(ifEndBlock);

        elseBlock = ctx->builder->GetInsertBlock();

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
    return nullptr;
}