#!/bin/bash

FILES="src/operator.cpp src/json.cpp src/type.cpp src/utils.cpp src/GMcompiler.cpp src/codeGen.cpp src/parser.cpp src/tokens.cpp src/main.cpp"
bison -d -o src/parser.cpp parser.yacc -t -v
mv src/parser.hpp include/parser.hpp
mv src/parser.output debug/
lex -o src/tokens.cpp tokens.l
g++ -fuse-ld=lld -I include/ -g `llvm-config --cxxflags --ldflags --system-libs --libs all` -lgmp -DYYDEBUG -o GroMath $FILES