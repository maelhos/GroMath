#pragma once
#include "stdinc.h"
#include "parser/GroMathParser.h"
#include "Environement.h"

using syntax::GroMathParser;
using Env = std::shared_ptr<Environement>;

#define GEN_BINARY_OP(Op, varName)        \
    do {                                  \
        auto op1 = gen(exp.list[1], env); \
        auto op2 = gen(exp.list[2], env); \
        return builder->Op(op1, op2, varName); \
    } while(false)


class GrosMathLLVM {

public:
    GrosMathLLVM() : parser(std::make_unique<GroMathParser>()) {
        moduleInit();
        setupExternFunction();
        setupGlobalEnvironement();
    }

    void exec(const std::string& program) {
        // parse
        auto ast = parser->parse("(begin " + program + ")");
        std::cout << "Successfully parsed !!" << std::endl;
        // compile
        compile(ast);

        // print on stdout
        module->print(llvm::outs(), nullptr);

        // save
        saveModuleToFile("./out.ll");
    }

private:
    void compile(const Exp& ast) {
        fn = createFunction("main", 
            llvm::FunctionType::get(builder->getInt32Ty(), false),
            GlobalEnv);

        createGlobalVar("VERSION", builder->getInt32(42));

        gen(ast, GlobalEnv);

        
        builder->CreateRet(builder->getInt32(0));
    }

    llvm::Value* gen(const Exp& exp, Env env) {
        switch (exp.type) {
            case ExpType::NUMBER:
                return builder->getInt32(exp.number);

            case ExpType::STRING:
                return builder->CreateGlobalStringPtr(parseStrSpecialChars(exp.string));

            case ExpType::SYMBOL:{
                if (exp.string == "true" || exp.string == "false")
                    return builder->getInt1(exp.string == "true" ? 1 : 0);
                
                auto varName = exp.string;
                auto value = env->lookup(varName);
                
                // local vars
                if (auto localVar = llvm::dyn_cast<llvm::AllocaInst>(value))
                    return builder->CreateLoad(localVar->getAllocatedType(),
                        localVar, varName.c_str());

                // global vars
                if (auto globalVar = llvm::dyn_cast<llvm::GlobalVariable>(value))
                    return builder->CreateLoad(globalVar->getInitializer()->getType(), 
                        globalVar, varName.c_str());

                // Function
                return value;
                break;
            }

            case ExpType::LIST: {
                auto tag = exp.list[0];

                if (tag.type == ExpType::SYMBOL){
                    auto op = tag.string;

                    if (op == "+")
                        GEN_BINARY_OP(CreateAdd, "tmpadd"); // the macros actually return ...
                    if (op == "-")
                        GEN_BINARY_OP(CreateSub, "tmpsub");
                    if (op == "*")
                        GEN_BINARY_OP(CreateMul, "tmpmul");
                    if (op == "/")
                        GEN_BINARY_OP(CreateSDiv, "tmpdiv");

                    if (op == ">")
                        GEN_BINARY_OP(CreateICmpUGT, "tmpcmp"); // unsigned !!
                    if (op == "<")
                        GEN_BINARY_OP(CreateICmpULT, "tmpcmp");
                    if (op == "==")
                        GEN_BINARY_OP(CreateICmpEQ, "tmpcmp");
                    if (op == "!=")
                        GEN_BINARY_OP(CreateICmpNE, "tmpcmp");
                    if (op == "==")
                        GEN_BINARY_OP(CreateICmpEQ, "tmpcmp");
                    if (op == "!=")
                        GEN_BINARY_OP(CreateICmpNE, "tmpcmp");
                    if (op == "<=")
                        GEN_BINARY_OP(CreateICmpUGE, "tmpcmp");
                    if (op == ">=")
                        GEN_BINARY_OP(CreateICmpULE, "tmpcmp");

                    if (op == "if"){
                        auto cond = gen(exp.list[1], env);

                        auto thenBlock = createBB("then", fn);

                        // dont specifie parent yet ... may be nested PHI node
                        auto elseBlock = createBB("else");
                        auto ifEndBlock = createBB("ifend");

                        builder->CreateCondBr(cond, thenBlock, elseBlock);

                        builder->SetInsertPoint(thenBlock);
                        auto thenRes = gen(exp.list[2], env);
                        builder->CreateBr(ifEndBlock);

                        thenBlock = builder->GetInsertBlock();

                        fn->insert(fn->end(), elseBlock);
                        // fn->getBasicBlockList().push_back(elseBlock); old syntax
                        builder->SetInsertPoint(elseBlock);
                        auto elseRes = gen(exp.list[3], env);
                        builder->CreateBr(ifEndBlock);

                        elseBlock = builder->GetInsertBlock();

                        fn->insert(fn->end(), ifEndBlock);
                        builder->SetInsertPoint(ifEndBlock);

                        auto phi = builder->CreatePHI(thenRes->getType(),
                            2, "tmpif");

                        phi->addIncoming(thenRes, thenBlock);
                        phi->addIncoming(elseRes, elseBlock);

                        return phi;
                    }


                    if (op == "while"){
                        auto condBlock = createBB("cond", fn);
                        builder->CreateBr(condBlock);

                        auto bodyBlock = createBB("body");
                        auto loopEndBlock = createBB("loopend");

                        builder->SetInsertPoint(condBlock);
                        auto cond = gen(exp.list[1], env);

                        builder->CreateCondBr(cond, bodyBlock, loopEndBlock);

                        fn->insert(fn->end(), bodyBlock);
                        builder->SetInsertPoint(bodyBlock);
                        gen(exp.list[2], env);

                        builder->CreateBr(condBlock);

                        fn->insert(fn->end(), loopEndBlock);
                        builder->SetInsertPoint(loopEndBlock);

                        return builder->getInt32(0);
                    }

                    if (op == "def"){
                        return compileFunction(exp, exp.list[1].string, env);
                    }

                    // (var (x int) 34)
                    // (var (test string) "caca")
                    if (op == "var") {
                        auto varNameDecl = exp.list[1];
                        auto varName = extractVarName(varNameDecl);

                        auto init = gen(exp.list[2], env);

                        auto varTy = extractVarType(varNameDecl);

                        auto varBinding = allocVar(varName, varTy, env);

                        return builder->CreateStore(init, varBinding);
                    }

                    if (op == "set") {
                        auto value = gen(exp.list[2], env);

                        auto varNameDecl = exp.list[1];

                        auto varName = extractVarName(varNameDecl);

                        auto varBinding = env->lookup(varName);

                        builder->CreateStore(value, varBinding);

                        return value;
                    }

                    if (op == "begin") {
                        auto blockEnv = std::make_shared<Environement>(
                            std::map<std::string, llvm::Value*>{}, env);

                        llvm::Value* blockRes;

                        for (uint32_t i = 1; i < exp.list.size(); i++)
                            blockRes = gen(exp.list[i], blockEnv);

                        return blockRes;
                    }

                    if (op == "printf") {
                        auto printfn = module->getFunction("printf");

                        std::vector<llvm::Value*> args{};

                        for (uint32_t i = 1; i < exp.list.size(); i++)
                            args.push_back(gen(exp.list[i], env));
                        
                        return builder->CreateCall(printfn, args);
                    }

                    /// else ... not need cuz other branch return
                    auto callable = gen(exp.list[0], env);
                    std::vector<llvm::Value*> args{};

                    for (int i = 1; i < exp.list.size(); i++)
                        args.push_back(gen(exp.list[i], env));
                    
                    auto fn = (llvm::Function*)callable;

                    return builder->CreateCall(fn, args);
                    ///
                }
                break;
            }
        }

        return builder->getInt32(0);
    }

