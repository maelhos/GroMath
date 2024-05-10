#include "GMcompiler.h"

bool GMLLVM::isCurentBlockTerminated(){
    auto blk = builder->GetInsertBlock();
    return blk && (blk->begin() != blk->end()) && blk->rbegin()->isTerminator();
}

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

llvm::Value* GMLLVM::allocVar(const std::string& name, llvm::Type* type, Env env){
    varsBuilder->SetInsertPoint(&fn->getEntryBlock());

    auto varAlloc = varsBuilder->CreateAlloca(type, 0, name.c_str());
    
    env->define(name, varAlloc);

    return varAlloc;
}

llvm::FunctionType* GMLLVM::extractFunctionType(NFunctionDeclaration* fnExp){
    auto returnType = extractVarType(fnExp->retType);

    std::vector<llvm::Type*> paramTypes{};

    for (auto &&decl : fnExp->arguments)
        paramTypes.push_back(extractVarType(&decl->type));

    return llvm::FunctionType::get(returnType, paramTypes, false);
}

llvm::Value* GMLLVM::compileFunction(NFunctionDeclaration* fnExp, Env env){
    // save
    auto prevFn = fn;
    auto prevBlock = builder->GetInsertBlock();

    auto newFn = createFunction(fnExp->id.name, extractFunctionType(fnExp), env);
    fn = newFn;

    int idx = 0;
    auto fnEnv = std::make_shared<Environement>(
        std::map<std::string, llvm::Value*>{}, env
    );

    for (auto &&arg : fn->args()){
        auto argName = fnExp->arguments[idx++]->id.name;

        arg.setName(argName);

        auto argBinding = allocVar(argName, arg.getType(), fnEnv);
        builder->CreateStore(&arg, argBinding);
    }
    
    fnExp->block.codeGen(this, fnEnv);

    builder->SetInsertPoint(prevBlock);
    fn = prevFn;

    return newFn;
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

    // for debug
    module->getOrInsertFunction("printf", 
            llvm::FunctionType::get(
                builder->getInt32Ty(),
                // builder->getInt8PtrTy(),
                builder->getInt8Ty()->getPointerTo(),
                true
            ));

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
    //res = builder->getInt32(42);
    //auto i32Res = builder->CreateIntCast(res, builder->getInt32Ty(), true);
    
    //builder->CreateRet(i32Res);
    
    return std::move(module);
}