#pragma once
#include "stdinc.h"
#include "token.h"
#include "position.h"
#include "error.h"

class Lexer{

private:
    const std::string fn;
    const std::string text;
    std::vector<Token> tokens{};

    Position pos;
    char current_char = 0;

    std::ostringstream CurrentLine;

    void next_char();
    void next_n_char(uint32_t n);
    
    void lex_number();

    std::ostringstream errors;

public:
    Lexer(const std::string& _fn, const std::string& _text);
    std::vector<Token> lex();

    std::string getErrors();
};
