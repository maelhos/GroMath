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

#line 79 "src/parser.cpp"

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
  YYSYMBOL_TTRUE = 6,                      /* TTRUE  */
  YYSYMBOL_TFALSE = 7,                     /* TFALSE  */
  YYSYMBOL_TCEQ = 8,                       /* TCEQ  */
  YYSYMBOL_TCNE = 9,                       /* TCNE  */
  YYSYMBOL_TCLT = 10,                      /* TCLT  */
  YYSYMBOL_TCLE = 11,                      /* TCLE  */
  YYSYMBOL_TCGT = 12,                      /* TCGT  */
  YYSYMBOL_TCGE = 13,                      /* TCGE  */
  YYSYMBOL_TEQUAL = 14,                    /* TEQUAL  */
  YYSYMBOL_TLPAREN = 15,                   /* TLPAREN  */
  YYSYMBOL_TRPAREN = 16,                   /* TRPAREN  */
  YYSYMBOL_TLBRACE = 17,                   /* TLBRACE  */
  YYSYMBOL_TRBRACE = 18,                   /* TRBRACE  */
  YYSYMBOL_TLBRACK = 19,                   /* TLBRACK  */
  YYSYMBOL_TRBRACK = 20,                   /* TRBRACK  */
  YYSYMBOL_TLLBRACK = 21,                  /* TLLBRACK  */
  YYSYMBOL_TRRBRACK = 22,                  /* TRRBRACK  */
  YYSYMBOL_TCOMMA = 23,                    /* TCOMMA  */
  YYSYMBOL_TDOT = 24,                      /* TDOT  */
  YYSYMBOL_TCOLON = 25,                    /* TCOLON  */
  YYSYMBOL_TSCOLON = 26,                   /* TSCOLON  */
  YYSYMBOL_TPLUS = 27,                     /* TPLUS  */
  YYSYMBOL_TMINUS = 28,                    /* TMINUS  */
  YYSYMBOL_TMUL = 29,                      /* TMUL  */
  YYSYMBOL_TDIV = 30,                      /* TDIV  */
  YYSYMBOL_TMOD = 31,                      /* TMOD  */
  YYSYMBOL_TPOW = 32,                      /* TPOW  */
  YYSYMBOL_TIF = 33,                       /* TIF  */
  YYSYMBOL_TELSE = 34,                     /* TELSE  */
  YYSYMBOL_TFN = 35,                       /* TFN  */
  YYSYMBOL_TWHILE = 36,                    /* TWHILE  */
  YYSYMBOL_TFOR = 37,                      /* TFOR  */
  YYSYMBOL_TIN = 38,                       /* TIN  */
  YYSYMBOL_TRET = 39,                      /* TRET  */
  YYSYMBOL_TBREAK = 40,                    /* TBREAK  */
  YYSYMBOL_TCONTINUE = 41,                 /* TCONTINUE  */
  YYSYMBOL_TRANGE = 42,                    /* TRANGE  */
  YYSYMBOL_TRARROW = 43,                   /* TRARROW  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_program = 45,                   /* program  */
  YYSYMBOL_stmts = 46,                     /* stmts  */
  YYSYMBOL_stmt = 47,                      /* stmt  */
  YYSYMBOL_if_stmt = 48,                   /* if_stmt  */
  YYSYMBOL_iterator = 49,                  /* iterator  */
  YYSYMBOL_for_stmt = 50,                  /* for_stmt  */
  YYSYMBOL_while_stmt = 51,                /* while_stmt  */
  YYSYMBOL_break_stmt = 52,                /* break_stmt  */
  YYSYMBOL_continue_stmt = 53,             /* continue_stmt  */
  YYSYMBOL_ret_stmt = 54,                  /* ret_stmt  */
  YYSYMBOL_block = 55,                     /* block  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_simple_var_decl = 57,           /* simple_var_decl  */
  YYSYMBOL_var_decl = 58,                  /* var_decl  */
  YYSYMBOL_func_decl = 59,                 /* func_decl  */
  YYSYMBOL_func_decl_args = 60,            /* func_decl_args  */
  YYSYMBOL_ident = 61,                     /* ident  */
  YYSYMBOL_cst_string = 62,                /* cst_string  */
  YYSYMBOL_cst_int = 63,                   /* cst_int  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_call_args = 65,                 /* call_args  */
  YYSYMBOL_binop = 66                      /* binop  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  136

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    64,    64,    67,    68,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    82,    83,    87,    88,    92,    96,
     104,   105,   106,   107,   110,   111,   117,   118,   124,   127,
     130,   131,   134,   135,   138,   139,   142,   145,   146,   149,
     153,   154,   155,   158,   161,   164,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   179,   180,   181,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195
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
  "TINTEGER", "TCSTSTRING", "TTRUE", "TFALSE", "TCEQ", "TCNE", "TCLT",
  "TCLE", "TCGT", "TCGE", "TEQUAL", "TLPAREN", "TRPAREN", "TLBRACE",
  "TRBRACE", "TLBRACK", "TRBRACK", "TLLBRACK", "TRRBRACK", "TCOMMA",
  "TDOT", "TCOLON", "TSCOLON", "TPLUS", "TMINUS", "TMUL", "TDIV", "TMOD",
  "TPOW", "TIF", "TELSE", "TFN", "TWHILE", "TFOR", "TIN", "TRET", "TBREAK",
  "TCONTINUE", "TRANGE", "TRARROW", "$accept", "program", "stmts", "stmt",
  "if_stmt", "iterator", "for_stmt", "while_stmt", "break_stmt",
  "continue_stmt", "ret_stmt", "block", "type", "simple_var_decl",
  "var_decl", "func_decl", "func_decl_args", "ident", "cst_string",
  "cst_int", "expr", "call_args", "binop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-61)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     164,   -61,   -61,   -61,   -61,   -61,    65,    65,    15,    65,
      15,    65,   -61,   -61,    20,   164,   -61,   -61,   -61,   -61,
      -4,     1,     3,   -61,    12,   -61,    -2,   -61,   -61,   248,
     -61,    10,   273,   282,    26,   307,    22,    23,   374,   -61,
     -61,   -61,   -61,   -61,   -61,    65,    65,    15,    65,    65,
      65,    65,    65,    65,   -61,    65,    65,    65,    65,    65,
      65,   -61,   125,    15,   125,   -14,    15,   374,   374,    -8,
     -12,   -61,     5,     5,     5,     5,     5,     5,    33,    33,
      44,    44,    44,    44,   141,    45,    47,   -61,    -7,    57,
     -61,   -61,    65,    68,    59,    42,   -61,    65,    65,    15,
     -61,   180,    62,    63,    64,    15,   317,    65,   125,   374,
     374,   -61,   -61,   125,   125,    15,   -61,    65,   214,   -61,
     -61,   -61,   -61,   -61,   -61,   -13,   342,   -61,    65,   -61,
     -61,   239,   -61,    65,   349,   -61
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    43,    45,    44,    53,    54,     0,     0,     0,     0,
       0,    30,    28,    29,     0,     2,     3,     8,     9,    10,
       0,     0,     0,    38,     0,     6,    48,    50,    49,     0,
      51,    48,     0,     0,     0,     0,     0,     0,    31,     1,
       4,    12,    13,    11,     5,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,    52,     0,    40,     0,     0,     0,    46,    56,     0,
      36,    34,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,    15,    14,    41,     0,     0,
      27,    26,     0,     0,     0,    36,    47,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     0,    57,
      37,    35,    32,     0,     0,     0,    42,     0,     0,    25,
      24,    19,    17,    18,    16,     0,     0,    20,     0,    39,
      23,     0,    21,     0,     0,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -61,   -61,     6,    -5,   -61,   -61,   -61,   -61,   -61,   -61,
     -61,   -47,   -60,    83,   -49,   -61,   -61,    11,   -61,   -61,
      -6,   -61,   -61
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    14,    15,    16,    17,    94,    18,    19,    20,    21,
      22,    86,    70,    23,    24,    25,    88,    31,    27,    28,
      29,    69,    30
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      32,    33,    98,    35,    84,    38,    95,    92,    96,   104,
      40,    26,    45,    46,    87,    97,   105,    91,     1,    34,
      39,    37,    41,    47,    45,    46,    26,    42,    93,    43,
      99,    99,    55,    56,    57,    58,    59,    60,    44,    67,
      68,    63,    72,    73,    74,    75,    76,    77,    66,    78,
      79,    80,    81,    82,    83,   125,   116,    85,    71,    90,
      65,   120,    57,    58,    59,    60,   122,   124,     1,     2,
       3,     4,     5,    26,    89,    26,    60,    71,   129,   102,
       6,   103,    47,   107,   108,    99,   106,   113,   114,   115,
     101,   109,   110,    36,     0,    26,    40,     0,     0,     0,
       0,   118,     0,   119,     0,     0,     0,     0,   121,   123,
     111,   126,    26,     0,     0,     0,    89,     0,     0,    26,
       0,     0,   131,     0,    26,    26,    71,   134,     1,     2,
       3,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       6,     0,    84,     0,     1,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     0,     0,     6,     0,     7,   100,
       8,     9,    10,     0,    11,    12,    13,     1,     2,     3,
       4,     5,     0,     0,     7,     0,     8,     9,    10,     6,
      11,    12,    13,     1,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,     0,     6,     0,     7,   112,     8,
       9,    10,     0,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     8,     9,    10,     0,    11,
      12,    13,    48,    49,    50,    51,    52,    53,     0,     0,
     127,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,    55,    56,    57,    58,    59,    60,    48,    49,    50,
      51,    52,    53,     0,     0,   132,    48,    49,    50,    51,
      52,    53,   133,     0,     0,     0,    55,    56,    57,    58,
      59,    60,     0,     0,    54,    55,    56,    57,    58,    59,
      60,    48,    49,    50,    51,    52,    53,     0,     0,    61,
      48,    49,    50,    51,    52,    53,     0,     0,     0,     0,
      55,    56,    57,    58,    59,    60,     0,    62,     0,    55,
      56,    57,    58,    59,    60,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,    48,    49,    50,    51,    52,
      53,     0,    64,     0,    55,    56,    57,    58,    59,    60,
     117,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      48,    49,    50,    51,    52,    53,     0,    48,    49,    50,
      51,    52,    53,     0,   130,   135,     0,     0,     0,    55,
      56,    57,    58,    59,    60,     0,    55,    56,    57,    58,
      59,    60,    48,    49,    50,    51,    52,    53,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    57,    58,    59,    60
};

static const yytype_int16 yycheck[] =
{
       6,     7,    14,     9,    17,    11,    66,    21,    16,    16,
      15,     0,    14,    15,    63,    23,    23,    64,     3,     8,
       0,    10,    26,    25,    14,    15,    15,    26,    42,    26,
      43,    43,    27,    28,    29,    30,    31,    32,    26,    45,
      46,    15,    48,    49,    50,    51,    52,    53,    25,    55,
      56,    57,    58,    59,    60,   115,   105,    62,    47,    64,
      38,   108,    29,    30,    31,    32,   113,   114,     3,     4,
       5,     6,     7,    62,    63,    64,    32,    66,   125,    34,
      15,    34,    25,    15,    25,    43,    92,    25,    25,    25,
      84,    97,    98,    10,    -1,    84,   101,    -1,    -1,    -1,
      -1,   107,    -1,   108,    -1,    -1,    -1,    -1,   113,   114,
      99,   117,   101,    -1,    -1,    -1,   105,    -1,    -1,   108,
      -1,    -1,   128,    -1,   113,   114,   115,   133,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    -1,    17,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    -1,    33,    18,
      35,    36,    37,    -1,    39,    40,    41,     3,     4,     5,
       6,     7,    -1,    -1,    33,    -1,    35,    36,    37,    15,
      39,    40,    41,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    15,    -1,    33,    18,    35,
      36,    37,    -1,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    35,    36,    37,    -1,    39,
      40,    41,     8,     9,    10,    11,    12,    13,    -1,    -1,
      16,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,     8,     9,    10,
      11,    12,    13,    -1,    -1,    16,     8,     9,    10,    11,
      12,    13,    23,    -1,    -1,    -1,    27,    28,    29,    30,
      31,    32,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    -1,    25,    -1,    27,
      28,    29,    30,    31,    32,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    -1,     8,     9,    10,    11,    12,
      13,    -1,    25,    -1,    27,    28,    29,    30,    31,    32,
      23,    -1,    -1,    -1,    27,    28,    29,    30,    31,    32,
       8,     9,    10,    11,    12,    13,    -1,     8,     9,    10,
      11,    12,    13,    -1,    22,    16,    -1,    -1,    -1,    27,
      28,    29,    30,    31,    32,    -1,    27,    28,    29,    30,
      31,    32,     8,     9,    10,    11,    12,    13,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    15,    33,    35,    36,
      37,    39,    40,    41,    45,    46,    47,    48,    50,    51,
      52,    53,    54,    57,    58,    59,    61,    62,    63,    64,
      66,    61,    64,    64,    61,    64,    57,    61,    64,     0,
      47,    26,    26,    26,    26,    14,    15,    25,     8,     9,
      10,    11,    12,    13,    26,    27,    28,    29,    30,    31,
      32,    16,    25,    15,    25,    38,    25,    64,    64,    65,
      56,    61,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    17,    47,    55,    58,    60,    61,
      47,    55,    21,    42,    49,    56,    16,    23,    14,    43,
      18,    46,    34,    34,    16,    23,    64,    15,    25,    64,
      64,    61,    18,    25,    25,    25,    58,    23,    64,    47,
      55,    47,    55,    47,    55,    56,    64,    16,    23,    55,
      22,    64,    16,    23,    64,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    46,    46,    47,    47,    47,    47,    47,
      47,    47,    47,    47,    48,    48,    48,    48,    48,    48,
      49,    49,    49,    49,    50,    50,    51,    51,    52,    53,
      54,    54,    55,    55,    56,    56,    57,    58,    58,    59,
      60,    60,    60,    61,    62,    63,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     1,     2,     1,     1,
       1,     2,     2,     2,     4,     4,     7,     7,     7,     7,
       4,     6,     8,     5,     6,     6,     4,     4,     1,     1,
       1,     2,     3,     2,     1,     3,     3,     5,     1,     8,
       0,     1,     3,     1,     1,     1,     3,     4,     1,     1,
       1,     1,     3,     1,     1,     0,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3
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
#line 64 "parser.yacc"
                { programBlock = (yyvsp[0].block); }
#line 1272 "src/parser.cpp"
    break;

  case 3: /* stmts: stmt  */
