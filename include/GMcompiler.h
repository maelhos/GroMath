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

    std::unique_ptr<llvm::Module> assemble(){
        // TODO

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
        // if testing AST stop here
        if (getenv("TEST_PARSER")) return;
    
        // 3. Printing
        std::error_code errCode;
        llvm::raw_fd_ostream outLL(outName, errCode);
        GMLLVM leuleuveumeu(MainAst);
        std::unique_ptr<llvm::Module> module(std::move(leuleuveumeu.assemble()));
        module->print(outLL, nullptr);

    }
};