/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/tree.h"
#include "../src/strtab.h"

extern int yylex();
extern int yylineno;
extern int yyerror(char *msg);

/* Scope management */
char* scope = "";

#line 86 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTCONST = 4,                   /* INTCONST  */
  YYSYMBOL_CHARCONST = 5,                  /* CHARCONST  */
  YYSYMBOL_ADDOP = 6,                      /* ADDOP  */
  YYSYMBOL_SUBOP = 7,                      /* SUBOP  */
  YYSYMBOL_MULOP = 8,                      /* MULOP  */
  YYSYMBOL_DIVOP = 9,                      /* DIVOP  */
  YYSYMBOL_EQ = 10,                        /* EQ  */
  YYSYMBOL_NEQ = 11,                       /* NEQ  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_GT = 13,                        /* GT  */
  YYSYMBOL_LTE = 14,                       /* LTE  */
  YYSYMBOL_GTE = 15,                       /* GTE  */
  YYSYMBOL_LPAREN = 16,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 17,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 18,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 19,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 20,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 21,                    /* RBRACE  */
  YYSYMBOL_SEMICLN = 22,                   /* SEMICLN  */
  YYSYMBOL_IFTOKEN = 23,                   /* IFTOKEN  */
  YYSYMBOL_ELSETOKEN = 24,                 /* ELSETOKEN  */
  YYSYMBOL_WHILETOKEN = 25,                /* WHILETOKEN  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_VOID = 27,                      /* VOID  */
  YYSYMBOL_INT = 28,                       /* INT  */
  YYSYMBOL_CHAR = 29,                      /* CHAR  */
  YYSYMBOL_ASSIGN = 30,                    /* ASSIGN  */
  YYSYMBOL_ERROR = 31,                     /* ERROR  */
  YYSYMBOL_32_ = 32,                       /* ','  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_declList = 35,                  /* declList  */
  YYSYMBOL_decl = 36,                      /* decl  */
  YYSYMBOL_funDecl = 37,                   /* funDecl  */
  YYSYMBOL_formalDeclList = 38,            /* formalDeclList  */
  YYSYMBOL_formalDecl = 39,                /* formalDecl  */
  YYSYMBOL_varDecl = 40,                   /* varDecl  */
  YYSYMBOL_typeSpecifier = 41,             /* typeSpecifier  */
  YYSYMBOL_argList = 42,                   /* argList  */
  YYSYMBOL_compoundStmt = 43,              /* compoundStmt  */
  YYSYMBOL_statementList = 44,             /* statementList  */
  YYSYMBOL_statement = 45,                 /* statement  */
  YYSYMBOL_expression = 46,                /* expression  */
  YYSYMBOL_relExpr = 47,                   /* relExpr  */
  YYSYMBOL_addExpr = 48,                   /* addExpr  */
  YYSYMBOL_term = 49,                      /* term  */
  YYSYMBOL_factor = 50,                    /* factor  */
  YYSYMBOL_funcCall = 51,                  /* funcCall  */
  YYSYMBOL_condStmt = 52,                  /* condStmt  */
  YYSYMBOL_loopStmt = 53,                  /* loopStmt  */
  YYSYMBOL_returnStmt = 54                 /* returnStmt  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  61
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
       2,     2,     2,     2,    32,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    56,    62,    69,    70,    73,    85,    96,
     107,   118,   124,   131,   139,   151,   163,   177,   178,   179,
     182,   188,   195,   200,   206,   212,   219,   220,   221,   222,
     223,   224,   225,   231,   241,   254,   255,   258,   265,   272,
     279,   286,   293,   302,   309,   316,   319,   326,   333,   336,
     340,   350,   357,   361,   365,   368,   375,   386,   393,   403,
     412,   416
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTCONST",
  "CHARCONST", "ADDOP", "SUBOP", "MULOP", "DIVOP", "EQ", "NEQ", "LT", "GT",
  "LTE", "GTE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE",
  "RBRACE", "SEMICLN", "IFTOKEN", "ELSETOKEN", "WHILETOKEN", "RETURN",
  "VOID", "INT", "CHAR", "ASSIGN", "ERROR", "','", "$accept", "program",
  "declList", "decl", "funDecl", "formalDeclList", "formalDecl", "varDecl",
  "typeSpecifier", "argList", "compoundStmt", "statementList", "statement",
  "expression", "relExpr", "addExpr", "term", "factor", "funcCall",
  "condStmt", "loopStmt", "returnStmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    44
};
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     122,   -40,   -40,   -40,    21,   122,   -40,   -40,   -40,    31,
     -40,   -40,     2,    18,    48,   -40,    -7,   -15,   -40,    65,
      57,    28,   -40,   -40,   100,   122,    68,    72,    77,   -40,
     -40,   105,   -40,   -40,    81,    84,    55,   -40,   103,   -40,
      62,   -40,   104,   -40,    36,    53,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   140,   -40,     6,   105,   105,   143,
     105,   105,   -40,   117,    52,   -40,   -40,   105,   105,   105,
     105,   105,   105,   -40,   108,   108,   108,   108,   -40,   -40,
     -13,   167,   123,   -40,   -40,   151,   159,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   107,    53,    53,   -40,   -40,   -40,
     105,   137,    76,    76,   105,   167,   105,   160,   -40,   133,
     -40,    76,   -40,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    19,    17,    18,     0,     2,     3,     6,     5,     0,
       1,     4,     0,     0,     0,    15,     0,     0,    11,     0,
       0,     0,    10,     8,     0,     0,    13,     0,    51,    52,
      53,     0,    23,    32,     0,     0,     0,    31,     0,    27,
       0,    24,     0,    36,    35,    45,    48,    54,    28,    29,
      30,     9,     7,    12,     0,    16,     0,     0,     0,     0,
       0,     0,    60,     0,     0,    22,    25,     0,     0,     0,
       0,     0,     0,    26,     0,     0,     0,     0,    14,    55,
       0,    20,     0,    33,    49,     0,     0,    61,    41,    42,
      37,    38,    39,    40,    51,    43,    44,    46,    47,    56,
       0,    50,     0,     0,     0,    21,     0,    57,    59,     0,
      34,     0,    50,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,   170,   -40,   -40,   158,     7,     3,   -40,
     -10,   -40,   -39,   -31,   -40,   -40,    66,   109,   -40,   -40,
     -40,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    17,    18,    37,    38,    80,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    66,    24,     9,    99,    63,    23,     8,     9,    28,
      29,    30,     8,    21,    52,    22,    19,    25,    13,   100,
      14,    10,    31,    79,    15,    81,    82,    83,    19,    85,
      86,    28,    29,    30,    12,    16,    88,    89,    90,    91,
      92,    93,    74,    75,    31,     1,     2,     3,    21,    32,
      33,    34,    20,    35,    36,     1,     2,     3,    28,    29,
      30,    76,    77,   107,   108,    28,    29,    30,    26,   105,
      14,    31,   113,   109,    15,   110,    27,    62,    31,    28,
      29,    30,    21,    65,    33,    34,    54,    35,    36,     1,
       2,     3,    31,    56,    55,    57,    21,    60,    33,    34,
      61,    35,    36,     1,     2,     3,    64,    58,    28,    29,
      30,    94,    29,    30,    67,    68,    69,    70,    71,    72,
      21,    31,    51,    56,    31,   104,    73,    67,    68,    69,
      70,    71,    72,    67,    68,    69,    70,    71,    72,    87,
      95,    96,   101,    67,    68,    69,    70,    71,    72,     1,
       2,     3,   112,    67,    68,    69,    70,    71,    72,    78,
      84,    67,    68,    69,    70,    71,    72,   106,   102,    67,
      68,    69,    70,    71,    72,    11,   103,    67,    68,    69,
      70,    71,    72,    53,   111,    97,    98
};

static const yytype_int8 yycheck[] =
{
      31,    40,    17,     0,    17,    36,    16,     0,     5,     3,
       4,     5,     5,    20,    24,    22,    13,    32,    16,    32,
      18,     0,    16,    17,    22,    56,    57,    58,    25,    60,
      61,     3,     4,     5,     3,    17,    67,    68,    69,    70,
      71,    72,     6,     7,    16,    27,    28,    29,    20,    21,
      22,    23,     4,    25,    26,    27,    28,    29,     3,     4,
       5,     8,     9,   102,   103,     3,     4,     5,     3,   100,
      18,    16,   111,   104,    22,   106,    19,    22,    16,     3,
       4,     5,    20,    21,    22,    23,    18,    25,    26,    27,
      28,    29,    16,    16,    22,    18,    20,    16,    22,    23,
      16,    25,    26,    27,    28,    29,     3,    30,     3,     4,
       5,     3,     4,     5,    10,    11,    12,    13,    14,    15,
      20,    16,    22,    16,    16,    18,    22,    10,    11,    12,
      13,    14,    15,    10,    11,    12,    13,    14,    15,    22,
      74,    75,    19,    10,    11,    12,    13,    14,    15,    27,
      28,    29,    19,    10,    11,    12,    13,    14,    15,    19,
      17,    10,    11,    12,    13,    14,    15,    30,    17,    10,
      11,    12,    13,    14,    15,     5,    17,    10,    11,    12,
      13,    14,    15,    25,    24,    76,    77
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    27,    28,    29,    34,    35,    36,    37,    40,    41,
       0,    36,     3,    16,    18,    22,    17,    38,    39,    41,
       4,    20,    22,    43,    17,    32,     3,    19,     3,     4,
       5,    16,    21,    22,    23,    25,    26,    40,    41,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    22,    43,    39,    18,    22,    16,    18,    30,    46,
      16,    16,    22,    46,     3,    21,    45,    10,    11,    12,
      13,    14,    15,    22,     6,     7,     8,     9,    19,    17,
      42,    46,    46,    46,    17,    46,    46,    22,    46,    46,
      46,    46,    46,    46,     3,    49,    49,    50,    50,    17,
      32,    19,    17,    17,    18,    46,    30,    45,    45,    46,
      46,    24,    19,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    37,    37,
      37,    38,    38,    39,    39,    40,    40,    41,    41,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    48,    48,    48,    49,    49,    49,    50,
      50,    50,    50,    50,    50,    51,    51,    52,    52,    53,
      54,    54
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     5,     6,
       5,     1,     3,     2,     4,     3,     6,     1,     1,     1,
       1,     3,     3,     2,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     3,     6,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       4,     1,     1,     1,     1,     3,     4,     5,     7,     5,
       2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: declList  */
