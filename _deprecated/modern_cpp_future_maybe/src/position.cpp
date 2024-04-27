#include "position.h"

Position::Position(int32_t _idx, uint32_t _ln, int32_t _col, std::string _fn, std::string _ftxt) :
idx(_idx), ln(_ln), col(_col), fn(_fn), ftxt(_ftxt) {}

void Position::advance(char chr){
    idx++;
    col++;

    if (chr == '\n'){
        ln++;
        col = 0;
    }
}