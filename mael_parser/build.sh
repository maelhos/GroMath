#!/bin/bash


bison -d -o parser.cpp parser.y -Wcounterexamples
lex -o tokens.cpp tokens.l
clang++ -fuse-ld=lld -g `llvm-config --cxxflags --ldflags --system-libs --libs core` -o GroMath parser.cpp tokens.cpp main.cpp