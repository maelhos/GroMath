#pragma once
#include "stdinc.h"
#include "position.h"

class Error{
private:
    
    Position pos_start;
    Position pos_end;

    std::string error_name;
    std::string details;
public:
    Error(Position _pos_start, Position _pos_end, std::string _error_name, std::string _details);

    friend std::ostream& operator<<(std::ostream& os, const Error& tok);
};

class IllegalCharError : public Error {
    static const std::string name;
public:
    IllegalCharError(Position _pos_start, Position _pos_end, std::string _details);
};

class IllegalSyntaxError : public Error {
    static const std::string name;
public:
    IllegalSyntaxError(Position _pos_start, Position _pos_end, std::string _details);
};