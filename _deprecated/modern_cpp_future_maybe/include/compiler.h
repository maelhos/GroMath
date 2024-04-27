#pragma once
#include "stdinc.h"
#include "lexer.h"
#include "parser.h"

// As I implement more things I can change these to my liking
using Compiled = Node;

class Compiler{
private:
    std::string fn;
    std::string text;
    std::string errors; 

    std::vector<std::string> lines;
public:
    bool hasIssuedError = false;
    Compiler(const std::string& _fn, const std::string& _text);
    Compiled run();
};