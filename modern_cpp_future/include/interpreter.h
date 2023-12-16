#pragma once
#include "stdinc.h"
#include "compiler.h"

class Interpreter{
private:
    static const std::string fn;
    bool running = true;
public:
    Interpreter();
    void interactive();
    void run(const std::string& code);
};