#line 49 "parser.y"
                 {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, (yyvsp[0].node));
                    ast = progNode;
                 }
#line 1216 "parser.tab.c"
    break;

  case 3: /* declList: decl  */
#line 57 "parser.y"
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[0].node));
                    (yyval.node) = declListNode;
                 }
#line 1226 "parser.tab.c"
    break;

  case 4: /* declList: declList decl  */
#line 63 "parser.y"
                 {
                    addChild((yyvsp[-1].node), (yyvsp[0].node));
                    (yyval.node) = (yyvsp[-1].node);
                 }
#line 1235 "parser.tab.c"
    break;

  case 7: /* funDecl: typeSpecifier ID LPAREN formalDeclList RPAREN compoundStmt  */
#line 74 "parser.y"
                {
                    scope = (yyvsp[-4].strval);
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE, (yyvsp[-5].value)));
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-4].strval)));
                    addChild(funDeclNode, (yyvsp[-2].node));  // Add formalDeclList
                    addChild(funDeclNode, (yyvsp[0].node));  // Add compoundStmt
                    (yyval.node) = funDeclNode;
                    ST_insert((yyvsp[-4].strval), "", (yyvsp[-5].value), FUNCTION);
                    scope = "";
                }
#line 1251 "parser.tab.c"
    break;

  case 8: /* funDecl: typeSpecifier ID LPAREN RPAREN compoundStmt  */
