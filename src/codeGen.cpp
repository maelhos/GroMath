#include "node.h"

llvm::Value* NIntConstant::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NSringConstant::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NDouble::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NIdentifier::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NMethodCall::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NBinaryOperator::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NAssignment::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NBlock::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NIfStatement::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NBreakStatement::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NContinueStatement::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NReturnStatement::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NWhileStatement::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NExpressionStatement::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NVariableDeclaration::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NFunctionDeclaration::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NRangeIterator::codeGen(CodeGenContext& ctx){
    return nullptr;
}

llvm::Value* NForStatement::codeGen(CodeGenContext& ctx){
    return nullptr;
}