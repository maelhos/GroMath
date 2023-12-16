#include "type.h"

NameType TypeNameMap = {
    {"void", type_void},
    {"float", type_float},
    {"int8", type_int8},
    {"uint8", type_uint8},
    {"int32", type_int32},
    {"uint32", type_uint32},
    {"int64", type_int64},
    {"uint64", type_uint64},
    {"bool", type_bool},
    {"ZZ", type_ZZ}
};

bool isTypeName(std::string& s){
    return (TypeNameMap.count(s) > 0);
}

llvm::Type* tollvmType(Type t, llvm::LLVMContext& ctx){
    switch (t){
    case type_none:
        std::cout << "Type 'type_none' cant be converted to llvm type..." << std::endl;
        exit(0);
    case type_void:
        return llvm::IntegerType::getVoidTy(ctx);
    case type_float:
        return llvm::IntegerType::getFloatTy(ctx);
    case type_uint8:
    case type_int8:
        return llvm::IntegerType::getInt8Ty(ctx);
    case type_int32:
    case type_uint32:
        return llvm::IntegerType::getInt32Ty(ctx);
    case type_int64:
    case type_uint64:
        return llvm::IntegerType::getInt64Ty(ctx);
    case type_bool:
        return llvm::IntegerType::getInt1Ty(ctx);
    case type_ZZ:
        std::cout << "ZZ type not implemented yet ..." << std::endl;
        exit(0);
    default:
        break;
    }
    std::cout << "Type not found while calling tollbmType." << std::endl;
}

FloatExprAST::FloatExprAST(double _Val) : Val(_Val) {}
IntExprAST::IntExprAST(long long _Val) : Val(_Val) {}