#line 86 "parser.y"
                {
                    scope = (yyvsp[-3].strval);
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE, (yyvsp[-4].value)));
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-3].strval)));
                    addChild(funDeclNode, (yyvsp[0].node));  // Add compoundStmt
                    (yyval.node) = funDeclNode;
                    ST_insert((yyvsp[-3].strval), "", (yyvsp[-4].value), FUNCTION);
                    scope = "";
		}
#line 1266 "parser.tab.c"
    break;

  case 9: /* funDecl: typeSpecifier ID LPAREN formalDeclList RPAREN SEMICLN  */
#line 97 "parser.y"
                {
                    scope = (yyvsp[-4].strval);
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE, (yyvsp[-5].value)));
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-4].strval)));
                    addChild(funDeclNode, (yyvsp[-2].node));  // Add formalDeclList
                    (yyval.node) = funDeclNode;
                    ST_insert((yyvsp[-4].strval), "", (yyvsp[-5].value), FUNCTION);
                    scope = "";
                }
#line 1281 "parser.tab.c"
    break;

  case 10: /* funDecl: typeSpecifier ID LPAREN RPAREN SEMICLN  */
#line 108 "parser.y"
                {
                    scope = (yyvsp[-3].strval);
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE, (yyvsp[-4].value)));
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-3].strval)));
                    (yyval.node) = funDeclNode;
                    ST_insert((yyvsp[-3].strval), "", (yyvsp[-4].value), FUNCTION);
                    scope = "";
                }
