#include "stdinc.h"
#include "token.h"
#include "lexer.h"
#include "interpreter.h"

int main(int argc, char* argv[]){
    
    Interpreter inter{};
    inter.interactive();
    
    return 0;
}