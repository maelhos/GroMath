#pragma once
#include "stdinc.h"

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum Token {
    tok_eof = -1,

    // commands
    tok_extern = -2,

    // primary
    tok_identifier = -3,
    tok_int = -4,
    tok_float = -5,

    // control
    tok_if = -6,
    tok_then = -7,
    tok_else = -8,

    // for
    tok_for = -9, 
    tok_in = -10
};

extern std::string IdentifierStr; // Filled in if tok_identifier
extern double FloatVal;             // Filled in if tok_number
extern long long IntVal;

extern std::map<char, int> BinopPrecedence;
extern std::map<std::string, int> IdentifierMapTok;
int gettok();
extern int CurTok;

int getNextToken();
int GetTokPrecedence();

extern std::stringstream debug_tokens;