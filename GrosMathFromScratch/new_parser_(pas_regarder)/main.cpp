#include <stdio.h>
#include "ast.hpp"
#include "lexer.hpp"
#include "parser.hpp"

int main(int argc, char* argv[]){

    if (argc > 1){
        char* fname = argv[1];

        FILE* fptr = fopen(fname, "rb");

        if(!fptr){
            printf("Cannot open %s\n", fname);
            exit(EXIT_FAILURE);
        }
        Lexer myLexer(fptr);
        Token tok;

    }
    return 0;
}