#include "lexer.h"

Lexer::Lexer(const std::string& _fn, const std::string& _text) : fn(_fn), text(_text), pos(-1, 0, -1, _fn, _text) {
    this->next_char();
}


void Lexer::next_char(){
    pos.advance(current_char);
    current_char = pos.idx < (int32_t)text.length() ? text[pos.idx] : 0;
}

void Lexer::next_n_char(uint32_t n){
    for (uint32_t i = 0; i < n; i++)
        this->next_char();
}

void Lexer::lex_number(){
    char* ret = 0;
    const char* base = text.c_str() + pos.idx;
    int a = strtol(base, &ret, 10);

    if (*ret == '.'){
        float a = strtof(base, &ret);
        tokens.push_back(Token_FLOAT(a));
        this->next_n_char((uint32_t)(ret - base));
        return;
    }

    tokens.push_back(Token_INT(a));
    this->next_n_char((uint32_t)(ret - base));
}

std::vector<Token> Lexer::lex(){
    while (current_char){
        switch (current_char){
            case ' ': case '\t':
                this->next_char();
                break;
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                this->lex_number();
                break;
            case '+':
                tokens.push_back(Token_PLUS());
                this->next_char();
                break;
            case '#':
                tokens.push_back(Token_COMM());
                this->next_char();
                break;
            case '-':
                this->next_char();
                if (current_char == '-'){
                    tokens.push_back(Token_COMM());
                    this->next_char();
                }
                else
                    tokens.push_back(Token_MINUS());
                break;
            case '*':
                tokens.push_back(Token_MUL());
                this->next_char();
                break;
            case '/':
                this->next_char();
                if (current_char == '/'){
                    tokens.push_back(Token_COMM());
                    this->next_char();
                }
                else
                    tokens.push_back(Token_DIV());
                break;
            case '(':
                tokens.push_back(Token_LPAR());
                this->next_char();
                break;
            case ')':
                tokens.push_back(Token_RPAR());
                this->next_char();
                break;
            case '\n':
                tokens.push_back(Token_EOL());
                this->next_char();
                break;
            default:
                Position pos_start(pos);
                char chr = current_char;
                this->next_char();
                std::ostringstream details;
                details << "'" << chr << "'";
                errors << "LexerError: " << IllegalCharError(pos_start, pos, details.str());
                return std::vector<Token>{};
                break;
        }
    }
    tokens.push_back(Token_EOF());
    return tokens;
}

std::string Lexer::getErrors(){
    return errors.str();
}