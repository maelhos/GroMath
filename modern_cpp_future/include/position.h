#pragma once
#include "stdinc.h"

class Position {
public:
    int32_t idx;
    uint32_t ln;
    int32_t col;

    std::string fn;
    std::string ftxt;
public:
    Position(int32_t _idx, uint32_t _ln, int32_t _col, std::string _fn, std::string _ftxt);

    void advance(char chr);
};

