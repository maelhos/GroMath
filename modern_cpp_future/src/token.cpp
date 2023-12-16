#include "token.h"

///////////////////////////////////// Variable Token

std::ostream& operator<<(std::ostream& os, const Token_INT& tok ){  
    os << "TOK_INT:" << tok.value;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Token_FLOAT& tok ){  
    os << "TOK_FLOAT:" << tok.value;
    return os;
}

///////////////////////////////////// Generic Token

std::ostream& operator<<(std::ostream& os, const Token_PLUS& tok ){
    os << "TOK_PLUS"; return os;
}

std::ostream& operator<<(std::ostream& os, const Token_MINUS& tok ){
    os << "TOK_MINUS"; return os;
}

std::ostream& operator<<(std::ostream& os, const Token_MUL& tok ){
    os << "TOK_MUL"; return os;
}

std::ostream& operator<<(std::ostream& os, const Token_DIV& tok ){
    os << "TOK_DIV"; return os;
}

/////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Token_RPAR& tok ){
    os << "TOK_RPAR"; return os;
}

std::ostream& operator<<(std::ostream& os, const Token_LPAR& tok ){
    os << "TOK_LPAR"; return os;
}

/////////////////////////////////////

std::ostream& operator<<(std::ostream& os, const Token_COMM& tok ){
    os << "TOK_COMM"; return os;
}

std::ostream& operator<<(std::ostream& os, const Token_EOL& tok ){
    os << "TOK_EOL"; return os;
}

std::ostream& operator<<(std::ostream& os, const Token_EOF& tok ){
    os << "TOK_EOF"; return os;
}

////////////// operator Token ///////////////

std::ostream& operator<<(std::ostream& os, const Token& tok){
    std::visit([&](auto&& arg){ os << arg; }, tok);
    return os;
}