#include <iostream>
#include "node.h"
#include "GMcompiler.h"

extern int yydebug;

#define YYERROR_VERBOSE 1
#define YYDEBUG 1


int main(int argc, char* argv[]){   

    yydebug = 1;
    if (argc < 2)
        exit(0);

    for (int i = 1; i < argc; i++){
        // maybe paralelisation in future ...
        GMcompiler myCompiler(argv[i]);
        myCompiler.compile();
    }

    std::cout << "Done" << std::endl;
    return 0;
}