
#~/Desktop/Big_Projects/syntax/bin/syntax -g new_parser/GroMathGrammarNew.yacc -m LALR1 -o new_parser/GroMathParserGrammarRef.h

clang++ -I new_parser -o GroMath -g `llvm-config --cxxflags --ldflags --system-libs --libs core | sed "s/\-fno\-exceptions//"` new_parser/main.cpp

./GroMath new_parser/test.gm

#lli ./out.ll
