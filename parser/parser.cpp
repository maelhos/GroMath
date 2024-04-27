/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.yacc"

    #include "node.h"
    NBlock* programBlock; /* the top level root node of our final AST */

    extern int yylex();
    void yyerror(const char *s) { printf("ERROR: %s\n", s); }

#line 79 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TIDENTIFIER = 3,                /* TIDENTIFIER  */
  YYSYMBOL_TINTEGER = 4,                   /* TINTEGER  */
  YYSYMBOL_TCSTSTRING = 5,                 /* TCSTSTRING  */
  YYSYMBOL_TCEQ = 6,                       /* TCEQ  */
  YYSYMBOL_TCNE = 7,                       /* TCNE  */
  YYSYMBOL_TCLT = 8,                       /* TCLT  */
  YYSYMBOL_TCLE = 9,                       /* TCLE  */
  YYSYMBOL_TCGT = 10,                      /* TCGT  */
  YYSYMBOL_TCGE = 11,                      /* TCGE  */
  YYSYMBOL_TEQUAL = 12,                    /* TEQUAL  */
  YYSYMBOL_TLPAREN = 13,                   /* TLPAREN  */
  YYSYMBOL_TRPAREN = 14,                   /* TRPAREN  */
  YYSYMBOL_TLBRACE = 15,                   /* TLBRACE  */
  YYSYMBOL_TRBRACE = 16,                   /* TRBRACE  */
  YYSYMBOL_TLBRACK = 17,                   /* TLBRACK  */
  YYSYMBOL_TRBRACK = 18,                   /* TRBRACK  */
  YYSYMBOL_TLLBRACK = 19,                  /* TLLBRACK  */
  YYSYMBOL_TRRBRACK = 20,                  /* TRRBRACK  */
  YYSYMBOL_TCOMMA = 21,                    /* TCOMMA  */
  YYSYMBOL_TDOT = 22,                      /* TDOT  */
  YYSYMBOL_TCOLON = 23,                    /* TCOLON  */
  YYSYMBOL_TSCOLON = 24,                   /* TSCOLON  */
  YYSYMBOL_TPLUS = 25,                     /* TPLUS  */
  YYSYMBOL_TMINUS = 26,                    /* TMINUS  */
  YYSYMBOL_TMUL = 27,                      /* TMUL  */
  YYSYMBOL_TDIV = 28,                      /* TDIV  */
  YYSYMBOL_TMOD = 29,                      /* TMOD  */
  YYSYMBOL_TPOW = 30,                      /* TPOW  */
  YYSYMBOL_TIF = 31,                       /* TIF  */
  YYSYMBOL_TELSE = 32,                     /* TELSE  */
  YYSYMBOL_TFN = 33,                       /* TFN  */
  YYSYMBOL_TWHILE = 34,                    /* TWHILE  */
  YYSYMBOL_TFOR = 35,                      /* TFOR  */
  YYSYMBOL_TIN = 36,                       /* TIN  */
  YYSYMBOL_TRET = 37,                      /* TRET  */
  YYSYMBOL_TBREAK = 38,                    /* TBREAK  */
  YYSYMBOL_TCONTINUE = 39,                 /* TCONTINUE  */
  YYSYMBOL_TRANGE = 40,                    /* TRANGE  */
  YYSYMBOL_TRARROW = 41,                   /* TRARROW  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_stmts = 44,                     /* stmts  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_if_stmt = 46,                   /* if_stmt  */
  YYSYMBOL_iterator = 47,                  /* iterator  */
  YYSYMBOL_for_stmt = 48,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 49,                /* while_stmt  */
  YYSYMBOL_break_stmt = 50,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 51,             /* continue_stmt  */
  YYSYMBOL_ret_stmt = 52,                  /* ret_stmt  */
  YYSYMBOL_block = 53,                     /* block  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_var_decl = 55,                  /* var_decl  */
  YYSYMBOL_func_decl = 56,                 /* func_decl  */
  YYSYMBOL_func_decl_args = 57,            /* func_decl_args  */
  YYSYMBOL_ident = 58,                     /* ident  */
  YYSYMBOL_cst_string = 59,                /* cst_string  */
  YYSYMBOL_cst_int = 60,                   /* cst_int  */
  YYSYMBOL_expr = 61,                      /* expr  */
  YYSYMBOL_call_args = 62,                 /* call_args  */
  YYSYMBOL_binop = 63                      /* binop  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    61,    61,    64,    65,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    79,    80,    83,    84,    85,    86,
      89,    92,    95,    98,   101,   102,   105,   106,   107,   110,
     111,   114,   115,   118,   122,   123,   124,   127,   130,   133,
     137,   138,   139,   140,   141,   142,   143,   146,   147,   148,
     151,   151,   151,   151,   151,   151,   152,   152,   153,   153
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TIDENTIFIER",
  "TINTEGER", "TCSTSTRING", "TCEQ", "TCNE", "TCLT", "TCLE", "TCGT", "TCGE",
  "TEQUAL", "TLPAREN", "TRPAREN", "TLBRACE", "TRBRACE", "TLBRACK",
  "TRBRACK", "TLLBRACK", "TRRBRACK", "TCOMMA", "TDOT", "TCOLON", "TSCOLON",
  "TPLUS", "TMINUS", "TMUL", "TDIV", "TMOD", "TPOW", "TIF", "TELSE", "TFN",
  "TWHILE", "TFOR", "TIN", "TRET", "TBREAK", "TCONTINUE", "TRANGE",
  "TRARROW", "$accept", "program", "stmts", "stmt", "if_stmt", "iterator",
  "for_stmt", "while_stmt", "break_stmt", "continue_stmt", "ret_stmt",
  "block", "type", "var_decl", "func_decl", "func_decl_args", "ident",
  "cst_string", "cst_int", "expr", "call_args", "binop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     156,   -58,   -58,   -58,    45,    45,     3,    45,     3,    45,
     -58,   -58,    14,   156,   -58,   -58,   -58,   -58,    12,    16,
      23,    29,   -58,     0,   -58,   -58,    53,     7,   194,   203,
      41,   226,   -20,    32,   287,   -58,   -58,   -58,   -58,   -58,
     -58,    45,    45,     3,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,    45,   -58,    82,     3,    82,
      -9,   287,   287,    -3,    -8,   -58,   287,   119,   -58,    24,
     -58,    20,   -58,    45,    52,    47,   -58,    45,    45,     3,
     -58,   133,    48,    49,     3,   234,    45,    82,   287,   287,
     -58,   -58,    82,     3,   -58,    45,    18,   -58,   -58,    82,
     257,   -58,    45,   -58,   -58,   171,   -58,    45,   264,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    37,    39,    38,     0,     0,     0,     0,     0,    24,
      22,    23,     0,     2,     3,     8,     9,    10,     0,     0,
       0,     0,     6,    42,    44,    43,     0,    42,     0,     0,
       0,     0,     0,     0,    25,     1,     4,    12,    13,    11,
       5,     0,    47,     0,    50,    51,    52,    53,    54,    55,
       7,    56,    57,    58,    59,     0,    46,     0,    34,     0,
       0,    40,    48,     0,    31,    29,    45,     0,    28,    14,
      35,     0,    21,     0,     0,     0,    41,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,    49,    32,
      30,    26,     0,     0,    36,     0,     0,    20,    15,     0,
       0,    16,     0,    33,    19,     0,    17,     0,     0,    18
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,    17,     8,   -58,   -58,   -58,   -58,   -58,   -58,
     -58,   -57,   -58,    -1,   -58,   -58,     9,   -58,   -58,    -4,
     -58,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    12,    13,    68,    15,    75,    16,    17,    18,    19,
      20,    69,    64,    21,    22,    71,    27,    24,    25,    26,
      63,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      28,    29,    72,    31,    78,    34,     1,    32,    14,    23,
      73,    76,    41,    42,    35,    30,    60,    33,    77,    41,
      42,    36,    23,    43,    44,    45,    46,    47,    48,    49,
      97,    74,   101,    79,    83,    98,    37,    61,    62,   102,
      38,    84,   103,    51,    52,    53,    54,    39,     1,     2,
       3,    66,    65,    40,    58,    43,    82,    70,     4,    44,
      45,    46,    47,    48,    49,    86,    23,    33,    23,    85,
      87,    92,    93,    88,    89,    14,    23,    50,    51,    52,
      53,    54,    96,    94,    81,     1,     2,     3,    90,    36,
      23,   100,     0,    33,     0,     4,    23,    67,   105,     0,
       0,    23,    99,   108,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     5,     0,     6,     7,     8,     0,     9,
      10,    11,     1,     2,     3,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,    80,     1,     2,     3,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,    91,
       5,     0,     6,     7,     8,     0,     9,    10,    11,     1,
       2,     3,     0,     0,     5,     0,     6,     7,     8,     4,
       9,    10,    11,     0,     0,     0,     0,    44,    45,    46,
      47,    48,    49,     0,     0,   106,     0,     5,     0,     6,
       7,     8,   107,     9,    10,    11,    51,    52,    53,    54,
      44,    45,    46,    47,    48,    49,     0,     0,    56,    44,
      45,    46,    47,    48,    49,     0,     0,     0,     0,    51,
      52,    53,    54,     0,     0,     0,    57,     0,    51,    52,
      53,    54,    44,    45,    46,    47,    48,    49,     0,     0,
      44,    45,    46,    47,    48,    49,     0,     0,     0,    59,
       0,    51,    52,    53,    54,    95,     0,     0,     0,    51,
      52,    53,    54,    44,    45,    46,    47,    48,    49,     0,
      44,    45,    46,    47,    48,    49,     0,   104,   109,     0,
       0,     0,    51,    52,    53,    54,     0,     0,     0,    51,
      52,    53,    54,    44,    45,    46,    47,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,    52,    53,    54
};

static const yytype_int8 yycheck[] =
{
       4,     5,    59,     7,    12,     9,     3,     8,     0,     0,
      19,    14,    12,    13,     0,     6,    36,     8,    21,    12,
      13,    13,    13,    23,     6,     7,     8,     9,    10,    11,
      87,    40,    14,    41,    14,    92,    24,    41,    42,    21,
      24,    21,    99,    25,    26,    27,    28,    24,     3,     4,
       5,    55,    43,    24,    13,    23,    32,    58,    13,     6,
       7,     8,     9,    10,    11,    13,    57,    58,    59,    73,
      23,    23,    23,    77,    78,    67,    67,    24,    25,    26,
      27,    28,    86,    84,    67,     3,     4,     5,    79,    81,
      81,    95,    -1,    84,    -1,    13,    87,    15,   102,    -1,
      -1,    92,    93,   107,    -1,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    31,    -1,    33,    34,    35,    -1,    37,
      38,    39,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    16,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,    -1,    16,
      31,    -1,    33,    34,    35,    -1,    37,    38,    39,     3,
       4,     5,    -1,    -1,    31,    -1,    33,    34,    35,    13,
      37,    38,    39,    -1,    -1,    -1,    -1,     6,     7,     8,
       9,    10,    11,    -1,    -1,    14,    -1,    31,    -1,    33,
      34,    35,    21,    37,    38,    39,    25,    26,    27,    28,
       6,     7,     8,     9,    10,    11,    -1,    -1,    14,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    25,
      26,    27,    28,    -1,    -1,    -1,    23,    -1,    25,    26,
      27,    28,     6,     7,     8,     9,    10,    11,    -1,    -1,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    23,
      -1,    25,    26,    27,    28,    21,    -1,    -1,    -1,    25,
      26,    27,    28,     6,     7,     8,     9,    10,    11,    -1,
       6,     7,     8,     9,    10,    11,    -1,    20,    14,    -1,
      -1,    -1,    25,    26,    27,    28,    -1,    -1,    -1,    25,
      26,    27,    28,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,    13,    31,    33,    34,    35,    37,
      38,    39,    43,    44,    45,    46,    48,    49,    50,    51,
      52,    55,    56,    58,    59,    60,    61,    58,    61,    61,
      58,    61,    55,    58,    61,     0,    45,    24,    24,    24,
      24,    12,    13,    23,     6,     7,     8,     9,    10,    11,
      24,    25,    26,    27,    28,    63,    14,    23,    13,    23,
      36,    61,    61,    62,    54,    58,    61,    15,    45,    53,
      55,    57,    53,    19,    40,    47,    14,    21,    12,    41,
      16,    44,    32,    14,    21,    61,    13,    23,    61,    61,
      58,    16,    23,    23,    55,    21,    61,    53,    53,    58,
      61,    14,    21,    53,    20,    61,    14,    21,    61,    14
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    46,    46,    47,    47,    47,    47,
      48,    49,    50,    51,    52,    52,    53,    53,    53,    54,
      54,    55,    55,    56,    57,    57,    57,    58,    59,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     1,     1,
       1,     2,     2,     2,     4,     7,     4,     6,     8,     5,
       6,     4,     1,     1,     1,     2,     3,     2,     1,     1,
       3,     3,     5,     8,     0,     1,     3,     1,     1,     1,
       3,     4,     1,     1,     1,     3,     3,     0,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: stmts  */