#line 1295 "parser.tab.c"
    break;

  case 11: /* formalDeclList: formalDecl  */
#line 119 "parser.y"
                {
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    addChild(formalDeclListNode, (yyvsp[0].node));
                    (yyval.node) = formalDeclListNode;
                }
#line 1305 "parser.tab.c"
    break;

  case 12: /* formalDeclList: formalDeclList ',' formalDecl  */
#line 125 "parser.y"
                {
                    addChild((yyvsp[-2].node), (yyvsp[0].node));
                    (yyval.node) = (yyvsp[-2].node);
                }
#line 1314 "parser.tab.c"
    break;

  case 13: /* formalDecl: typeSpecifier ID  */
#line 132 "parser.y"
                {
                    tree* formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, maketreeWithVal(TYPE, (yyvsp[-1].value)));
                    addChild(formalDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[0].strval)));
                    ST_insert((yyvsp[0].strval), scope, (yyvsp[-1].value), SCALAR);
                    (yyval.node) = formalDeclNode;
                }
#line 1326 "parser.tab.c"
    break;

  case 14: /* formalDecl: typeSpecifier ID LBRACKET RBRACKET  */
#line 140 "parser.y"
                {
                    tree* formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, maketreeWithVal(TYPE, (yyvsp[-3].value)));
                    tree* arrayNode = maketree(ARRAY);
                    addChild(arrayNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-2].strval)));
                    addChild(formalDeclNode, arrayNode);
                    ST_insert((yyvsp[-2].strval), scope, (yyvsp[-3].value), ARRAY);
                    (yyval.node) = formalDeclNode;
                }
#line 1340 "parser.tab.c"
    break;

  case 15: /* varDecl: typeSpecifier ID SEMICLN  */
#line 152 "parser.y"
                 {
                    if ((yyvsp[-2].value) == VOID_TYPE) {
                        yyerror("Variable cannot be of type 'void'");
                        (yyval.node) = maketree(ERROR);
                    } else {
                        tree* varDeclNode = maketree(VARDECL);
                        addChild(varDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-1].strval)));
                        (yyval.node) = varDeclNode;
                        ST_insert((yyvsp[-1].strval), scope, (yyvsp[-2].value), SCALAR);
                    }
                 }
#line 1356 "parser.tab.c"
    break;

  case 16: /* varDecl: typeSpecifier ID LBRACKET INTCONST RBRACKET SEMICLN  */
