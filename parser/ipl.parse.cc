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
#line 1 "/Users/singhotto/Documents/IPL/parser/ipl.yy"

#include "ipl.hh"
#include "ipl.parse.hh"
#include <iostream>
#include <string>
#include <memory>

// Declare external lexer functions
extern int yylex();
extern int yyparse();
extern int yyerror(const char* s);
extern int yylineno;

Interpreter& eval = Interpreter::getInstance();

#line 87 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"

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

#include "ipl.parse.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTEGER = 3,                    /* INTEGER  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_VAR = 7,                        /* VAR  */
  YYSYMBOL_PRINT = 8,                      /* PRINT  */
  YYSYMBOL_FUNC = 9,                       /* FUNC  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_WHILE = 11,                     /* WHILE  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_ADD = 17,                       /* ADD  */
  YYSYMBOL_SUB = 18,                       /* SUB  */
  YYSYMBOL_MUL = 19,                       /* MUL  */
  YYSYMBOL_DIV = 20,                       /* DIV  */
  YYSYMBOL_MOD = 21,                       /* MOD  */
  YYSYMBOL_ASSIGN = 22,                    /* ASSIGN  */
  YYSYMBOL_INCREASE = 23,                  /* INCREASE  */
  YYSYMBOL_DECREASE = 24,                  /* DECREASE  */
  YYSYMBOL_ADDASSIGN = 25,                 /* ADDASSIGN  */
  YYSYMBOL_SUBASSIGN = 26,                 /* SUBASSIGN  */
  YYSYMBOL_MULASSIGN = 27,                 /* MULASSIGN  */
  YYSYMBOL_DIVASSIGN = 28,                 /* DIVASSIGN  */
  YYSYMBOL_EQUAL = 29,                     /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 30,                  /* NOTEQUAL  */
  YYSYMBOL_LESS = 31,                      /* LESS  */
  YYSYMBOL_GREATER = 32,                   /* GREATER  */
  YYSYMBOL_LESSEQUAL = 33,                 /* LESSEQUAL  */
  YYSYMBOL_GREATEREQUAL = 34,              /* GREATEREQUAL  */
  YYSYMBOL_AND = 35,                       /* AND  */
  YYSYMBOL_OR = 36,                        /* OR  */
  YYSYMBOL_LPAREN = 37,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 38,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 39,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 40,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 41,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 42,                     /* COMMA  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_program = 44,                   /* program  */
  YYSYMBOL_body = 45,                      /* body  */
  YYSYMBOL_stmt_no_semicolon = 46,         /* stmt_no_semicolon  */
  YYSYMBOL_stmt_semicolon = 47,            /* stmt_semicolon  */
  YYSYMBOL_func_decl = 48,                 /* func_decl  */
  YYSYMBOL_func_call = 49,                 /* func_call  */
  YYSYMBOL_func_args = 50,                 /* func_args  */
  YYSYMBOL_var_decl = 51,                  /* var_decl  */
  YYSYMBOL_var_assign = 52,                /* var_assign  */
  YYSYMBOL_IDENTIFIER = 53,                /* IDENTIFIER  */
  YYSYMBOL_expr_list = 54,                 /* expr_list  */
  YYSYMBOL_expr = 55                       /* expr  */
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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  123

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    64,    72,    73,    74,    75,    76,    80,
      81,    85,    90,    94,   101,   101,   101,   102,   106,   112,
     119,   120,   127,   128,   129,   134,   137,   140,   146,   149,
     152,   155,   158,   161,   164,   167,   173,   177,   178,   179,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199
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
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER", "FLOAT",
  "ID", "STRING", "VAR", "PRINT", "FUNC", "FOR", "WHILE", "IF", "ELSE",
  "RETURN", "TRUE", "FALSE", "ADD", "SUB", "MUL", "DIV", "MOD", "ASSIGN",
  "INCREASE", "DECREASE", "ADDASSIGN", "SUBASSIGN", "MULASSIGN",
  "DIVASSIGN", "EQUAL", "NOTEQUAL", "LESS", "GREATER", "LESSEQUAL",
  "GREATEREQUAL", "AND", "OR", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "SEMICOLON", "COMMA", "$accept", "program", "body", "stmt_no_semicolon",
  "stmt_semicolon", "func_decl", "func_call", "func_args", "var_decl",
  "var_assign", "IDENTIFIER", "expr_list", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-34)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -34,    -4,   -25,    -4,     9,    13,    15,     2,    51,
      76,   -34,   -34,   -34,    25,    27,    28,   338,    58,     2,
      45,    24,     2,     2,   -34,   -34,   -34,     2,   -34,   164,
     -34,   -34,   -34,   -34,   -34,   -34,     2,   -34,   -34,     2,
       2,     2,     2,     2,     2,   -12,   280,    -4,     2,   214,
     236,   258,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   -34,   -34,    62,   280,   280,
     280,   280,   280,    29,   -34,   280,    56,     2,    70,   -34,
     189,    61,    68,   -34,    14,    14,   -34,   -34,   -34,   307,
     307,   307,   307,   307,   307,   325,   300,   -34,   -34,   280,
      81,    -4,    -4,   362,   362,   362,   -34,    85,   355,     8,
      84,   132,    90,   -34,   117,   -34,   362,    92,   140,   362,
     -34,   148,   -34
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,    36,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     7,     5,     9,     0,     0,     0,     0,    25,    37,
       0,    20,     0,     0,    54,    55,    56,     0,    57,     0,
       1,     8,     6,    16,    14,    15,    20,    30,    31,     0,
       0,     0,     0,    37,    20,     0,    38,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    29,    57,    28,    32,
      33,    34,    35,     0,    27,    26,     0,     0,     0,    23,
       0,     0,     0,    45,    40,    41,    42,    43,    44,    46,
      47,    48,    49,    50,    51,    52,    53,    21,    17,    39,
       0,     0,     0,     4,     4,     4,    24,     0,     0,    20,
      20,    20,     0,    13,    10,    19,     4,     0,    20,     4,
      12,    20,    11
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -34,   -34,    60,    17,     4,   -34,   -33,   -34,   -34,    30,
       0,    91,     1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    14,    78,    15,    16,
      28,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      17,     1,    18,    66,    20,    24,    25,     1,    26,    29,
      17,    74,    19,     1,    32,     2,     3,     4,     5,     6,
       7,    17,     8,    49,    50,    48,    76,    31,    51,     1,
      77,     2,     3,    54,    55,    56,    67,    68,     8,    27,
      69,    70,    71,    72,    67,    75,    21,    79,   113,    80,
      22,    30,    23,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    33,    97,    34,    35,
       1,    77,     2,     3,     4,     5,     6,     7,    99,     8,
      44,     1,    47,     2,     3,     4,     5,     6,     7,     1,
       8,     2,     3,     4,     5,     6,     7,    98,     8,    43,
     103,   106,   108,    17,    17,    17,    -4,   104,   100,    17,
      17,    17,   101,    32,    32,    32,    17,   -20,    17,    17,
     105,    17,    32,   112,   114,    32,    31,    31,    31,   116,
     117,   119,   107,     0,    73,    31,     0,     1,    31,     2,
       3,     4,     5,     6,     7,     1,     8,     2,     3,     4,
       5,     6,     7,     1,     8,     2,     3,     4,     5,     6,
       7,     0,     8,   109,   110,   111,     0,     0,     0,     0,
       0,     0,   115,     0,     0,     0,   118,     0,     0,   121,
     120,    52,    53,    54,    55,    56,     0,     0,   122,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,    65,    52,    53,    54,    55,
      56,     0,     0,     0,     0,     0,     0,     0,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,     0,     0,
     102,    52,    53,    54,    55,    56,     0,     0,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,     0,    81,    52,    53,    54,    55,    56,     0,     0,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    82,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,     0,    83,    52,    53,    54,
      55,    56,     0,     0,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    52,    53,    54,
      55,    56,     0,     0,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   -21,   -21,   -21,   -21,
     -21,   -21,    52,    53,    54,    55,    56,     0,     0,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    62,
      36,    37,    38,    39,    40,    41,    42,     1,     0,     2,
       3,     4,     5,     6,     7,    43,     8,    36,    37,    38,
      39,    40,    41,    42
};

