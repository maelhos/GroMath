#include "stdinc.h"
#include "ast.h"
#include "JIT.h"

extern std::unique_ptr<llvm::LLVMContext> TheContext;
extern std::unique_ptr<llvm::IRBuilder<>> Builder;
extern std::unique_ptr<llvm::Module> TheModule;

extern std::map<std::string, std::unique_ptr<PrototypeAST>> FunctionProtos;
extern std::map<std::string, llvm::Value *> NamedValues;

extern std::unique_ptr<GroMathJIT> TheJIT;

extern std::unique_ptr<llvm::FunctionPassManager> TheFPM;
extern std::unique_ptr<llvm::LoopAnalysisManager> TheLAM;
extern std::unique_ptr<llvm::FunctionAnalysisManager> TheFAM;
extern std::unique_ptr<llvm::CGSCCAnalysisManager> TheCGAM;
extern std::unique_ptr<llvm::ModuleAnalysisManager> TheMAM;
extern std::unique_ptr<llvm::PassInstrumentationCallbacks> ThePIC;
extern std::unique_ptr<llvm::StandardInstrumentations> TheSI;

void InitializeModule();
llvm::Function* getFunction(std::string Name);

llvm::Value* LogErrorV(const char *Str);

// the rest is just godegen method for classes in ast.h