    std::string parseStrSpecialChars(std::string s){
        static const std::map<std::string, std::string> specialReplace = {
            {"\\\\", "\\"},
            {"\\'", "'"},
            {"\\\"", "\""},
            {"\\n", "\n"},
            {"\\r", "\r"},
            {"\\t", "\t"}
        };

        for (auto &&[first, second] : specialReplace)
            while (s.find(first) != std::string::npos)
                s.replace(s.find(first), first.length(), second);
        return s;
    }

    std::string extractVarName(const Exp& exp) {
        return exp.type == ExpType::LIST ? exp.list[0].string : exp.string;
    }

    llvm::Type* extractVarType(const Exp& exp) {
        return exp.type == ExpType::LIST ? getTypeFromString(exp.list[1].string)
                                            : builder->getInt32Ty();
    }

    llvm::Type* getTypeFromString(const std::string& type) {
        if (type == "number")
            return builder->getInt32Ty();

        if (type == "string")
            return builder->getInt8Ty()->getPointerTo();

        // TODO: should create sonme kind of warning here
        return builder->getInt32Ty();
    }

    bool hasReturnType(const Exp& fnExp){
        return fnExp.list[3].type == ExpType::SYMBOL &&
               fnExp.list[3].string == "->";
    }

    llvm::FunctionType* extractFunctionType(const Exp& fnExp){
        auto params = fnExp.list[2];


        auto returnType = hasReturnType(fnExp)
                            ? getTypeFromString(fnExp.list[4].string)
                            : builder->getInt32Ty();

        std::vector<llvm::Type*> paramTypes{};

        for (auto &&param : params.list)
            paramTypes.push_back(extractVarType(param));

        return llvm::FunctionType::get(returnType, paramTypes, false);
    }