#line 164 "parser.y"
                 {
                    if ((yyvsp[-5].value) == VOID_TYPE) {
                        yyerror("Array cannot be of type 'void'");
                        (yyval.node) = maketree(ERROR);
                    } else {
                        tree* arrayDeclNode = maketree(VARDECL);
                        addChild(arrayDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-4].strval)));
                        (yyval.node) = arrayDeclNode;
                        ST_insert((yyvsp[-4].strval), scope, (yyvsp[-5].value), ARRAY);
                    }
                 }
#line 1372 "parser.tab.c"
    break;

  case 17: /* typeSpecifier: INT  */
#line 177 "parser.y"
                      { (yyval.value) = INT_TYPE; }
#line 1378 "parser.tab.c"
    break;

  case 18: /* typeSpecifier: CHAR  */
#line 178 "parser.y"
                       { (yyval.value) = CHAR_TYPE; }
#line 1384 "parser.tab.c"
    break;

  case 19: /* typeSpecifier: VOID  */
#line 179 "parser.y"
                       { (yyval.value) = VOID_TYPE; }
#line 1390 "parser.tab.c"
    break;

  case 20: /* argList: expression  */
#line 183 "parser.y"
                {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, (yyvsp[0].node));
                    (yyval.node) = argListNode;
                }
#line 1400 "parser.tab.c"
    break;

  case 21: /* argList: argList ',' expression  */
#line 189 "parser.y"
                {
                    addChild((yyvsp[-2].node), (yyvsp[0].node));
                    (yyval.node) = (yyvsp[-2].node);
                }
#line 1409 "parser.tab.c"
    break;

  case 22: /* compoundStmt: LBRACE statementList RBRACE  */
#line 196 "parser.y"
                {
                    (yyval.node) = maketree(COMPOUNDSTMT);
                    addChild((yyval.node), (yyvsp[-1].node));
                }
#line 1418 "parser.tab.c"
    break;

  case 23: /* compoundStmt: LBRACE RBRACE  */
#line 201 "parser.y"
                {
                    (yyval.node) = maketree(COMPOUNDSTMT);
                }
#line 1426 "parser.tab.c"
    break;

  case 24: /* statementList: statement  */
#line 207 "parser.y"
                {
                    tree* stmtListNode = maketree(STMTLIST);
                    addChild(stmtListNode, (yyvsp[0].node));
                    (yyval.node) = stmtListNode;
                }
#line 1436 "parser.tab.c"
    break;

  case 25: /* statementList: statementList statement  */
#line 213 "parser.y"
                {
                    addChild((yyvsp[-1].node), (yyvsp[0].node));
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1445 "parser.tab.c"
    break;

  case 32: /* statement: SEMICLN  */
#line 226 "parser.y"
                {
                    (yyval.node) = NULL;
                }
#line 1453 "parser.tab.c"
    break;

  case 33: /* expression: ID ASSIGN expression  */
#line 232 "parser.y"
                {
                    if (ST_lookup((yyvsp[-2].strval), scope) == -1 && ST_lookup((yyvsp[-2].strval), "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, (yyvsp[-2].strval));
                    }
                    tree* assgnNode = maketree(ASSIGN);
                    addChild(assgnNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-2].strval)));
                    addChild(assgnNode, (yyvsp[0].node));
                    (yyval.node) = assgnNode;
                }
#line 1467 "parser.tab.c"
    break;

  case 34: /* expression: ID LBRACKET expression RBRACKET ASSIGN expression  */
