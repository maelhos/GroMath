#include "token.h"

std::string IdentifierStr;
double FloatVal;
long long IntVal;       

std::stringstream debug_tokens("");
int CurTok;

std::map<char, int> BinopPrecedence = {
    {'<', 10},
    {'>', 10},
    {'+', 20},
    {'-', 30},
    {'*', 40}
};

std::map<std::string, int> IdentifierMapTok = {
    {"extern", tok_extern},
    {"if", tok_if},
    {"then", tok_then},
    {"else", tok_else},
    {"for", tok_for},
    {"in", tok_in}
};

int gettok() {
    static int LastChar = ' ';

    // Skip any whitespace.
    while (isspace(LastChar))
        LastChar = getchar();

    if (isalpha(LastChar)) { // identifier: [a-zA-Z][a-zA-Z0-9]*
        IdentifierStr = LastChar;
        while (isalnum((LastChar = getchar())))
            IdentifierStr += LastChar;

        if (IdentifierMapTok.count(IdentifierStr) > 0) // for some reason even though contains exist in c++20, doesnt work...
            return IdentifierMapTok[IdentifierStr];
        return tok_identifier;
    }


    if (isdigit(LastChar) || LastChar == '.') { // Number: [0-9.]+
        bool isFloat = (LastChar == '.');
        std::string NumStr;
        do {
            NumStr += LastChar;
            LastChar = getchar();
            isFloat |= (LastChar == '.');
        } while (isdigit(LastChar) || LastChar == '.');

        if (isFloat){
            FloatVal = strtod(NumStr.c_str(), nullptr);
            return tok_float;
        }
        else{
            IntVal = strtoll(NumStr.c_str(), nullptr, 10);
            return tok_int;
        }
    }

    if (LastChar == '#') {
        // Comment until end of line.
        do
            LastChar = getchar();
        while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

        if (LastChar != EOF)
            return gettok();
    }

    // Check for end of file.  Don't eat the EOF.
    if (LastChar == EOF)
        return tok_eof;

    // Otherwise, just return the character as its ascii value.
    int ThisChar = LastChar;
    LastChar = getchar();
    return ThisChar;
}

int getNextToken() {
    CurTok = gettok();
    switch (CurTok){
    case tok_eof:
        debug_tokens << "tok_eof ";
        break;
    case tok_extern:
        debug_tokens << "tok_extern ";
        break;
    case tok_identifier:
        debug_tokens << "tok_identifier(\"" << IdentifierStr << "\") ";
        break;
    case tok_int:
        debug_tokens << "tok_int(" << IntVal << ") ";
        break;
    case tok_float:
        debug_tokens << "tok_float(" << FloatVal << ") ";
        break;
    default:
        debug_tokens << "tok_chr('" << (char)CurTok << "') ";
        break;
    }

    return CurTok;
}

int GetTokPrecedence() {
    if (!isascii(CurTok))
        return -1;

    // Make sure it's a declared binop.
    int TokPrec = BinopPrecedence[CurTok];
    if (TokPrec <= 0) return -1;
    return TokPrec;
}