#include "stdinc.h"
#include "token.h"
#include "ast.h"
#include "interpreter.h"
#include "generator.h"
#include "JIT.h"


#define DLLEXPORT

/// putchard - putchar that takes a double and returns 0.
extern "C" DLLEXPORT double putchard(double X) {
    fputc((char)X, stderr);
    return 0;
}

/// printd - printf that takes a double prints it as "%f\n", returning 0.
extern "C" DLLEXPORT double printd(double X) {
    fprintf(stderr, "%f\n", X);
    return 0;
}

int main(int argc, char* argv[]){
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();

    fprintf(stderr, "Gromath> ");
    getNextToken();
    
    TheJIT = ExitOnErr(GroMathJIT::Create());

    InitializeModule();
    
    MainLoop();

    return 0;
}