static const yytype_int8 yycheck[] =
{
       0,     5,     2,    36,     4,     3,     4,     5,     6,     8,
      10,    44,    37,     5,    10,     7,     8,     9,    10,    11,
      12,    21,    14,    22,    23,    21,    38,    10,    27,     5,
      42,     7,     8,    19,    20,    21,    36,    36,    14,    37,
      39,    40,    41,    42,    44,    44,    37,    47,    40,    48,
      37,     0,    37,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    41,    38,    41,    41,
       5,    42,     7,     8,     9,    10,    11,    12,    77,    14,
      22,     5,    37,     7,     8,     9,    10,    11,    12,     5,
      14,     7,     8,     9,    10,    11,    12,    41,    14,    37,
      39,   101,   102,   103,   104,   105,    41,    39,    38,   109,
     110,   111,    42,   109,   110,   111,   116,    41,   118,   119,
      39,   121,   118,    38,    40,   121,   109,   110,   111,    39,
      13,    39,   102,    -1,    43,   118,    -1,     5,   121,     7,
       8,     9,    10,    11,    12,     5,    14,     7,     8,     9,
      10,    11,    12,     5,    14,     7,     8,     9,    10,    11,
      12,    -1,    14,   103,   104,   105,    -1,    -1,    -1,    -1,
      -1,    -1,    40,    -1,    -1,    -1,   116,    -1,    -1,   119,
      40,    17,    18,    19,    20,    21,    -1,    -1,    40,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    41,    17,    18,    19,    20,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      41,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    17,    18,    19,    20,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    17,    18,    19,
      20,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    17,    18,    19,
      20,    21,    -1,    -1,    17,    18,    19,    20,    21,    29,
      30,    31,    32,    33,    34,    35,    29,    30,    31,    32,
      33,    34,    17,    18,    19,    20,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      22,    23,    24,    25,    26,    27,    28,     5,    -1,     7,
       8,     9,    10,    11,    12,    37,    14,    22,    23,    24,
      25,    26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,     8,     9,    10,    11,    12,    14,    44,
      45,    46,    47,    48,    49,    51,    52,    53,    53,    37,
      53,    37,    37,    37,     3,     4,     6,    37,    53,    55,
       0,    46,    47,    41,    41,    41,    22,    23,    24,    25,
      26,    27,    28,    37,    22,    54,    55,    37,    47,    55,
      55,    55,    17,    18,    19,    20,    21,    29,    30,    31,
      32,    33,    34,    35,    36,    41,    49,    53,    55,    55,
      55,    55,    55,    54,    49,    55,    38,    42,    50,    53,
      55,    38,    38,    38,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    38,    41,    55,
      38,    42,    41,    39,    39,    39,    53,    52,    53,    45,
      45,    45,    38,    40,    40,    40,    39,    13,    45,    39,
      40,    45,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    44,    44,    45,    45,    45,    45,    45,    46,
      46,    46,    46,    46,    47,    47,    47,    47,    47,    48,
      49,    49,    50,    50,    50,    51,    51,    51,    52,    52,
      52,    52,    52,    52,    52,    52,    53,    54,    54,    54,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     0,     1,     2,     1,     2,     1,
       7,    11,    10,     7,     2,     2,     2,     5,     3,     8,
       0,     4,     0,     1,     3,     2,     4,     4,     3,     3,
       2,     2,     3,     3,     3,     3,     1,     0,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1
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
  case 3: /* program: body  */
#line 64 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
           { 
        Block* b = new Block(*(yyvsp[0].sBody));
        eval.visit(b); 
        delete b;
    }
#line 1259 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 4: /* body: %empty  */
#line 72 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
               { (yyval.sBody) = new StmtsVec(); }
#line 1265 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 5: /* body: stmt_semicolon  */
#line 73 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                     { (yyval.sBody) = new StmtsVec(); (yyval.sBody)->push_back((yyvsp[0].stmt)); }
#line 1271 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 6: /* body: body stmt_semicolon  */
#line 74 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                          { (yyvsp[-1].sBody)->push_back((yyvsp[0].stmt)); }
#line 1277 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 7: /* body: stmt_no_semicolon  */
#line 75 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                        { (yyval.sBody) = new StmtsVec(); (yyval.sBody)->push_back((yyvsp[0].stmt)); }
#line 1283 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 8: /* body: body stmt_no_semicolon  */
#line 76 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                             { (yyvsp[-1].sBody)->push_back((yyvsp[0].stmt)); }
#line 1289 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 10: /* stmt_no_semicolon: IF LPAREN expr RPAREN LBRACE body RBRACE  */
#line 81 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                               {
        (yyval.stmt) = IPLFactory::createIfcond(U(Expr, (yyvsp[-4].expr)), *(yyvsp[-1].sBody));
        delete (yyvsp[-1].sBody);
    }
