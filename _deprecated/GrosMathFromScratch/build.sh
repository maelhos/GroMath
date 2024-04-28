
~/Desktop/Big_Projects/syntax/bin/syntax -g src/parser/GroMathGrammar.yacc -m LALR1 -o src/parser/GroMathParser.h

clang++ -fuse-ld=lld -I src/ -o GroMath -g `llvm-config --cxxflags --ldflags --system-libs --libs core | sed "s/\-fno\-exceptions//"` src/GrosMathLLVM.cpp

./GroMath

lli ./out.ll
