#pragma once
#include "stdinc.h"

class ErrorLogMessage : public std::basic_ostringstream<char> {
    public :
    ~ErrorLogMessage() {
        std::cerr << "Fatal error :" << str().c_str();
        exit(EXIT_FAILURE);
    }
};

#define DIE ErrorLogMessage()