#line 1298 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 11: /* stmt_no_semicolon: IF LPAREN expr RPAREN LBRACE body RBRACE ELSE LBRACE body RBRACE  */
#line 85 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                                                       {
        (yyval.stmt) = IPLFactory::createIfelse(U(Expr, (yyvsp[-8].expr)), *(yyvsp[-5].sBody), *(yyvsp[-1].sBody));
        delete (yyvsp[-5].sBody);
        delete (yyvsp[-1].sBody);
    }
#line 1308 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 12: /* stmt_no_semicolon: FOR LPAREN stmt_semicolon expr SEMICOLON var_assign RPAREN LBRACE body RBRACE  */
#line 90 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                                                                    {
        (yyval.stmt) = IPLFactory::createForLoop(U(Statement, (yyvsp[-7].stmt)), U(Expr, (yyvsp[-6].expr)), U(Statement, (yyvsp[-4].stmt)), *(yyvsp[-1].sBody));
        delete (yyvsp[-1].sBody);
    }
#line 1317 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 13: /* stmt_no_semicolon: WHILE LPAREN expr RPAREN LBRACE body RBRACE  */
#line 94 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                                  {
        (yyval.stmt) = IPLFactory::createWhile(U(Expr, (yyvsp[-4].expr)), *(yyvsp[-1].sBody));
        delete (yyvsp[-1].sBody);
    }
