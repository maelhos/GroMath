#pragma once
#include "stdinc.h"

enum Type {
    type_none,
    type_void,
    type_float,
    type_double,
    type_int8,
    type_int32,
    type_int64,
    type_bool,
    type_ZZ
};

class ExprAST {
public:
    Type type = type_none;
    virtual ~ExprAST() = default;
    virtual llvm::Value* codegen() = 0;
};