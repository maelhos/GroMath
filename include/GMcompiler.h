#pragma once
#include "stdinc.h"
#include "node.h"
#include "llvm_include.h"
#include "Environement.h"

extern NBlock* programBlock;

extern int yyparse();
extern FILE *yyin;
extern int yyrestart(FILE*);

using Env = std::shared_ptr<Environement>;

class GMLLVM {
private:
    NBlock* entry;
    Env GlobalEnv;
    llvm::Function* fn; // current function being processed
    std::unique_ptr<llvm::LLVMContext> ctx;
    std::unique_ptr<llvm::Module> module;

    std::unique_ptr<llvm::IRBuilder<>> varsBuilder;
    std::unique_ptr<llvm::IRBuilder<>> builder;

    llvm::BasicBlock* createBB(const std::string& name, llvm::Function* fn = nullptr) {
        return llvm::BasicBlock::Create(*ctx, name, fn);
    }

    llvm::Function* createFunctionProto(const std::string& fnName, llvm::FunctionType* fnType, Env env) {
        auto fnc = llvm::Function::Create(fnType, llvm::Function::ExternalLinkage, fnName, *module);
        llvm::verifyFunction(*fnc);
        env->define(fnName, fnc);
        return fnc;
    }

    void createFunctionBlock(llvm::Function* fn) {
        auto entry = createBB("entry", fn);
        builder->SetInsertPoint(entry);
    }

    llvm::Function* createFunction(const std::string& fnName, llvm::FunctionType* fnType, Env env) {
        auto fnc = module->getFunction(fnName);

        if (fnc == nullptr)
            fnc = createFunctionProto(fnName, fnType, env);
        

        createFunctionBlock(fnc);
        return fnc;
    }
public: 
    GMLLVM(NBlock* entry) : entry(entry) {
        ctx = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("GroMathLLVM", *ctx);

        builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
        varsBuilder = std::make_unique<llvm::IRBuilder<>>(*ctx);
    }

    std::unique_ptr<llvm::Module> assemble(){
        fn = createFunction("main", 
            llvm::FunctionType::get(builder->getInt32Ty(), false),
            GlobalEnv);

        CodeGenContext ctx;
        auto res = entry->codeGen(ctx);
        auto i32Res = builder->CreateIntCast(res, builder->getInt32Ty(), true);
        
        builder->CreateRet(i32Res);
        
        return std::move(module);
    }
};


class GMcompiler{
private:
    char* toCompile;
    NBlock* MainAst;
    FILE* file;
    std::string outName;

public:
    GMcompiler(char* toCompile) 
        : toCompile(toCompile), MainAst(nullptr), outName(toCompile) {
        file = fopen(toCompile, "r");
        if (!file){
            fprintf(stderr, "No such file or directory or can't open %s\n", toCompile);
            exit(1);
        }
        outName.append(".o");
    }

    void compile(){
        // 1. Parsing
        yyrestart(file);
        yyparse();
        MainAst = programBlock;

        // if testing AST stop here or error
        if (getenv("TEST_PARSER") || !MainAst) return;
    
        // 3. Printing
        std::error_code errCode;
        llvm::raw_fd_ostream outLL(outName, errCode);
        GMLLVM leuleuveumeu(MainAst);
        std::unique_ptr<llvm::Module> module(std::move(leuleuveumeu.assemble()));
        module->print(outLL, nullptr);

    }
};