#line 67 "parser.yacc"
             { (yyval.block) = new NBlock(); (yyval.block)->statements.push_back((yyvsp[0].stmt)); }
#line 1278 "src/parser.cpp"
    break;

  case 4: /* stmts: stmts stmt  */
#line 68 "parser.yacc"
                   { (yyvsp[-1].block)->statements.push_back((yyvsp[0].stmt)); }
#line 1284 "src/parser.cpp"
    break;

  case 5: /* stmt: var_decl TSCOLON  */
#line 71 "parser.yacc"
                        { (yyval.stmt) = (NStatement*)(yyvsp[-1].var_decl); }
#line 1290 "src/parser.cpp"
    break;

  case 7: /* stmt: expr TSCOLON  */
#line 73 "parser.yacc"
                    { (yyval.stmt) = new NExpressionStatement(*(yyvsp[-1].expr)); }
#line 1296 "src/parser.cpp"
    break;

  case 14: /* if_stmt: TIF expr TCOLON block  */
#line 82 "parser.yacc"
                                { (yyval.stmt) = new NIfStatement((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1302 "src/parser.cpp"
    break;

  case 15: /* if_stmt: TIF expr TCOLON stmt  */
#line 84 "parser.yacc"
            { auto tbl = new NBlock();
                   tbl->statements.push_back((yyvsp[0].stmt));
                   (yyval.stmt) = new NIfStatement((yyvsp[-2].expr), tbl); }
#line 1310 "src/parser.cpp"
    break;

  case 16: /* if_stmt: TIF expr TCOLON block TELSE TCOLON block  */
#line 87 "parser.yacc"
                                                   { (yyval.stmt) = new NIfStatement((yyvsp[-5].expr), (yyvsp[-3].block), (yyvsp[0].block)); }
#line 1316 "src/parser.cpp"
    break;

  case 17: /* if_stmt: TIF expr TCOLON stmt TELSE TCOLON block  */
#line 89 "parser.yacc"
            { auto tbl = new NBlock();
                   tbl->statements.push_back((yyvsp[-3].stmt));
                   (yyval.stmt) = new NIfStatement((yyvsp[-5].expr), tbl, (yyvsp[0].block)); }
#line 1324 "src/parser.cpp"
    break;

  case 18: /* if_stmt: TIF expr TCOLON block TELSE TCOLON stmt  */
#line 93 "parser.yacc"
            { auto tbl = new NBlock();
                   tbl->statements.push_back((yyvsp[0].stmt));
                   (yyval.stmt) = new NIfStatement((yyvsp[-5].expr), (yyvsp[-3].block), tbl); }
#line 1332 "src/parser.cpp"
    break;

  case 19: /* if_stmt: TIF expr TCOLON stmt TELSE TCOLON stmt  */
#line 97 "parser.yacc"
            { auto tbl1 = new NBlock();
                   tbl1->statements.push_back((yyvsp[-3].stmt));
                   auto tbl2 = new NBlock();
                   tbl2->statements.push_back((yyvsp[0].stmt));
                   (yyval.stmt) = new NIfStatement((yyvsp[-5].expr), tbl1, tbl2); }
#line 1342 "src/parser.cpp"
    break;

  case 20: /* iterator: TRANGE TLPAREN expr TRPAREN  */
#line 104 "parser.yacc"
                                       { (yyval.iter) = new NRangeIterator(0, (yyvsp[-1].expr));}
#line 1348 "src/parser.cpp"
    break;

  case 21: /* iterator: TRANGE TLPAREN expr TCOMMA expr TRPAREN  */
#line 105 "parser.yacc"
                                                   { (yyval.iter) = new NRangeIterator((yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1354 "src/parser.cpp"
    break;

  case 22: /* iterator: TRANGE TLPAREN expr TCOMMA expr TCOMMA expr TRPAREN  */
#line 106 "parser.yacc"
                                                               { (yyval.iter) = new NRangeIterator((yyvsp[-5].expr), (yyvsp[-3].expr), (yyvsp[-1].expr));}
#line 1360 "src/parser.cpp"
    break;

  case 23: /* iterator: TLLBRACK expr TCOMMA expr TRRBRACK  */
#line 107 "parser.yacc"
                                              { (yyval.iter) = new NRangeIterator((yyvsp[-3].expr), (yyvsp[-1].expr), nullptr, true);}
#line 1366 "src/parser.cpp"
    break;

  case 24: /* for_stmt: TFOR simple_var_decl TIN iterator TCOLON block  */
#line 110 "parser.yacc"
                                                          { (yyval.stmt) = new NForStatement((yyvsp[-4].var_decl), (yyvsp[-2].iter), (yyvsp[0].block)); }
#line 1372 "src/parser.cpp"
    break;

  case 25: /* for_stmt: TFOR simple_var_decl TIN iterator TCOLON stmt  */
#line 112 "parser.yacc"
                 { auto tbl = new NBlock();
                   tbl->statements.push_back((yyvsp[0].stmt));
                   (yyval.stmt) = new NForStatement((yyvsp[-4].var_decl), (yyvsp[-2].iter), tbl); }
#line 1380 "src/parser.cpp"
    break;

  case 26: /* while_stmt: TWHILE expr TCOLON block  */
#line 117 "parser.yacc"
                                      { (yyval.stmt) = new NWhileStatement((yyvsp[-2].expr), (yyvsp[0].block)); }
#line 1386 "src/parser.cpp"
    break;

  case 27: /* while_stmt: TWHILE expr TCOLON stmt  */
#line 119 "parser.yacc"
                { auto tbl = new NBlock();
                  tbl->statements.push_back((yyvsp[0].stmt));
                  (yyval.stmt) = new NWhileStatement((yyvsp[-2].expr), tbl); }
#line 1394 "src/parser.cpp"
    break;

  case 28: /* break_stmt: TBREAK  */
#line 124 "parser.yacc"
                    {(yyval.stmt) = new NBreakStatement();}
#line 1400 "src/parser.cpp"
    break;

  case 29: /* continue_stmt: TCONTINUE  */
#line 127 "parser.yacc"
                          {(yyval.stmt) = new NContinueStatement();}
#line 1406 "src/parser.cpp"
    break;

  case 30: /* ret_stmt: TRET  */
#line 130 "parser.yacc"
                {(yyval.stmt) = new NReturnStatement();}
#line 1412 "src/parser.cpp"
    break;

  case 31: /* ret_stmt: TRET expr  */
#line 131 "parser.yacc"
                     {(yyval.stmt) = new NReturnStatement((yyvsp[0].expr));}
#line 1418 "src/parser.cpp"
    break;

  case 32: /* block: TLBRACE stmts TRBRACE  */
#line 134 "parser.yacc"
                              { (yyval.block) = (yyvsp[-1].block); }
#line 1424 "src/parser.cpp"
    break;

  case 33: /* block: TLBRACE TRBRACE  */
#line 135 "parser.yacc"
                        { (yyval.block) = new NBlock(); }
#line 1430 "src/parser.cpp"
    break;

  case 34: /* type: ident  */
#line 138 "parser.yacc"
             { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].ident)); }
#line 1436 "src/parser.cpp"
    break;

  case 35: /* type: type TRARROW ident  */
#line 139 "parser.yacc"
                          { (yyval.exprvec)->push_back((yyvsp[0].ident)); }
#line 1442 "src/parser.cpp"
    break;

  case 36: /* simple_var_decl: ident TCOLON type  */
#line 142 "parser.yacc"
                                    { (yyval.var_decl) = new NVariableDeclaration(*(yyvsp[0].exprvec), *(yyvsp[-2].ident)); }
#line 1448 "src/parser.cpp"
    break;

  case 37: /* var_decl: ident TCOLON type TEQUAL expr  */
#line 145 "parser.yacc"
                                         { (yyval.var_decl) = new NVariableDeclaration(*(yyvsp[-2].exprvec), *(yyvsp[-4].ident), (yyvsp[0].expr)); }
#line 1454 "src/parser.cpp"
    break;

  case 39: /* func_decl: TFN ident TLPAREN func_decl_args TRPAREN TCOLON type block  */
#line 150 "parser.yacc"
            { (yyval.stmt) = new NFunctionDeclaration((yyvsp[-1].exprvec), *(yyvsp[-6].ident), *(yyvsp[-4].varvec), *(yyvsp[0].block)); delete (yyvsp[-4].varvec); }
#line 1460 "src/parser.cpp"
    break;

  case 40: /* func_decl_args: %empty  */
#line 153 "parser.yacc"
                            { (yyval.varvec) = new VariableList(); }
#line 1466 "src/parser.cpp"
    break;

  case 41: /* func_decl_args: var_decl  */
#line 154 "parser.yacc"
                     { (yyval.varvec) = new VariableList(); (yyval.varvec)->push_back((yyvsp[0].var_decl)); }
#line 1472 "src/parser.cpp"
    break;

  case 42: /* func_decl_args: func_decl_args TCOMMA var_decl  */
#line 155 "parser.yacc"
                                           { (yyvsp[-2].varvec)->push_back((yyvsp[0].var_decl)); }
#line 1478 "src/parser.cpp"
    break;

  case 43: /* ident: TIDENTIFIER  */
#line 158 "parser.yacc"
                    { (yyval.ident) = new NIdentifier(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1484 "src/parser.cpp"
    break;

  case 44: /* cst_string: TCSTSTRING  */
#line 161 "parser.yacc"
                        { (yyval.expr) = new NSringConstant(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1490 "src/parser.cpp"
    break;

  case 45: /* cst_int: TINTEGER  */
#line 164 "parser.yacc"
                   { (yyval.expr) = new NIntConstant(*(yyvsp[0].string)); delete (yyvsp[0].string); }
#line 1496 "src/parser.cpp"
    break;

  case 46: /* expr: ident TEQUAL expr  */
#line 168 "parser.yacc"
                         { (yyval.expr) = new NAssignment(*(yyvsp[-2].ident), *(yyvsp[0].expr)); }
#line 1502 "src/parser.cpp"
    break;

  case 47: /* expr: ident TLPAREN call_args TRPAREN  */
#line 169 "parser.yacc"
                                       { (yyval.expr) = new NMethodCall(*(yyvsp[-3].ident), *(yyvsp[-1].exprvec)); delete (yyvsp[-1].exprvec); }
#line 1508 "src/parser.cpp"
    break;

  case 48: /* expr: ident  */
#line 170 "parser.yacc"
             { (yyval.expr) = (yyvsp[0].ident); }
#line 1514 "src/parser.cpp"
    break;

  case 52: /* expr: TLPAREN expr TRPAREN  */
#line 174 "parser.yacc"
                            { (yyval.expr) = (yyvsp[-1].expr); }
#line 1520 "src/parser.cpp"
    break;

  case 53: /* expr: TTRUE  */
#line 175 "parser.yacc"
             { (yyval.expr) = new NBool(true); }
#line 1526 "src/parser.cpp"
    break;

  case 54: /* expr: TFALSE  */
#line 176 "parser.yacc"
              { (yyval.expr) = new NBool(false); }
#line 1532 "src/parser.cpp"
    break;

  case 55: /* call_args: %empty  */
#line 179 "parser.yacc"
            { (yyval.exprvec) = new ExpressionList(); }
#line 1538 "src/parser.cpp"
    break;

  case 56: /* call_args: expr  */
#line 180 "parser.yacc"
                 { (yyval.exprvec) = new ExpressionList(); (yyval.exprvec)->push_back((yyvsp[0].expr)); }
#line 1544 "src/parser.cpp"
    break;

  case 57: /* call_args: call_args TCOMMA expr  */
#line 181 "parser.yacc"
                                   { (yyvsp[-2].exprvec)->push_back((yyvsp[0].expr)); }
#line 1550 "src/parser.cpp"
    break;

  case 58: /* binop: expr TCEQ expr  */
#line 184 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1556 "src/parser.cpp"
    break;

  case 59: /* binop: expr TCNE expr  */
#line 185 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1562 "src/parser.cpp"
    break;

  case 60: /* binop: expr TCLT expr  */
#line 186 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1568 "src/parser.cpp"
    break;

  case 61: /* binop: expr TCLE expr  */
#line 187 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1574 "src/parser.cpp"
    break;

  case 62: /* binop: expr TCGT expr  */
#line 188 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1580 "src/parser.cpp"
    break;

  case 63: /* binop: expr TCGE expr  */
#line 189 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1586 "src/parser.cpp"
    break;

  case 64: /* binop: expr TPLUS expr  */
#line 190 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1592 "src/parser.cpp"
    break;

  case 65: /* binop: expr TMINUS expr  */
#line 191 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1598 "src/parser.cpp"
    break;

  case 66: /* binop: expr TMUL expr  */
#line 192 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1604 "src/parser.cpp"
    break;

  case 67: /* binop: expr TDIV expr  */
#line 193 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1610 "src/parser.cpp"
    break;

  case 68: /* binop: expr TMOD expr  */
#line 194 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1616 "src/parser.cpp"
    break;

  case 69: /* binop: expr TPOW expr  */
#line 195 "parser.yacc"
                         { (yyval.expr) = new NBinaryOperator(*(yyvsp[-2].expr), (yyvsp[-1].token), *(yyvsp[0].expr)); }
#line 1622 "src/parser.cpp"
    break;


#line 1626 "src/parser.cpp"

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

#line 198 "parser.yacc"
