#pragma once
#include <stdio.h>
#include <list>
#include <ctype.h>
#include <cassert>

enum TokenType {
    tok_uk = 0,
    tok_eof = 1,
    tok_conststr = 2,
    tok_constint = 3,
    tok_identifier = 4
};

using Token = std::pair<TokenType, std::string>;

// [a-zA-Z_$]
#define isalphaB(c) (c == '_' || c == '$' || isalpha(c))

// [a-zA-Z0-9_$]
#define isalphaC(c) (isdigit(c) || isalphaB(c))

class Lexer{
private:
    FILE* file;
    int LastChar;
    bool done;
    std::list<Token> lookAheadQueue;

    Token fill(){
        if (LastChar == EOF){
            return std::make_pair(tok_eof, "");
            done = true;
        }

        while (isspace(LastChar))
            LastChar = fgetc(file);

        if (LastChar == EOF){
            return std::make_pair(tok_eof, "");
            done = true;
        }

        if (isalphaB(LastChar)){
            std::string retStr(1, LastChar);
            LastChar = fgetc(file);
            while (isalphaC(LastChar)){
                retStr += LastChar;
                LastChar = fgetc(file);
            }
            return std::make_pair(tok_identifier, retStr);
        }

        if (isdigit(LastChar)){
            std::string retStr(1, LastChar);

            while (isdigit((LastChar = fgetc(file))))
                retStr += LastChar;

            return std::make_pair(tok_constint, retStr);
        }

        if (LastChar == '"'){
            LastChar = fgetc(file); // eat first '"'
            if (LastChar == EOF){
                printf("Unterminated string constant at end of file\n");
                exit(EXIT_FAILURE);
            }
            std::string retStr{};

            while (LastChar != '"' && LastChar != EOF){
                retStr += LastChar;
                LastChar = fgetc(file);
            }

            if (LastChar == EOF){
                printf("Unterminated string constant\n");
                exit(EXIT_FAILURE);
            }       
            LastChar = fgetc(file); // eat last '"'
            LastChar = fgetc(file); // prep for next

            return std::make_pair(tok_conststr, retStr);
        }

        if (LastChar == '/'){
            LastChar = fgetc(file);

            if (LastChar == '/'){
                LastChar = fgetc(file);
                while (LastChar != '\n' && LastChar != EOF)
                    LastChar = fgetc(file);
                return fill();
            }

            return std::make_pair(tok_uk, std::string(1, '/'));
        }

        int lchar = LastChar;
        LastChar = fgetc(file);
        return std::make_pair(tok_uk, std::string(1, lchar));
    }
public:
    Lexer(FILE* file) : file(file), LastChar(' '), done(false) {}

    Token getToken(){
        if (lookAheadQueue.empty())
            lookAheadQueue.push_back(fill());
        Token ret = lookAheadQueue.front();

        if (ret.first != tok_eof) lookAheadQueue.pop_front();
        else done = true;
        
        return ret;
    }

    Token look(int where){
        assert(where >= 0);
        while (lookAheadQueue.size() < where + 1)
            lookAheadQueue.push_back(fill());
        
        auto it = lookAheadQueue.begin();
        std::advance(it, where);
        Token ret = *it;

        return ret;
    }  
};
