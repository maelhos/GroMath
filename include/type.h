#pragma once
#include "stdinc.h"
#include "expr.h"

enum Type {
    type_none,
    type_void,
    type_float,
    type_int8,
    type_uint8,
    type_int32,
    type_uint32,
    type_int64,
    type_uint64,
    type_bool,
    type_ZZ
};

typedef std::map<std::string, Type> NameType;
extern NameType TypeNameMap;

bool isTypeName(std::string& s);
llvm::Type* tollvmType(Type t, llvm::LLVMContext& ctx);

class FloatExprAST : public ExprAST {
    double Val;
public:
    FloatExprAST(double _Val);
    llvm::Value* codegen() override;
};

class IntExprAST : public ExprAST {
    long long Val;
public:
    IntExprAST(long long _Val);
    llvm::Value* codegen() override;
};