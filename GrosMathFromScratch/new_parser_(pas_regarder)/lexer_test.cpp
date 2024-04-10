#include <stdio.h>
#include "lexer.hpp"

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

        tok = myLexer.look(0);
        printf("TOK : %d, %s\n", tok.first, tok.second.c_str());
        tok = myLexer.look(0);
        printf("TOK : %d, %s\n", tok.first, tok.second.c_str());
        tok = myLexer.look(1);
        printf("TOK : %d, %s\n", tok.first, tok.second.c_str());

        tok = myLexer.getToken();
        printf("\nTOK : %d, %s\n\n", tok.first, tok.second.c_str()); 

        tok = myLexer.look(0);
        printf("TOK : %d, %s\n", tok.first, tok.second.c_str());
        tok = myLexer.look(0);
        printf("TOK : %d, %s\n", tok.first, tok.second.c_str());
        tok = myLexer.look(1);
        printf("TOK : %d, %s\n", tok.first, tok.second.c_str());     
    }
    return 0;
}