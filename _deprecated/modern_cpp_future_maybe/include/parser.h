#pragma once
#include "stdinc.h"
#include "token.h"
#include "node.h"

class Parser{
private:
    std::vector<Token> tokens;
    int32_t tok_idx = -1;
    Token current_tok = Token_EOF();

    template<typename... Args>
    Node parse_bin_op(Node (Parser::*func)(void));
    template<typename T, typename... Args>
    Node parse_match();

    Node parse_expr();
    Node parse_term();
    Node parse_factor();
public:
    bool hasIssuedError = false;
    
    Parser(std::vector<Token>& _tokens);
    Node parse();
    void advance();
};