#line 1326 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 17: /* stmt_semicolon: PRINT LPAREN expr_list RPAREN SEMICOLON  */
#line 102 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                              {
        (yyval.stmt) = IPLFactory::createPrintExpr(*(yyvsp[-2].sExprList));
        delete (yyvsp[-2].sExprList);
    }
#line 1335 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 18: /* stmt_semicolon: RETURN expr SEMICOLON  */
#line 106 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                            {
        (yyval.stmt) = IPLFactory::createReturnStmt(U(Expr, (yyvsp[-1].expr)));
    }
#line 1343 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 19: /* func_decl: FUNC IDENTIFIER LPAREN func_args RPAREN LBRACE body RBRACE  */
#line 112 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                                               {
        (yyval.stmt) = IPLFactory::createDefFunc(U(Id, (yyvsp[-6].IDENTIFIER)), *(yyvsp[-4].sIdList), *(yyvsp[-1].sBody));
        delete (yyvsp[-4].sIdList);
        delete (yyvsp[-1].sBody);
    }
#line 1353 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 21: /* func_call: IDENTIFIER LPAREN expr_list RPAREN  */
#line 120 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                         {
        (yyval.expr) = IPLFactory::createCallFunc(U(Id, (yyvsp[-3].IDENTIFIER)), *(yyvsp[-1].sExprList));
        delete (yyvsp[-1].sExprList);
    }
#line 1362 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 22: /* func_args: %empty  */
#line 127 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
               { (yyval.sIdList) = new IdVec(); }
#line 1368 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 23: /* func_args: IDENTIFIER  */
#line 128 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                 { (yyval.sIdList) = new IdVec(); (yyval.sIdList)->push_back((yyvsp[0].IDENTIFIER)); }
#line 1374 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 24: /* func_args: func_args COMMA IDENTIFIER  */
#line 129 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                 { (yyval.sIdList)->push_back((yyvsp[0].IDENTIFIER)); }
#line 1380 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 25: /* var_decl: VAR IDENTIFIER  */
#line 134 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                   {
        (yyval.stmt) = IPLFactory::createDefVar(U(Id, (yyvsp[0].IDENTIFIER)));
    }
