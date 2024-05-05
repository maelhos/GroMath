#include "GMcompiler.h"

llvm::BasicBlock* GMLLVM::createBB(const std::string& name, llvm::Function* fn) {
    return llvm::BasicBlock::Create(*ctx, name, fn);
}

llvm::Function* GMLLVM::createFunctionProto(const std::string& fnName, llvm::FunctionType* fnType, Env env) {
    auto fnc = llvm::Function::Create(fnType, llvm::Function::ExternalLinkage, fnName, *module);
    llvm::verifyFunction(*fnc);
    env->define(fnName, fnc);
    return fnc;
}

void GMLLVM::createFunctionBlock(llvm::Function* fn) {
    auto entry = createBB("entry", fn);
    builder->SetInsertPoint(entry);
}

llvm::Function* GMLLVM::createFunction(const std::string& fnName, llvm::FunctionType* fnType, Env env) {
    auto fnc = module->getFunction(fnName);
    if (fnc == nullptr)
        fnc = createFunctionProto(fnName, fnType, env);
    
    createFunctionBlock(fnc);
    return fnc;
}

llvm::GlobalVariable* GMLLVM::createGlobalVar(const std::string& name, llvm::Constant* init) {
    module->getOrInsertGlobal(name, init->getType());
    auto var = module->getNamedGlobal(name);
    var->setAlignment(llvm::MaybeAlign(4));
    var->setConstant(false);
    var->setInitializer(init);
    return var;
}

GMLLVM::GMLLVM(NBlock* entry) : entry(entry) {
    //setup global LLVM stuff
    ctx = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>("GroMathLLVM", *ctx);

    builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
    varsBuilder = std::make_unique<llvm::IRBuilder<>>(*ctx);

    //setup global env
    std::map<std::string, llvm::Value*> globalObject{
        {"VERSION", builder->getInt32(1)},
    };

    std::map<std::string, llvm::Value*> globalRec{};

    for (auto& entry : globalObject) 
        globalRec[entry.first] = createGlobalVar(entry.first, 
            (llvm::Constant*)entry.second);

    GlobalEnv = std::make_unique<Environement>(globalRec, nullptr);
}

std::unique_ptr<llvm::Module> GMLLVM::assemble(){
    fn = createFunction("main", 
        llvm::FunctionType::get(builder->getInt32Ty(), false),
        GlobalEnv);

    auto res = entry->codeGen(this, GlobalEnv);

    if (getenv("JSON_AST")){
        auto json = entry->toJsonStr();

        printf("\nPrinting JSON :\n");

        FILE* json_out = fopen("out_ast.json", "w");
        fwrite(json.c_str(), 1, json.size(), json_out);
        fclose(json_out);

        system("cat out_ast.json | jq");
    }
    
    //temp for testings
    res = builder->getInt32(42);
    auto i32Res = builder->CreateIntCast(res, builder->getInt32Ty(), true);
    
    builder->CreateRet(i32Res);
    
    return std::move(module);
}