#include "parser.h"

Parser::Parser(std::vector<Token>& _tokens) : tokens(_tokens) {
    this->advance();
}

void Parser::advance(){
    tok_idx++;
    current_tok = tok_idx < (int32_t)tokens.size() ? tokens[tok_idx] : Token_EOF();
}

Node Parser::parse(){
    return this->parse_expr();
}

template<typename... Args>
Node Parser::parse_bin_op(Node (Parser::*func)(void)){
    Node left = (*this.*func)();
    bool loop_condition = false;

    do {
        loop_condition = false;
        std::visit(overloaded{
            [](auto&& arg){},
            [&](Args tok) {
                loop_condition = true;
                Token op_tok(current_tok);
                this->advance();
                Node right = (*this.*func)();
                left = std::make_unique<BinOpNode>(std::move(left), op_tok, std::move(right));
            }...
        }, current_tok);
    } while (loop_condition);

    return left;
}

Node Parser::parse_expr(){
    return this->parse_bin_op<Token_PLUS, Token_MINUS>(&Parser::parse_term);
}

Node Parser::parse_term(){
    return this->parse_bin_op<Token_MUL, Token_DIV>(&Parser::parse_factor);
}

template<typename T, typename... Args>
Node Parser::parse_match(){
    Node ret = std::make_unique<ErrorNode>();
    std::visit( overloaded{
            [&](auto&& arg){ hasIssuedError = true;},
            [&](Args tok) {
                ret = std::make_unique<T>(current_tok);
                this->advance();
            }...
    }, current_tok);
    return ret;
}

Node Parser::parse_factor(){
    return this->parse_match<NumberNode, Token_INT, Token_FLOAT>();
}