#line 1388 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 26: /* var_decl: VAR IDENTIFIER ASSIGN expr  */
#line 137 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                 {
        (yyval.stmt) = IPLFactory::createDefVar(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1396 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 27: /* var_decl: VAR IDENTIFIER ASSIGN func_call  */
#line 140 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                      {
        (yyval.stmt) = IPLFactory::createDefVar(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1404 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 28: /* var_assign: IDENTIFIER ASSIGN expr  */
#line 146 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                           {
        (yyval.stmt) = IPLFactory::createAssign(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1412 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 29: /* var_assign: IDENTIFIER ASSIGN func_call  */
#line 149 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                  {
        (yyval.stmt) = IPLFactory::createAssign(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1420 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 30: /* var_assign: IDENTIFIER INCREASE  */
#line 152 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                          {
        (yyval.stmt) = IPLFactory::createIncrease(U(Id, (yyvsp[-1].IDENTIFIER)));
    }
#line 1428 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 31: /* var_assign: IDENTIFIER DECREASE  */
#line 155 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                          {
        (yyval.stmt) = IPLFactory::createDecrease(U(Id, (yyvsp[-1].IDENTIFIER)));
    }
#line 1436 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 32: /* var_assign: IDENTIFIER ADDASSIGN expr  */
#line 158 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                {
        (yyval.stmt) = IPLFactory::createAddAssign(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1444 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 33: /* var_assign: IDENTIFIER SUBASSIGN expr  */
#line 161 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                {
        (yyval.stmt) = IPLFactory::createSubAssign(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1452 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 34: /* var_assign: IDENTIFIER MULASSIGN expr  */
#line 164 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                {
        (yyval.stmt) = IPLFactory::createMulAssign(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1460 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 35: /* var_assign: IDENTIFIER DIVASSIGN expr  */
#line 167 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                                {
        (yyval.stmt) = IPLFactory::createDivAssign(U(Id, (yyvsp[-2].IDENTIFIER)), U(Expr, (yyvsp[0].expr)));
    }
#line 1468 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 36: /* IDENTIFIER: ID  */
#line 173 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
       { (yyval.IDENTIFIER) = IPLFactory::createId(*(yyvsp[0].str)); delete (yyvsp[0].str); }
#line 1474 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 37: /* expr_list: %empty  */
#line 177 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
              { (yyval.sExprList) = new ExprVec(); }
#line 1480 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 38: /* expr_list: expr  */
#line 178 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
           { (yyval.sExprList) = new ExprVec(); (yyval.sExprList)->push_back((yyvsp[0].expr)); }
#line 1486 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 39: /* expr_list: expr_list COMMA expr  */
#line 179 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                           { (yyval.sExprList)->push_back((yyvsp[0].expr)); }
#line 1492 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 40: /* expr: expr ADD expr  */
#line 182 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                   { (yyval.expr) = IPLFactory::createAddExpr(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1498 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 41: /* expr: expr SUB expr  */
#line 183 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                    { (yyval.expr) = IPLFactory::createSubtExpr(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1504 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 42: /* expr: expr MUL expr  */
#line 184 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                    { (yyval.expr) = IPLFactory::createMulExpr(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1510 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 43: /* expr: expr DIV expr  */
#line 185 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                    { (yyval.expr) = IPLFactory::createDivExpr(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1516 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 44: /* expr: expr MOD expr  */
#line 186 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                    { (yyval.expr) = IPLFactory::createModExpr(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1522 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 45: /* expr: LPAREN expr RPAREN  */
#line 187 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                         { (yyval.expr) = (yyvsp[-1].expr); }
#line 1528 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 46: /* expr: expr EQUAL expr  */
#line 188 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                      { (yyval.expr) = IPLFactory::createEqual(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1534 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 47: /* expr: expr NOTEQUAL expr  */
#line 189 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                         { (yyval.expr) = IPLFactory::createNotEqual(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1540 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 48: /* expr: expr LESS expr  */
#line 190 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                     { (yyval.expr) = IPLFactory::createLess(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1546 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 49: /* expr: expr GREATER expr  */
#line 191 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                        { (yyval.expr) = IPLFactory::createGreater(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1552 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 50: /* expr: expr LESSEQUAL expr  */
#line 192 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                          { (yyval.expr) = IPLFactory::createLessEqual(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1558 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 51: /* expr: expr GREATEREQUAL expr  */
#line 193 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                             { (yyval.expr) = IPLFactory::createGreaterEqual(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1564 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 52: /* expr: expr AND expr  */
#line 194 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                    { (yyval.expr) = IPLFactory::createAnd(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1570 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 53: /* expr: expr OR expr  */
#line 195 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                   { (yyval.expr) = IPLFactory::createOr(U(Expr, (yyvsp[-2].expr)), U(Expr, (yyvsp[0].expr))); }
#line 1576 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 54: /* expr: INTEGER  */
#line 196 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
              { (yyval.expr) = IPLFactory::createFloat((yyvsp[0].inum)); }
#line 1582 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 55: /* expr: FLOAT  */
#line 197 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
            { (yyval.expr) = IPLFactory::createFloat((yyvsp[0].fnum)); }
#line 1588 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 56: /* expr: STRING  */
#line 198 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
             { (yyval.expr) = IPLFactory::createString(*(yyvsp[0].str)); }
#line 1594 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;

  case 57: /* expr: IDENTIFIER  */
#line 199 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
                 { (yyval.expr) = (yyvsp[0].IDENTIFIER); }
#line 1600 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"
    break;


#line 1604 "/Users/singhotto/Documents/IPL/parser/ipl.parse.cc"

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

#line 202 "/Users/singhotto/Documents/IPL/parser/ipl.yy"
