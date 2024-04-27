#include "interpreter.h"

llvm::ExitOnError ExitOnErr;

void HandleIdentifierExpression(){
    std::string FnName = IdentifierStr;
    if (isTypeName(IdentifierStr)) // for some reason even though contains exist in c++20, doesnt work...
        HandleDefinition();
    else
        HandleTopLevelExpression();
}

void HandleDefinition() {
    if (auto FnAST = ParseDefinition()) {
        if (auto *FnIR = FnAST->codegen()) {
            fprintf(stderr, "------------------\nRead function definition:\n");
            FnIR->print(llvm::errs());
            ExitOnErr(TheJIT->addModule(llvm::orc::ThreadSafeModule(std::move(TheModule), std::move(TheContext))));
            InitializeModule();
        }
        fprintf(stderr, "------------------\nTOKENS : %s\n", debug_tokens.str().c_str());
    } 
    else 
        getNextToken();
    
}

void HandleExtern() {
    if (auto ProtoAST = ParseExtern()) {
        if (auto *FnIR = ProtoAST->codegen()) {
            fprintf(stderr, "Read extern: ");
            FnIR->print(llvm::errs());
            FunctionProtos[ProtoAST->getName()] = std::move(ProtoAST);
        }
    } 
    else
        getNextToken();

}

void HandleTopLevelExpression() {
    // Evaluate a top-level expression into an anonymous function.
    if (auto FnAST = ParseTopLevelExpr()) {
        if (FnAST->codegen()) {
            // Create a ResourceTracker to track JIT'd memory allocated to our
            // anonymous expression -- that way we can free it after executing.
            auto RT = TheJIT->getMainJITDylib().createResourceTracker();

            auto TSM = llvm::orc::ThreadSafeModule(std::move(TheModule), std::move(TheContext));
            ExitOnErr(TheJIT->addModule(std::move(TSM), RT));
            InitializeModule();

            // Search the JIT for the __anon_expr symbol.
            auto ExprSymbol = ExitOnErr(TheJIT->lookup("__anon_expr"));

            // Get the symbol's address and cast it to the right type (takes no
            // arguments, returns a double) so we can call it as a native function.
            double (*FP)() = ExprSymbol.getAddress().toPtr<double (*)()>();
            fprintf(stderr, "%f\n", FP());

            // Delete the anonymous expression module from the JIT.
            ExitOnErr(RT->remove());
        }
    } else
        getNextToken();

}


void MainLoop() {
    while (true) {
        switch (CurTok) {
        case tok_eof:
            return;
        case ';': // ignore top-level semicolons.
            getNextToken();
            break;
        case tok_identifier:
            HandleIdentifierExpression();
            break;
        case tok_extern:
            HandleExtern();
            break;
        default:
            fprintf(stderr, "Error handling unkwnown token...\n");
            getNextToken(); // to avoid looooops...
            break;
        }
        fprintf(stderr, "Gromath> ");
        
        debug_tokens.str(std::string());
        debug_parse.str(std::string());
        indentation = 0;
    }
    
}