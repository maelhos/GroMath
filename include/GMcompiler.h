#pragma once
#include "stdinc.h"
#include "node.h"
#include "llvm_include.h"

extern NBlock* programBlock;

extern int yyparse();
extern FILE *yyin;
extern int yyrestart(FILE*);

class GMLLVM {
private:
    NBlock* entry;
    std::unique_ptr<llvm::LLVMContext> ctx;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> varsBuilder;
    std::unique_ptr<llvm::IRBuilder<>> builder;
public: 
    GMLLVM(NBlock* entry) : entry(entry) {
        ctx = std::make_unique<llvm::LLVMContext>();
        module = std::make_unique<llvm::Module>("GroMathLLVM", *ctx);
        builder = std::make_unique<llvm::IRBuilder<>>(*ctx);
        varsBuilder = std::make_unique<llvm::IRBuilder<>>(*ctx);
    }
};


class GMcompiler{
private:
    std::vector<FILE*> toCompile;
    NBlock* MainAst;

    void compileFile(FILE* f){
        // 1. Parsing
        yyrestart(f);
        yyparse();
        MainAst = programBlock;

        GMLLVM leuleuveumeu(MainAst);
        // TODO : actually do the thing lol
    }

public:
    GMcompiler(std::vector<FILE*>& toCompile) 
        : toCompile(toCompile), MainAst(nullptr) {}

    void compile(){
        for (auto&& f : toCompile)
            compileFile(f);
    }
};