#line 242 "parser.y"
                {
                    if (ST_lookup((yyvsp[-5].strval), scope) == -1 && ST_lookup((yyvsp[-5].strval), "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, (yyvsp[-5].strval));
                    }
                    tree* assgnNode = maketree(ASSIGN);
                    tree* arrayAccess = maketree(ARRAY_ACCESS);
                    addChild(arrayAccess, maketreeWithStrVal(IDENTIFIER, (yyvsp[-5].strval)));
                    addChild(arrayAccess, (yyvsp[-3].node));  // index
                    addChild(assgnNode, arrayAccess);
                    addChild(assgnNode, (yyvsp[0].node));  // value
                    (yyval.node) = assgnNode;
                }
#line 1484 "parser.tab.c"
    break;

  case 37: /* relExpr: expression LT expression  */
#line 259 "parser.y"
                {
                    tree* relNode = maketree(LT);
                    addChild(relNode, (yyvsp[-2].node));
                    addChild(relNode, (yyvsp[0].node));
                    (yyval.node) = relNode;
                }
#line 1495 "parser.tab.c"
    break;

  case 38: /* relExpr: expression GT expression  */
#line 266 "parser.y"
                {
                    tree* relNode = maketree(GT);
                    addChild(relNode, (yyvsp[-2].node));
                    addChild(relNode, (yyvsp[0].node));
                    (yyval.node) = relNode;
                }
#line 1506 "parser.tab.c"
    break;

  case 39: /* relExpr: expression LTE expression  */
#line 273 "parser.y"
                {
                    tree* relNode = maketree(LTE);
                    addChild(relNode, (yyvsp[-2].node));
                    addChild(relNode, (yyvsp[0].node));
                    (yyval.node) = relNode;
                }
#line 1517 "parser.tab.c"
    break;

  case 40: /* relExpr: expression GTE expression  */
#line 280 "parser.y"
                {
                    tree* relNode = maketree(GTE);
                    addChild(relNode, (yyvsp[-2].node));
                    addChild(relNode, (yyvsp[0].node));
                    (yyval.node) = relNode;
                }
#line 1528 "parser.tab.c"
    break;

  case 41: /* relExpr: expression EQ expression  */
#line 287 "parser.y"
                {
                    tree* relNode = maketree(EQ);
                    addChild(relNode, (yyvsp[-2].node));
                    addChild(relNode, (yyvsp[0].node));
                    (yyval.node) = relNode;
                }
#line 1539 "parser.tab.c"
    break;

  case 42: /* relExpr: expression NEQ expression  */
#line 294 "parser.y"
                {
                    tree* relNode = maketree(NEQ);
                    addChild(relNode, (yyvsp[-2].node));
                    addChild(relNode, (yyvsp[0].node));
                    (yyval.node) = relNode;
                }
#line 1550 "parser.tab.c"
    break;

  case 43: /* addExpr: addExpr ADDOP term  */
#line 303 "parser.y"
                {
                    tree* addExprNode = maketree(ADDOP);
                    addChild(addExprNode, (yyvsp[-2].node));
                    addChild(addExprNode, (yyvsp[0].node));
                    (yyval.node) = addExprNode;
                }
#line 1561 "parser.tab.c"
    break;

  case 44: /* addExpr: addExpr SUBOP term  */
#line 310 "parser.y"
                {
                    tree* subExprNode = maketree(SUBOP);
                    addChild(subExprNode, (yyvsp[-2].node));
                    addChild(subExprNode, (yyvsp[0].node));
                    (yyval.node) = subExprNode;
                }
#line 1572 "parser.tab.c"
    break;

  case 46: /* term: term MULOP factor  */
#line 320 "parser.y"
                {
                    tree* mulExprNode = maketree(MULOP);
                    addChild(mulExprNode, (yyvsp[-2].node));
                    addChild(mulExprNode, (yyvsp[0].node));
                    (yyval.node) = mulExprNode;
                }
#line 1583 "parser.tab.c"
    break;

  case 47: /* term: term DIVOP factor  */
#line 327 "parser.y"
                {
                    tree* divExprNode = maketree(DIVOP);
                    addChild(divExprNode, (yyvsp[-2].node));
                    addChild(divExprNode, (yyvsp[0].node));
                    (yyval.node) = divExprNode;
                }
#line 1594 "parser.tab.c"
    break;

  case 49: /* factor: LPAREN expression RPAREN  */
#line 337 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1602 "parser.tab.c"
    break;

  case 50: /* factor: ID LBRACKET expression RBRACKET  */
#line 341 "parser.y"
                {
                    if (ST_lookup((yyvsp[-3].strval), scope) == -1 && ST_lookup((yyvsp[-3].strval), "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, (yyvsp[-3].strval));
                    }
                    tree* arrayNode = maketree(ARRAY_ACCESS);
                    addChild(arrayNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[-3].strval)));
                    addChild(arrayNode, (yyvsp[-1].node));
                    (yyval.node) = arrayNode;
                }
