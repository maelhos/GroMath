#include "interpreter.h"

const std::string Interpreter::fn = "<stdin>";

Interpreter::Interpreter(){}

static bool keepRunning = true;

void intHandler(int){
    keepRunning = false;
}

void Interpreter::interactive(){
    struct sigaction act;
    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);

    while (keepRunning && running){
        std::string text("");
        std::cout << "GrosMath >";
        std::getline(std::cin, text);

        this->run(text);
    }
}

void Interpreter::run(const std::string& code){
    Compiler compiler(fn, code);
    Compiled cm = compiler.run();

    if (!compiler.hasIssuedError)
        std::cout << cm << std::endl;
}