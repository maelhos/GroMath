#pragma once
#include "ast.hpp"
#include "lexer.hpp"
#include "error.hpp"

std::unique_ptr<MainAST> parseMain(Lexer& lex){
    std::unique_ptr<MainAST> ret = std::make_unique<MainAST>();
    while (1){
        Token tok = lex.look(0);

        if (tok.first == tok_eof)
            return ret;
    
        else if (tok.first == tok_identifier){
            if (tok.second == "fn")
                ret->AddFnDeclAST(parseFnDecl(lex));
            else if (tok.second == "obj")
                ret->AddObjDecl(parseObjDecl(lex));
            else{
                printf("Unknow Identifier in MainAST : %s\n", tok.second.c_str());
                exit(1);
            }
        }
        else{
            printf("Unknow Identifier in MainAST : %s\n", tok.second.c_str());
            exit(1);
        }
    }
}

std::unique_ptr<ObjDeclAST> parseObjDecl(Lexer& lex){
    lex.getToken(); // eat "obj"

    Token tok = lex.getToken();
    checkToken(tok, tok_identifier, "Expected name Identifier for obj declaration\n");

    std::unique_ptr<ObjDeclAST> ret(tok.second);

    tok = lex.getToken();
    checkToken(tok, tok_uk, "{", "Expected \"{\" in obj declaration\n");

    tok = lex.getToken();
    while (tok.first != tok_uk || tok.second != "}"){
        // parse entries
        std::unique_ptr<TypeAST> type = parseType(lex);
        Token tok_name = lex.getToken();
        checkToken(tok, tok_identifier, "Expected \"identifier\" in obj declaration\n");
        ret->AddParam(tok_name.second, std::move(type));

        Token last = lex.look(0);
        if (last.first == tok_uk && last.second == ",")
            lex.getToken();
    }
    lex.getToken(); // eat clolsing bracket
}