#include "stdinc.h"
#include "GMcompiler.h"
#include "parser.hpp"

#define GEN_BINARY_OP(Op, varName) return builder->Op(lhs, rhs, (varName));

llvm::Value* GMLLVM::resolveOperatorInt(int tok, llvm::Value* lhs, llvm::Value* rhs){
    switch (tok){
    case TPLUS:
        GEN_BINARY_OP(CreateAdd, "tmpadd");
    case TMINUS:
        GEN_BINARY_OP(CreateSub, "tmpsub");
    case TMUL:
        GEN_BINARY_OP(CreateMul, "tmpmul");
    case TDIV:
        GEN_BINARY_OP(CreateSDiv, "tmpdiv");

    case TCGT:
        GEN_BINARY_OP(CreateICmpSGT, "tmpcmp");
    case TCLT:
        GEN_BINARY_OP(CreateICmpSLT, "tmpcmp");
    case TCEQ:
        GEN_BINARY_OP(CreateICmpEQ, "tmpcmp");
    case TCNE:
        GEN_BINARY_OP(CreateICmpNE, "tmpcmp");
    case TCLE:
        GEN_BINARY_OP(CreateICmpSGE, "tmpcmp");
    case TCGE:
        GEN_BINARY_OP(CreateICmpSLE, "tmpcmp");    
    default:
        printf("Unkwnon token as binop for integer !\n");
        exit(1);
    }
}