#!/bin/bash

bison -d -o parser.cpp parser.yacc -t -v
lex -o tokens.cpp tokens.l
clang++ -fuse-ld=lld -g `llvm-config --cxxflags --ldflags --system-libs --libs core` -DYYDEBUG -o GroMath parser.cpp tokens.cpp main.cpp