#pragma once
#include "stdinc.h"
#include "llvm_include.h"
#include "Environement.h"
#include "utils.h"
#include "node.h"

extern int yyparse();
extern FILE *yyin;
extern int yyrestart(FILE*);

using Env = std::shared_ptr<Environement>;

extern NBlock* programBlock;

struct GMLLVM {
    NBlock* entry;
    Env GlobalEnv;
    
    ////////////

    llvm::Function* fn; // current function being processed
    std::unique_ptr<llvm::LLVMContext> ctx;
    std::unique_ptr<llvm::Module> module;

    std::unique_ptr<llvm::IRBuilder<>> varsBuilder;
    std::unique_ptr<llvm::IRBuilder<>> builder;
    
    std::unique_ptr<llvm::FunctionPassManager> FPM;
    std::unique_ptr<llvm::LoopAnalysisManager> LAM;
    std::unique_ptr<llvm::FunctionAnalysisManager> FAM;
    std::unique_ptr<llvm::CGSCCAnalysisManager> CGAM;
    std::unique_ptr<llvm::ModuleAnalysisManager> MAM;
    std::unique_ptr<llvm::PassInstrumentationCallbacks> PIC;
    std::unique_ptr<llvm::StandardInstrumentations> SI;
    ////////////

    bool isCurentBlockTerminated();
    llvm::BasicBlock* createBB(const std::string& name, llvm::Function* fn = nullptr);
    
    llvm::Type* convertType(NIdentifier* ident);
    llvm::Type* extractVarType(ExpressionList* type);

    llvm::FunctionType* extractFunctionType(NFunctionDeclaration* fnExp);
    llvm::Function* createFunctionProto(const std::string& fnName, llvm::FunctionType* fnType, Env env);
    void createFunctionBlock(llvm::Function* fn);
    llvm::Function* createFunction(const std::string& fnName, llvm::FunctionType* fnType, Env env);
    llvm::Value* compileFunction(NFunctionDeclaration* fnExp, Env env);

    llvm::GlobalVariable* createGlobalVar(const std::string& name, llvm::Constant* init);
    llvm::Value* allocVar(const std::string& name, llvm::Type* type, Env env);

    llvm::Value* resolveOperatorInt(int tok, llvm::Value* lhs, llvm::Value* rhs);
    GMLLVM(NBlock* entry);

    std::unique_ptr<llvm::Module> assemble();
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
        outName.append(".ll");
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