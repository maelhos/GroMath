#include "node.h"
#include "GMcompiler.h"
#include "utils.h"

llvm::Value* NIntConstant::codeGen(GMLLVM* ctx){
    // must be tune for later
    int32_t val = strtol(value.c_str(), 0, 10);

    return ctx->builder->getInt32(val);;
}

llvm::Value* NSringConstant::codeGen(GMLLVM* ctx){
    const std::string val(value.substr(1, value.length() - 1));
    return ctx->builder->CreateGlobalStringPtr(parseStrSpecialChars(val));
}

llvm::Value* NDouble::codeGen(GMLLVM* ctx){
    // useless, not double in grammar ...
    return nullptr;
}

llvm::Value* NIdentifier::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NMethodCall::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NBinaryOperator::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NAssignment::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NBlock::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NIfStatement::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NBreakStatement::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NContinueStatement::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NReturnStatement::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NWhileStatement::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NExpressionStatement::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NVariableDeclaration::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NFunctionDeclaration::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NRangeIterator::codeGen(GMLLVM* ctx){
    return nullptr;
}

llvm::Value* NForStatement::codeGen(GMLLVM* ctx){
    return nullptr;
}