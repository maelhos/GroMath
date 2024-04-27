#pragma once
#include "stdinc.h"

///////////////////////////////////// Variable Token

class Token_INT{
    public:
    int value;
    Token_INT(int _value) : value(_value) {}
    friend std::ostream& operator<<(std::ostream& os, const Token_INT& tok);
};

class Token_FLOAT{
    public:
    float value;
    Token_FLOAT(float _value) : value(_value) {}

    friend std::ostream& operator<<(std::ostream& os, const Token_FLOAT& tok);
};

///////////////////////////////////// Generic Token

class Token_PLUS{
    public:
    Token_PLUS() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_PLUS& tok);
};

class Token_MINUS{
    public:
    Token_MINUS() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_MINUS& tok);
};

class Token_MUL{
    public:
    Token_MUL() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_MUL& tok);
};

class Token_DIV{
    public:
    Token_DIV() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_DIV& tok);
};

/////////////////////////////////////

class Token_LPAR{
    public:
    Token_LPAR() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_LPAR& tok);
};

class Token_RPAR{
    public:
    Token_RPAR() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_RPAR& tok);
};

/////////////////////////////////////

class Token_COMM{
    public:
    Token_COMM() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_COMM& tok);
};

class Token_EOL{
    public:
    Token_EOL() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_EOL& tok);
};

class Token_EOF{
    public:
    Token_EOF() {}
    friend std::ostream& operator<<(std::ostream& os, const Token_EOF& tok);
};

/////////////////////////////////////

using GenericToken = std::variant<Token_PLUS, Token_MINUS, Token_MUL, Token_DIV, 
    Token_RPAR, Token_LPAR, Token_COMM, Token_EOL, Token_EOF>;

using Token        = std::variant<Token_PLUS, Token_MINUS, Token_MUL, Token_DIV, 
    Token_RPAR, Token_LPAR, Token_COMM, Token_EOL, Token_EOF,
    Token_INT, Token_FLOAT>;

std::ostream& operator<<(std::ostream& os, const Token& tok);