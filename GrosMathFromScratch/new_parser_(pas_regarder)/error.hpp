#include <stdio.h>
#include "lexer.hpp"

void checkToken(Token& tok, TokenType type, std::string& val, std::string& errormsg){
    if (tok.first != type || tok.second != val){
        printf(errormsg._str());
        exit(1);
    }
}

void checkToken(Token& tok, TokenType type, std::string& errormsg){
    if (tok.first != type){
        printf(errormsg._str());
        exit(1);
    }
}