#line 1616 "parser.tab.c"
    break;

  case 51: /* factor: ID  */
#line 351 "parser.y"
                {
                    if (ST_lookup((yyvsp[0].strval), scope) == -1 && ST_lookup((yyvsp[0].strval), "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, (yyvsp[0].strval));
                    }
                    (yyval.node) = maketreeWithStrVal(IDENTIFIER, (yyvsp[0].strval));
                }
#line 1627 "parser.tab.c"
    break;

  case 52: /* factor: INTCONST  */
#line 358 "parser.y"
                {
                    (yyval.node) = maketreeWithVal(INTEGER, (yyvsp[0].value));
                }
#line 1635 "parser.tab.c"
    break;

  case 53: /* factor: CHARCONST  */
#line 362 "parser.y"
                {
                    (yyval.node) = maketreeWithVal(CHAR, (yyvsp[0].value));
                }
#line 1643 "parser.tab.c"
    break;

  case 55: /* funcCall: ID LPAREN RPAREN  */
#line 369 "parser.y"
                {
                    if (ST_lookup((yyvsp[-2].strval), "") == -1) {
                        printf("warning: line %d: implicit declaration of function '%s'\n", yylineno, (yyvsp[-2].strval));
                    }
                    (yyval.node) = maketreeWithStrVal(FUNCCALL, (yyvsp[-2].strval));
                }
#line 1654 "parser.tab.c"
    break;

  case 56: /* funcCall: ID LPAREN argList RPAREN  */
#line 376 "parser.y"
                {
                    if (ST_lookup((yyvsp[-3].strval), "") == -1) {
                        printf("warning: line %d: implicit declaration of function '%s'\n", yylineno, (yyvsp[-3].strval));
                    }
                    tree* funcCallNode = maketreeWithStrVal(FUNCCALL, (yyvsp[-3].strval));
                    addChild(funcCallNode, (yyvsp[-1].node));
                    (yyval.node) = funcCallNode;
                }
#line 1667 "parser.tab.c"
    break;

  case 57: /* condStmt: IFTOKEN LPAREN expression RPAREN statement  */
#line 387 "parser.y"
                {
                    tree* ifNode = maketree(IFSTMT);
                    addChild(ifNode, (yyvsp[-2].node));
                    addChild(ifNode, (yyvsp[0].node));
                    (yyval.node) = ifNode;
                }
#line 1678 "parser.tab.c"
    break;

  case 58: /* condStmt: IFTOKEN LPAREN expression RPAREN statement ELSETOKEN statement  */
#line 394 "parser.y"
                {
                    tree* ifElseNode = maketree(IFSTMT);
                    addChild(ifElseNode, (yyvsp[-4].node));
                    addChild(ifElseNode, (yyvsp[-2].node));
                    addChild(ifElseNode, (yyvsp[0].node));
                    (yyval.node) = ifElseNode;
                }
#line 1690 "parser.tab.c"
    break;

  case 59: /* loopStmt: WHILETOKEN LPAREN expression RPAREN statement  */
#line 404 "parser.y"
                {
                    tree* whileNode = maketree(LOOPSTMT);
                    addChild(whileNode, (yyvsp[-2].node));
                    addChild(whileNode, (yyvsp[0].node));
                    (yyval.node) = whileNode;
                }
#line 1701 "parser.tab.c"
    break;

  case 60: /* returnStmt: RETURN SEMICLN  */
#line 413 "parser.y"
                {
                    (yyval.node) = maketree(RETURNSTMT);
                }
#line 1709 "parser.tab.c"
    break;

  case 61: /* returnStmt: RETURN expression SEMICLN  */
#line 417 "parser.y"
                {
                    tree* returnNode = maketree(RETURNSTMT);
                    addChild(returnNode, (yyvsp[-1].node));
                    (yyval.node) = returnNode;
                }
#line 1719 "parser.tab.c"
    break;


#line 1723 "parser.tab.c"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 424 "parser.y"


int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}
