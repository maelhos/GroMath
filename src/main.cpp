#include <iostream>
#include "node.h"

extern int yydebug;

#define YYERROR_VERBOSE 1
#define YYDEBUG 1

int main(int argc, char* argv[]){   

    yydebug = 1;
    if (argc < 2)
        exit(0);

    FILE* f = fopen(argv[1], "r");
    if (!f){
        fprintf(stderr, "No such file or directory or can't open %s", argv[1]);
        exit(1);
    }

    std::cout << "Done parsing !!" << std::endl;
    return 0;
}