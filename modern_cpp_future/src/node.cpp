#include "node.h"

ErrorNode::ErrorNode() {}

NumberNode::NumberNode(Token _tok) : tok(_tok) {}

BinOpNode::BinOpNode(Node _lnode, Token _tok, Node _rnode) 
    : lnode(std::move(_lnode)), tok(_tok), rnode(std::move(_rnode)) {}


std::ostream& operator<<(std::ostream& os, const ErrorNode& node){
    os << "ERROR_NODE";
    return os;
}


std::ostream& operator<<(std::ostream& os, const NumberNode& node){
    os << node.tok;
    return os;
}

std::ostream& operator<<(std::ostream& os, const BinOpNode& node){
    //std::cout << "e";
    os << "{" << node.lnode << ", " << node.tok << ", " << node.rnode << "}";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Node& node){
    //std::cout << "look";
    std::visit([&](auto&& arg){ os << *arg; }, node);
    return os;
}