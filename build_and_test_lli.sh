#!/bin/bash

FILES="src/codeGen.cpp src/parser.cpp src/tokens.cpp src/main.cpp"
bison -d -o src/parser.cpp parser.yacc -t -v
mv src/parser.hpp include/parser.h
mv src/parser.output debug/
lex -o src/tokens.cpp tokens.l
clang++ -fuse-ld=lld -I include/ -g `llvm-config --cxxflags --ldflags --system-libs --libs core` -DYYDEBUG -o GroMath $FILES

./GroMath test_llvm.gm
lli test_llvm.gm.ll