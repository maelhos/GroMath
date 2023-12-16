#include "error.h"

Error::Error(Position _pos_start, Position _pos_end, std::string _error_name, std::string _details)
    : pos_start(_pos_start), pos_end(_pos_end), error_name(_error_name), details(_details) {}

std::ostream& operator<<(std::ostream& os, const Error& error){
    os << error.error_name << ": " << error.details << std::endl;
    os << "File " << error.pos_end.fn << ", line " << error.pos_start.ln + 1 <<  ", char " << error.pos_start.col + 1;

    return os;
}

////////// IllegalCharError
const std::string IllegalCharError::name = "Illegal Character";
IllegalCharError::IllegalCharError(Position _pos_start, Position _pos_end, std::string _details) 
    : Error(_pos_start, _pos_end, name, _details) {}

////////// IllegalSyntaxError
const std::string IllegalSyntaxError::name = "Illegal Syntax";
IllegalSyntaxError::IllegalSyntaxError(Position _pos_start, Position _pos_end, std::string _details) 
    : Error(_pos_start, _pos_end, name, _details) {}