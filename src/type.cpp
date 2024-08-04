#include "GMcompiler.h"

llvm::Type* GMLLVM::convertType(NIdentifier* ident){
    auto name = ident->name;

    if (name == "int")
        return builder->getInt32Ty();
    
    if (name == "ZZ")
        return builder->getPtrTy();
    
    printf("Unknown type \"%s\"...\n", name.c_str());
    exit(1);
}

llvm::Type* GMLLVM::extractVarType(ExpressionList* type){
    if (type->size() == 0)
        return builder->getVoidTy();

    if (type->size() == 1)
        return convertType(static_cast<NIdentifier*>(type->at(0)));

    auto returnType = convertType(static_cast<NIdentifier*>(type->at(type->size() - 1)));
    std::vector<llvm::Type*> paramTypes{};
    for (int i = 0; i < type->size() - 1; i++)
        paramTypes.push_back(convertType(static_cast<NIdentifier*>(type->at(i))));
    

    return llvm::FunctionType::get(returnType, paramTypes, false);
}

