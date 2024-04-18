#include <iostream>
#include "node.h"

extern NBlock* programBlock;
extern int yyparse();

#define YYDEBUG 1 // This is new

int main(int argc, char* argv[])
{   
    yyparse();

    std::cout << "Done parsing !!" << std::endl;
    std::cout << programBlock << std::endl;
    return 0;
}