
~/Desktop/Big_Projects/syntax/bin/syntax -g src/parser/GroMathGrammar.yacc -m LALR1 -o src/parser/GroMathParser.h

clang++ -o GroMath -g `llvm-config --cxxflags --ldflags --system-libs --libs core | sed "s/\-fno\-exceptions//"` src/GrosMathLLVM.cpp

./GroMath

lli ./out.ll
