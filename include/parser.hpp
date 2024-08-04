/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_HPP_INCLUDED
# define YY_YY_SRC_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TIDENTIFIER = 258,             /* TIDENTIFIER  */
    TINTEGER = 259,                /* TINTEGER  */
    TCSTSTRING = 260,              /* TCSTSTRING  */
    TTRUE = 261,                   /* TTRUE  */
    TFALSE = 262,                  /* TFALSE  */
    TCEQ = 263,                    /* TCEQ  */
    TCNE = 264,                    /* TCNE  */
    TCLT = 265,                    /* TCLT  */
    TCLE = 266,                    /* TCLE  */
    TCGT = 267,                    /* TCGT  */
    TCGE = 268,                    /* TCGE  */
    TEQUAL = 269,                  /* TEQUAL  */
    TLPAREN = 270,                 /* TLPAREN  */
    TRPAREN = 271,                 /* TRPAREN  */
    TLBRACE = 272,                 /* TLBRACE  */
    TRBRACE = 273,                 /* TRBRACE  */
    TLBRACK = 274,                 /* TLBRACK  */
    TRBRACK = 275,                 /* TRBRACK  */
    TLLBRACK = 276,                /* TLLBRACK  */
    TRRBRACK = 277,                /* TRRBRACK  */
    TCOMMA = 278,                  /* TCOMMA  */
    TDOT = 279,                    /* TDOT  */
    TCOLON = 280,                  /* TCOLON  */
    TSCOLON = 281,                 /* TSCOLON  */
    TPLUS = 282,                   /* TPLUS  */
    TMINUS = 283,                  /* TMINUS  */
    TMUL = 284,                    /* TMUL  */
    TDIV = 285,                    /* TDIV  */
    TMOD = 286,                    /* TMOD  */
    TPOW = 287,                    /* TPOW  */
    TIF = 288,                     /* TIF  */
    TELSE = 289,                   /* TELSE  */
    TFN = 290,                     /* TFN  */
    TWHILE = 291,                  /* TWHILE  */
    TFOR = 292,                    /* TFOR  */
    TIN = 293,                     /* TIN  */
    TRET = 294,                    /* TRET  */
    TBREAK = 295,                  /* TBREAK  */
    TCONTINUE = 296,               /* TCONTINUE  */
    TRANGE = 297,                  /* TRANGE  */
    TRARROW = 298                  /* TRARROW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "parser.yacc"

    Node* node;
    NBlock* block;
    NExpression* expr;
    NStatement* stmt;
    NIdentifier* ident;
    NVariableDeclaration* var_decl;
    NIterator* iter;
    std::vector<NVariableDeclaration*>* varvec;
    std::vector<NExpression*>* exprvec;
    std::string* string;
    int token;

#line 121 "src/parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_PARSER_HPP_INCLUDED  */
