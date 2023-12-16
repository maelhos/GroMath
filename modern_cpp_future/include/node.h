#pragma once
#include "stdinc.h"
#include "token.h"


using Node = std::variant<std::unique_ptr<struct ErrorNode>, std::unique_ptr<struct NumberNode>, std::unique_ptr<struct BinOpNode>>;

class ErrorNode{
public:
    ErrorNode();
    friend std::ostream& operator<<(std::ostream& os, const ErrorNode& node);
};

class NumberNode{
private:
    Token tok;
public:
    NumberNode(Token _tok);
    friend std::ostream& operator<<(std::ostream& os, const NumberNode& node);
};

class BinOpNode{
private:
    Node lnode;
    Token tok;
    Node rnode;
public:
    BinOpNode(Node _lnode, Token _tok, Node _rnode);
    friend std::ostream& operator<<(std::ostream& os, const BinOpNode& Node);
};

std::ostream& operator<<(std::ostream& os, const Node& node);