%{
#include <string>
#include "node.h"
#include "parser.hpp"

#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)

#define TOKEN(t) (yylval.token = t)
//extern "C" int yywrap() {return 0; }
%}

%option noyywrap

%%

[ \t\n]                 ;
"//".*                  ;

"if"                    return TOKEN(TIF);
"else"                  return TOKEN(TELSE);
"fn"                    return TOKEN(TFN);
"while"                 return TOKEN(TWHILE);
"for"                   return TOKEN(TFOR);
"in"                    return TOKEN(TIN);
"ret"                   return TOKEN(TRET);
"break"                 return TOKEN(TBREAK);
"continue"              return TOKEN(TCONTINUE);
"range"                 return TOKEN(TRANGE);

"true"                  return TOKEN(TTRUE);
"false"                 return TOKEN(TFALSE);

"->"                    return TOKEN(TRARROW);

[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+                  SAVE_TOKEN; return TINTEGER;
\"(\\.|[^"\\])*\"       SAVE_TOKEN; return TCSTSTRING;

"="                     return TOKEN(TEQUAL);

"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
"<"                     return TOKEN(TCLT);
"<="                    return TOKEN(TCLE);
">"                     return TOKEN(TCGT);
">="                    return TOKEN(TCGE);

"("                     return TOKEN(TLPAREN);
")"                     return TOKEN(TRPAREN);
"{"                     return TOKEN(TLBRACE);
"}"                     return TOKEN(TRBRACE);
"["                     return TOKEN(TLBRACK);
"]"                     return TOKEN(TRBRACK);
"[["                    return TOKEN(TLLBRACK);
"]]"                    return TOKEN(TRRBRACK);

"."                     return TOKEN(TDOT);
":"                     return TOKEN(TCOLON);
";"                     return TOKEN(TSCOLON);
","                     return TOKEN(TCOMMA);

"+"                     return TOKEN(TPLUS);
"-"                     return TOKEN(TMINUS);
"*"                     return TOKEN(TMUL);
"/"                     return TOKEN(TDIV);
"%"                     return TOKEN(TMOD);
"^"                     return TOKEN(TPOW);

.                       printf("Unknown tokenn !"); yyterminate();

%%