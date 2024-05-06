#include "node.h"
#include "GMcompiler.h"
#include "utils.h"

llvm::Value* NIntConstant::codeGen(GMLLVM* ctx, Env env){
    // must be tune for later TODO: biginted... 
    int32_t val = strtol(value.c_str(), 0, 10);

    return ctx->builder->getInt32(val);;
}

llvm::Value* NSringConstant::codeGen(GMLLVM* ctx, Env env){
    const std::string val(value.substr(1, value.length() - 1));
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
    return nullptr;
}

llvm::Value* NMethodCall::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NBinaryOperator::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NAssignment::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NBlock::codeGen(GMLLVM* ctx, Env env){
    printf("NBlock\n");
    for (auto&& stmt : statements)
        stmt->codeGen(ctx, env);
    
    return nullptr;
}

llvm::Value* NIfStatement::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NBreakStatement::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NContinueStatement::codeGen(GMLLVM* ctx, Env env){
    return nullptr;
}

llvm::Value* NReturnStatement::codeGen(GMLLVM* ctx, Env env){
    printf("NRet\n");
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
    return nullptr;
}

llvm::Value* NVariableDeclaration::codeGen(GMLLVM* ctx, Env env){
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