    llvm::Value* compileFunction(const Exp& fnExp, std::string fnName, Env env){
        auto params = fnExp.list[2];
        auto body = hasReturnType(fnExp) ? fnExp.list[5] : fnExp.list[3];

        // save
        auto prevFn = fn;
        auto prevBlock = builder->GetInsertBlock();

        auto newFn = createFunction(fnName, extractFunctionType(fnExp), env);
        fn = newFn;

        int idx = 0;
        auto fnEnv = std::make_shared<Environement>(
            std::map<std::string, llvm::Value*>{}, env);

        for (auto &&arg : fn->args()){
            auto param = params.list[idx++];
            auto argName = extractVarName(param);

            arg.setName(argName);

            auto argBinding = allocVar(argName, arg.getType(), fnEnv);
            builder->CreateStore(&arg, argBinding);
        }
        
        builder->CreateRet(gen(body, fnEnv));

        builder->SetInsertPoint(prevBlock);
        fn = prevFn;

        return newFn;
    }


    llvm::Value* allocVar(const std::string& name, llvm::Type* type, Env env){
        varsBuilder->SetInsertPoint(&fn->getEntryBlock());

        auto varAlloc = varsBuilder->CreateAlloca(type, 0, name.c_str());

        env->define(name, varAlloc);

        return varAlloc;
    }

    llvm::GlobalVariable* createGlobalVar(const std::string& name, llvm::Constant* init) {
        module->getOrInsertGlobal(name, init->getType());

        auto var = module->getNamedGlobal(name);
        var->setAlignment(llvm::MaybeAlign(4));
        var->setConstant(false);
        var->setInitializer(init);

        return var;
    }

    void setupExternFunction() {

        module->getOrInsertFunction("printf", 
            llvm::FunctionType::get(
                builder->getInt32Ty(),
                // builder->getInt8PtrTy(),
                builder->getInt8Ty()->getPointerTo(),
                true
            ));
    }

    llvm::Function* createFunctionProto(const std::string& fnName, llvm::FunctionType* fnType, Env env) {
        auto fnc = llvm::Function::Create(fnType, llvm::Function::ExternalLinkage, fnName, *module);
        
        llvm::verifyFunction(*fnc);

        env->define(fnName, fnc);

        return fnc;

    }

    llvm::BasicBlock* createBB(const std::string& name, llvm::Function* fn = nullptr) {
        return llvm::BasicBlock::Create(*ctx, name, fn);
    }

    void createFunctionBlock(llvm::Function* fn) {
        auto entry = createBB("entry", fn);
        builder->SetInsertPoint(entry);
    }

    llvm::Function* createFunction(const std::string& fnName, llvm::FunctionType* fnType, Env env) {
        auto fnc = module->getFunction(fnName);

        if (fnc == nullptr) {
            fnc = createFunctionProto(fnName, fnType, env);
        }   

        createFunctionBlock(fnc);
        return fnc;
    }

    void saveModuleToFile(const std::string& fileName) {
        std::error_code errorCode;
        llvm::raw_fd_ostream outLL(fileName, errorCode);
        module->print(outLL, nullptr);
    }

    void moduleInit(){
        ctx = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("GroMathllvm", *ctx);

        builder = std::make_unique<llvm::IRBuilder<>>(*ctx);

        varsBuilder = std::make_unique<llvm::IRBuilder<>>(*ctx);
    }

    void setupGlobalEnvironement() {
        std::map<std::string, llvm::Value*> globalObject{
            {"VERSION", builder->getInt32(42)},
        };

        std::map<std::string, llvm::Value*> globalRec{};

        for (auto& entry : globalObject) 
            globalRec[entry.first] = createGlobalVar(entry.first, 
                (llvm::Constant*)entry.second);

        GlobalEnv = std::make_unique<Environement>(globalRec, nullptr);
    }

    std::unique_ptr<GroMathParser> parser;
    Env GlobalEnv;
    llvm::Function* fn; // current function being processed
    std::unique_ptr<llvm::LLVMContext> ctx;
    std::unique_ptr<llvm::Module> module;
    // for stack allocated before the rest
    std::unique_ptr<llvm::IRBuilder<>> varsBuilder;
    std::unique_ptr<llvm::IRBuilder<>> builder;

};

