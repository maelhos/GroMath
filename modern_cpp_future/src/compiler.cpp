#include "compiler.h"

Compiler::Compiler(const std::string& _fn, const std::string& _text)
    : fn(_fn), text(_text), lines{} {
    std::stringstream ss(text);
    std::string item;
    while (std::getline(ss, item, '\n'))
        lines.push_back(item);
    }

Compiled Compiler::run(){
    Lexer lexer(fn, text);

    // Lexing
    std::vector<Token> tokens = lexer.lex();
    errors = lexer.getErrors();
    if (tokens.empty()){
        std::cout << errors << std::endl;
        hasIssuedError = true;
        return std::make_unique<ErrorNode>();
    }
    
    #ifdef DEBUG
        std::cout << "DEBUG Lexer : ";
        for (uint32_t i = 0; i < tokens.size(); i++)
            std::cout << tokens[i] << " ";
        std::cout << std::endl;
        
    #endif
    // Parsing
    Parser parser(tokens);

    Compiled ret = parser.parse();
    hasIssuedError |= parser.hasIssuedError;


    return ret;
}
