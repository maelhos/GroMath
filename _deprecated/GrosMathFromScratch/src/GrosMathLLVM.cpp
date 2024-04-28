#include "GrosMathLLVM.h"


int main(int argc, char* argv[]) {

    std::string prgm = R"(

        (def square ((a number) (b number)) -> number 
            (* (+ a b) b)
        )

        (printf "Gromathed %d\n" (+ (square 2 3) (square 8 3)))


    )";

    GrosMathLLVM vm;

    vm.exec(prgm);
    
    return 0;
}