#line 61 "parser.yacc"
                { programBlock = (yyvsp[0].block); }
#line 1238 "parser.cpp"
    break;

  case 3: /* stmts: stmt  */
#line 64 "parser.yacc"
             { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[0].stmt)); }
#line 1244 "parser.cpp"
    break;

  case 4: /* stmts: stmts stmt  */
#line 65 "parser.yacc"
                   { (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt)); }
#line 1250 "parser.cpp"
    break;

  case 5: /* stmt: var_decl TSCOLON  */
#line 68 "parser.yacc"
                        { (yyval.stmt) = (NStatement*)(yyvsp[-1].var_decl); }
#line 1256 "parser.cpp"
    break;

  case 7: /* stmt: expr TSCOLON  */
#line 70 "parser.yacc"
                    { (yyval.stmt) = new NExpressionStatement(*(yyvsp[-1].expr)); }
#line 1262 "parser.cpp"
    break;

  case 14: /* if_stmt: TIF expr TCOLON block  */
#line 79 "parser.yacc"
                                { (yyval.stmt) = new NIfStatement((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1268 "parser.cpp"
    break;

  case 15: /* if_stmt: TIF expr TCOLON block TELSE TCOLON block  */
#line 80 "parser.yacc"
                                                   { (yyval.stmt) = new NIfStatement((yyvsp[-5].expr), (yyvsp[-3].block), (yyvsp[0].block)); }
#line 1274 "parser.cpp"
    break;

  case 16: /* iterator: TRANGE TLPAREN expr TRPAREN  */
#line 83 "parser.yacc"
                                       { (yyval.iter) = new NRangeIterator((yyvsp[-1].expr));}
#line 1280 "parser.cpp"
    break;

  case 17: /* iterator: TRANGE TLPAREN expr TCOMMA expr TRPAREN  */
#line 84 "parser.yacc"
                                                   { (yyval.iter) = new NRangeIterator((yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1286 "parser.cpp"
    break;

  case 18: /* iterator: TRANGE TLPAREN expr TCOMMA expr TCOMMA expr TRPAREN  */
#line 85 "parser.yacc"
                                                               { (yyval.iter) = new NRangeIterator((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1292 "parser.cpp"
    break;

  case 19: /* iterator: TLLBRACK expr TCOMMA expr TRRBRACK  */
#line 86 "parser.yacc"
                                              { (yyval.iter) = new NRangeIterator((yyvsp[-3].expr), (yyvsp[-1].expr), nullptr, true);}
#line 1298 "parser.cpp"
    break;

  case 20: /* for_stmt: TFOR var_decl TIN iterator TCOLON block  */
#line 89 "parser.yacc"
                                                   { (yyval.stmt) = new NForStatement((yyvsp[-4].var_decl), (yyvsp[-2].iter), (yyvsp[0].block)); }
#line 1304 "parser.cpp"
    break;

  case 21: /* while_stmt: TWHILE expr TCOLON block  */
#line 92 "parser.yacc"
                                      { (yyval.stmt) = new NWhileStatement((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1310 "parser.cpp"
    break;

  case 22: /* break_stmt: TBREAK  */
#line 95 "parser.yacc"
                    {(yyval.stmt) = new NBreakStatement();}
#line 1316 "parser.cpp"
    break;

  case 23: /* continue_stmt: TCONTINUE  */
#line 98 "parser.yacc"
                          {(yyval.stmt) = new NContinueStatement();}
#line 1322 "parser.cpp"
    break;

  case 24: /* ret_stmt: TRET  */
#line 101 "parser.yacc"
                {(yyval.stmt) = new NReturnStatement();}
#line 1328 "parser.cpp"
    break;

  case 25: /* ret_stmt: TRET expr  */
#line 102 "parser.yacc"
                     {(yyval.stmt) = new NReturnStatement((yyvsp[0].expr));}
#line 1334 "parser.cpp"
    break;

  case 26: /* block: TLBRACE stmts TRBRACE  */
#line 105 "parser.yacc"
                              { (yyval.block) = (yyvsp[-1].block); }
#line 1340 "parser.cpp"
    break;

  case 27: /* block: TLBRACE TRBRACE  */
#line 106 "parser.yacc"
                        { (yyval.block) = new NBlock(); }
#line 1346 "parser.cpp"
    break;

  case 28: /* block: stmt  */
#line 107 "parser.yacc"
             { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[0].stmt));}
#line 1352 "parser.cpp"
    break;

  case 29: /* type: ident  */
#line 110 "parser.yacc"
             { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].ident)); }
#line 1358 "parser.cpp"
    break;

  case 30: /* type: type TRARROW ident  */
#line 111 "parser.yacc"
                          { (yyval.exprvec)->push_back((yyvsp[0].ident)); }
#line 1364 "parser.cpp"
    break;

  case 31: /* var_decl: ident TCOLON type  */
#line 114 "parser.yacc"
                             { (yyval.var_decl) = new NVariableDeclaration(*(yyvsp[0].exprvec), *(yyvsp[-2].ident)); }
#line 1370 "parser.cpp"
    break;

  case 32: /* var_decl: ident TCOLON type TEQUAL expr  */
#line 115 "parser.yacc"
                                         { (yyval.var_decl) = new NVariableDeclaration(*(yyvsp[-2].exprvec), *(yyvsp[-4].ident), (yyvsp[0].expr)); }
#line 1376 "parser.cpp"
    break;

  case 33: /* func_decl: TFN ident TLPAREN func_decl_args TRPAREN TCOLON ident block  */
#line 119 "parser.yacc"
            { (yyval.stmt) = new NFunctionDeclaration(*(yyvsp[-1].ident), *(yyvsp[-6].ident), *(yyvsp[-4].varvec), *(yyvsp[0].block)); delete (yyvsp[-4].varvec); }
#line 1382 "parser.cpp"
    break;

  case 34: /* func_decl_args: %empty  */
#line 122 "parser.yacc"
                            { (yyval.varvec) = new VariableList(); }
#line 1388 "parser.cpp"
    break;

  case 35: /* func_decl_args: var_decl  */
#line 123 "parser.yacc"
                     { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yyvsp[0].var_decl)); }
#line 1394 "parser.cpp"
    break;

  case 36: /* func_decl_args: func_decl_args TCOMMA var_decl  */
#line 124 "parser.yacc"
                                           { (yyvsp[-2].varvec)->push_back((yyvsp[0].var_decl)); }
#line 1400 "parser.cpp"
    break;

  case 37: /* ident: TIDENTIFIER  */
#line 127 "parser.yacc"
                    { (yyval.ident) = new NIdentifier(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1406 "parser.cpp"
    break;

  case 38: /* cst_string: TCSTSTRING  */
#line 130 "parser.yacc"
                        { (yyval.expr) = new NSringConstant(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1412 "parser.cpp"
    break;

  case 39: /* cst_int: TINTEGER  */
#line 133 "parser.yacc"
                   { (yyval.expr) = new NIntConstant(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1418 "parser.cpp"
    break;

  case 40: /* expr: ident TEQUAL expr  */
#line 137 "parser.yacc"
                         { (yyval.expr) = new NAssignment(*(yyvsp[-2].ident), *(yyvsp[0].expr)); }
#line 1424 "parser.cpp"
    break;

  case 41: /* expr: ident TLPAREN call_args TRPAREN  */
#line 138 "parser.yacc"
                                       { (yyval.expr) = new NMethodCall(*(yyvsp[-3].ident), *(yyvsp[-1].exprvec)); delete (yyvsp[-1].exprvec); }
#line 1430 "parser.cpp"
    break;

  case 42: /* expr: ident  */
#line 139 "parser.yacc"
             { (yyval.expr) = (yyvsp[0].ident); }
#line 1436 "parser.cpp"
    break;

  case 45: /* expr: expr binop expr  */
#line 142 "parser.yacc"
                       { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1442 "parser.cpp"
    break;

  case 46: /* expr: TLPAREN expr TRPAREN  */
#line 143 "parser.yacc"
                            { (yyval.expr) = (yyvsp[-1].expr); }
#line 1448 "parser.cpp"
    break;

  case 47: /* call_args: %empty  */
#line 146 "parser.yacc"
            { (yyval.exprvec) = new ExpressionList(); }
#line 1454 "parser.cpp"
    break;

  case 48: /* call_args: expr  */
#line 147 "parser.yacc"
                 { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].expr)); }
#line 1460 "parser.cpp"
    break;

  case 49: /* call_args: call_args TCOMMA expr  */
#line 148 "parser.yacc"
                                   { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1466 "parser.cpp"
    break;


#line 1470 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 156 "parser.yacc"
