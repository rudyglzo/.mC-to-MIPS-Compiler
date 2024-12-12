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
#include <stdarg.h>
#include <limits.h>
#include "../src/tree.h"
#include "../src/strtab.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
extern int yycol;

void yyerror(const char *s);

// Global variables
tree* ast = NULL;  // AST root
int current_type;  // Track current declaration type
int in_loop = 0;   // Track if we're in a loop
char* current_func = NULL;  // Track current function for return type checking


#line 95 "parser.tab.c"

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
  YYSYMBOL_INTCONST = 3,                   /* INTCONST  */
  YYSYMBOL_CHARCONST = 4,                  /* CHARCONST  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_KWD_IF = 6,                     /* KWD_IF  */
  YYSYMBOL_KWD_ELSE = 7,                   /* KWD_ELSE  */
  YYSYMBOL_KWD_WHILE = 8,                  /* KWD_WHILE  */
  YYSYMBOL_KWD_INT = 9,                    /* KWD_INT  */
  YYSYMBOL_KWD_CHAR = 10,                  /* KWD_CHAR  */
  YYSYMBOL_KWD_RETURN = 11,                /* KWD_RETURN  */
  YYSYMBOL_KWD_VOID = 12,                  /* KWD_VOID  */
  YYSYMBOL_OPER_ADD = 13,                  /* OPER_ADD  */
  YYSYMBOL_OPER_SUB = 14,                  /* OPER_SUB  */
  YYSYMBOL_OPER_MUL = 15,                  /* OPER_MUL  */
  YYSYMBOL_OPER_DIV = 16,                  /* OPER_DIV  */
  YYSYMBOL_OPER_LT = 17,                   /* OPER_LT  */
  YYSYMBOL_OPER_GT = 18,                   /* OPER_GT  */
  YYSYMBOL_OPER_LTE = 19,                  /* OPER_LTE  */
  YYSYMBOL_OPER_GTE = 20,                  /* OPER_GTE  */
  YYSYMBOL_OPER_EQ = 21,                   /* OPER_EQ  */
  YYSYMBOL_OPER_NEQ = 22,                  /* OPER_NEQ  */
  YYSYMBOL_OPER_ASGN = 23,                 /* OPER_ASGN  */
  YYSYMBOL_LPAREN = 24,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 25,                    /* RPAREN  */
  YYSYMBOL_LSQ_BRKT = 26,                  /* LSQ_BRKT  */
  YYSYMBOL_RSQ_BRKT = 27,                  /* RSQ_BRKT  */
  YYSYMBOL_LCRLY_BRKT = 28,                /* LCRLY_BRKT  */
  YYSYMBOL_RCRLY_BRKT = 29,                /* RCRLY_BRKT  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_SEMICLN = 31,                   /* SEMICLN  */
  YYSYMBOL_ERROR = 32,                     /* ERROR  */
  YYSYMBOL_ILLEGAL_TOK = 33,               /* ILLEGAL_TOK  */
  YYSYMBOL_YYACCEPT = 34,                  /* $accept  */
  YYSYMBOL_program = 35,                   /* program  */
  YYSYMBOL_declList = 36,                  /* declList  */
  YYSYMBOL_decl = 37,                      /* decl  */
  YYSYMBOL_varDecl = 38,                   /* varDecl  */
  YYSYMBOL_typeSpec = 39,                  /* typeSpec  */
  YYSYMBOL_arrayDecl = 40,                 /* arrayDecl  */
  YYSYMBOL_formalDeclList = 41,            /* formalDeclList  */
  YYSYMBOL_formalDecl = 42,                /* formalDecl  */
  YYSYMBOL_funDecl = 43,                   /* funDecl  */
  YYSYMBOL_funBody = 44,                   /* funBody  */
  YYSYMBOL_localDeclList = 45,             /* localDeclList  */
  YYSYMBOL_stmtList = 46,                  /* stmtList  */
  YYSYMBOL_stmt = 47,                      /* stmt  */
  YYSYMBOL_compoundStmt = 48,              /* compoundStmt  */
  YYSYMBOL_49_1 = 49,                      /* $@1  */
  YYSYMBOL_assignStmt = 50,                /* assignStmt  */
  YYSYMBOL_condStmt = 51,                  /* condStmt  */
  YYSYMBOL_loopStmt = 52,                  /* loopStmt  */
  YYSYMBOL_53_2 = 53,                      /* $@2  */
  YYSYMBOL_returnStmt = 54,                /* returnStmt  */
  YYSYMBOL_expression = 55,                /* expression  */
  YYSYMBOL_relop = 56,                     /* relop  */
  YYSYMBOL_addExpr = 57,                   /* addExpr  */
  YYSYMBOL_addop = 58,                     /* addop  */
  YYSYMBOL_term = 59,                      /* term  */
  YYSYMBOL_mulop = 60,                     /* mulop  */
  YYSYMBOL_factor = 61,                    /* factor  */
  YYSYMBOL_var = 62,                       /* var  */
  YYSYMBOL_funcCallExpr = 63,              /* funcCallExpr  */
  YYSYMBOL_argList = 64                    /* argList  */
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
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    72,    77,    84,    88,    94,   132,   137,
     142,   149,   157,   162,   167,   172,   178,   183,   211,   237,
     245,   251,   256,   262,   267,   271,   275,   279,   283,   287,
     295,   294,   306,   318,   324,   334,   333,   346,   355,   367,
     368,   386,   387,   388,   389,   390,   391,   394,   395,   410,
     411,   414,   415,   430,   431,   435,   439,   443,   447,   459,
     466,   498,   533,   538,   544
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
  "\"end of file\"", "error", "\"invalid token\"", "INTCONST",
  "CHARCONST", "ID", "KWD_IF", "KWD_ELSE", "KWD_WHILE", "KWD_INT",
  "KWD_CHAR", "KWD_RETURN", "KWD_VOID", "OPER_ADD", "OPER_SUB", "OPER_MUL",
  "OPER_DIV", "OPER_LT", "OPER_GT", "OPER_LTE", "OPER_GTE", "OPER_EQ",
  "OPER_NEQ", "OPER_ASGN", "LPAREN", "RPAREN", "LSQ_BRKT", "RSQ_BRKT",
  "LCRLY_BRKT", "RCRLY_BRKT", "COMMA", "SEMICLN", "ERROR", "ILLEGAL_TOK",
  "$accept", "program", "declList", "decl", "varDecl", "typeSpec",
  "arrayDecl", "formalDeclList", "formalDecl", "funDecl", "funBody",
  "localDeclList", "stmtList", "stmt", "compoundStmt", "$@1", "assignStmt",
  "condStmt", "loopStmt", "$@2", "returnStmt", "expression", "relop",
  "addExpr", "addop", "term", "mulop", "factor", "var", "funcCallExpr",
  "argList", YY_NULLPTR
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
     285,   286,   287,   288
};
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      50,   -76,   -76,   -76,     7,    50,   -76,   -76,    -1,   -76,
     -76,   -76,    16,    50,     8,   -15,    31,   -24,   -76,    24,
     -76,   -76,    32,    37,    50,   -76,   -76,   -76,   -76,   -76,
      50,   -76,    62,     4,    32,    49,    55,    58,   -76,    26,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,    60,   -76,
      44,    44,    61,   -76,   -76,    30,    44,   -76,    53,    57,
      48,   -76,   -76,   -76,   -76,    44,    63,    64,    44,    44,
      66,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,   -76,
      44,    44,   -76,   -76,    44,    17,    56,   -76,    33,    67,
     -76,   -11,   -76,    59,    48,   -76,   -76,   -76,    79,    33,
     -76,    44,    33,   -76,   -76,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     8,     9,    10,     0,     2,     4,     5,     0,     6,
       1,     3,    13,    16,     0,     0,     0,     0,    15,     0,
      12,     7,    13,     0,     0,    11,    17,    21,    18,    14,
      23,    20,     0,     0,    13,     0,     0,     0,    35,     0,
      30,    19,    22,    25,    24,    26,    27,    28,     0,    29,
       0,     0,     0,    58,    59,     0,     0,    37,     0,    39,
      47,    51,    56,    57,    23,     0,     0,     0,     0,    64,
       0,    38,    49,    50,    42,    43,    41,    44,    45,    46,
       0,     0,    53,    54,     0,     0,     0,    60,     0,     0,
      63,     0,    55,    40,    48,    52,    31,    32,    33,     0,
      61,     0,     0,    36,    62,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -76,   -76,   -76,    83,    65,    13,    71,   -76,    70,   -76,
     -76,   -76,    34,   -75,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -48,   -76,    19,   -76,    15,   -76,    18,   -33,   -76,
     -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    15,    17,    18,     9,
      28,    30,    33,    42,    43,    64,    44,    45,    46,    52,
      47,    58,    80,    59,    81,    60,    84,    61,    62,    63,
      91
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    23,    66,    67,    12,    35,    24,    10,    70,    36,
      37,    19,    38,    98,   100,    39,    21,    86,    35,   101,
      89,    90,    36,    37,   103,    38,    16,   105,    39,    53,
      54,    55,    40,    41,    35,    20,    22,    16,    36,    37,
      13,    38,    14,    32,    39,    40,    96,    53,    54,    55,
      56,    25,    48,   104,    69,    48,    50,    57,    14,     1,
       2,    40,     3,    82,    83,    27,    48,    34,    56,    48,
      72,    73,    72,    73,    74,    75,    76,    77,    78,    79,
      49,    50,    51,    65,    71,    68,   102,    97,    11,    88,
      87,    92,    99,    26,    29,    31,    94,     0,    85,    93,
       0,     0,    95
};

static const yytype_int8 yycheck[] =
{
      33,    25,    50,    51,     5,     1,    30,     0,    56,     5,
       6,     3,     8,    88,    25,    11,    31,    65,     1,    30,
      68,    69,     5,     6,    99,     8,    13,   102,    11,     3,
       4,     5,    28,    29,     1,    27,     5,    24,     5,     6,
      24,     8,    26,    30,    11,    28,    29,     3,     4,     5,
      24,    27,    85,   101,    24,    88,    26,    31,    26,     9,
      10,    28,    12,    15,    16,    28,    99,     5,    24,   102,
      13,    14,    13,    14,    17,    18,    19,    20,    21,    22,
      31,    26,    24,    23,    31,    24,     7,    31,     5,    25,
      27,    25,    25,    22,    24,    30,    81,    -1,    64,    80,
      -1,    -1,    84
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    12,    35,    36,    37,    38,    39,    43,
       0,    37,     5,    24,    26,    40,    39,    41,    42,     3,
      27,    31,     5,    25,    30,    27,    40,    28,    44,    42,
      45,    38,    39,    46,     5,     1,     5,     6,     8,    11,
      28,    29,    47,    48,    50,    51,    52,    54,    62,    31,
      26,    24,    53,     3,     4,     5,    24,    31,    55,    57,
      59,    61,    62,    63,    49,    23,    55,    55,    24,    24,
      55,    31,    13,    14,    17,    18,    19,    20,    21,    22,
      56,    58,    15,    16,    60,    46,    55,    27,    25,    55,
      55,    64,    25,    57,    59,    61,    29,    31,    47,    25,
      25,    30,     7,    47,    55,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    39,    39,
      39,    40,    40,    40,    41,    41,    41,    42,    43,    44,
      45,    45,    46,    46,    47,    47,    47,    47,    47,    47,
      49,    48,    50,    51,    51,    53,    52,    54,    54,    55,
      55,    56,    56,    56,    56,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    61,
      62,    63,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     1,     1,
       1,     3,     2,     0,     3,     1,     0,     3,     6,     4,
       2,     0,     2,     0,     1,     1,     1,     1,     1,     2,
       0,     4,     4,     5,     7,     0,     6,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     3,     1,     1,     1,     1,
       4,     4,     3,     1,     0
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
#line 66 "parser.y"
        {
            ast = maketree(PROGRAM_NODE);
            addChild(ast, (yyvsp[0].node));
        }
#line 1220 "parser.tab.c"
    break;

  case 3: /* declList: declList decl  */
#line 73 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1229 "parser.tab.c"
    break;

  case 4: /* declList: decl  */
#line 78 "parser.y"
                {
                    (yyval.node) = maketree(DECL_LIST_NODE);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1238 "parser.tab.c"
    break;

  case 5: /* decl: varDecl  */
#line 85 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1246 "parser.tab.c"
    break;

  case 6: /* decl: funDecl  */
#line 89 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1254 "parser.tab.c"
    break;

  case 7: /* varDecl: typeSpec ID arrayDecl SEMICLN  */
#line 95 "parser.y"
        {
            (yyval.node) = maketree(VAR_DECL_NODE);
            addChild((yyval.node), (yyvsp[-3].node));
            int scope;

            if (current_type == VOID_TYPE) {
                report_error("Cannot declare void variable");
                free((yyvsp[-2].strval));
                YYERROR;
            }

            if ((yyvsp[-1].value) == 0) { // Regular variable
                if (ST_insert((yyvsp[-2].strval), current_type, SCALAR, &scope) != -1) {
                    addChild((yyval.node), maketreeWithVal(ID_NODE, scope));
                }
            } else if ((yyvsp[-1].value) > 0) { // Valid array size
                if (ST_insert((yyvsp[-2].strval), current_type, ARRAY, &scope) != -1) {
                    tree* id_node = maketreeWithVal(ID_NODE, scope);
                    id_node->array_size = (yyvsp[-1].value);
                    addChild((yyval.node), id_node);
                    
                    // Set array size in symbol table
                    symEntry* entry = current_scope->strTable[scope];
                    if (entry) entry->size = (yyvsp[-1].value);
                }
            } else { // Invalid array size (zero or negative)
                report_error("Array variable declared with size of zero");
                if (ST_insert((yyvsp[-2].strval), current_type, ARRAY, &scope) != -1) {
                    tree* id_node = maketreeWithVal(ID_NODE, scope);
                    id_node->array_size = 0;
                    addChild((yyval.node), id_node);
                }
            }
            free((yyvsp[-2].strval));
        }
#line 1294 "parser.tab.c"
    break;

  case 8: /* typeSpec: KWD_INT  */
#line 133 "parser.y"
                {
                    (yyval.node) = maketreeWithVal(TYPE_SPEC_NODE, INT_TYPE);
                    current_type = INT_TYPE;
                }
#line 1303 "parser.tab.c"
    break;

  case 9: /* typeSpec: KWD_CHAR  */
#line 138 "parser.y"
                {
                    (yyval.node) = maketreeWithVal(TYPE_SPEC_NODE, CHAR_TYPE);
                    current_type = CHAR_TYPE;
                }
#line 1312 "parser.tab.c"
    break;

  case 10: /* typeSpec: KWD_VOID  */
#line 143 "parser.y"
                {
                    (yyval.node) = maketreeWithVal(TYPE_SPEC_NODE, VOID_TYPE);
                    current_type = VOID_TYPE;
                }
#line 1321 "parser.tab.c"
    break;

  case 11: /* arrayDecl: LSQ_BRKT INTCONST RSQ_BRKT  */
#line 150 "parser.y"
    {
        if ((yyvsp[-1].value) <= 0) {
            (yyval.value) = -1;  // Just mark as invalid, don't report here
        } else {
            (yyval.value) = (yyvsp[-1].value);
        }
    }
#line 1333 "parser.tab.c"
    break;

  case 12: /* arrayDecl: LSQ_BRKT RSQ_BRKT  */
#line 158 "parser.y"
    {
        (yyval.value) = -1;  // Special marker for unsized arrays
    }
#line 1341 "parser.tab.c"
    break;

  case 13: /* arrayDecl: %empty  */
#line 162 "parser.y"
    {
        (yyval.value) = 0;  // Not an array
    }
#line 1349 "parser.tab.c"
    break;

  case 14: /* formalDeclList: formalDeclList COMMA formalDecl  */
#line 168 "parser.y"
                {
                    (yyval.node) = (yyvsp[-2].node);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1358 "parser.tab.c"
    break;

  case 15: /* formalDeclList: formalDecl  */
#line 173 "parser.y"
                {
                    (yyval.node) = maketree(FORMAL_DECL_LIST_NODE);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1367 "parser.tab.c"
    break;

  case 16: /* formalDeclList: %empty  */
#line 178 "parser.y"
                {
                    (yyval.node) = maketree(FORMAL_DECL_LIST_NODE);
                }
#line 1375 "parser.tab.c"
    break;

  case 17: /* formalDecl: typeSpec ID arrayDecl  */
#line 184 "parser.y"
    {
        (yyval.node) = maketree(FORMAL_DECL_NODE);
        addChild((yyval.node), (yyvsp[-2].node));
        int scope;
        if ((yyvsp[0].value) != 0) {  // Array parameter (both sized and unsized)
            if (ST_insert((yyvsp[-1].strval), current_type, ARRAY, &scope) == -1) {
                yyerror("Formal parameter array declaration failed");
            }
            tree* id_node = maketreeWithVal(ID_NODE, scope);
            id_node->array_size = (yyvsp[0].value);
            addChild((yyval.node), id_node);
            add_param(current_type, ARRAY);
        } else {  // Scalar parameter
            if (current_type == VOID_TYPE) {
                report_error("Cannot have void parameter");
                YYERROR;
            }
            if (ST_insert((yyvsp[-1].strval), current_type, SCALAR, &scope) == -1) {
                yyerror("Formal parameter declaration failed");
            }
            addChild((yyval.node), maketreeWithVal(ID_NODE, scope));
            add_param(current_type, SCALAR);
        }
        free((yyvsp[-1].strval));
    }
#line 1405 "parser.tab.c"
    break;

  case 18: /* funDecl: typeSpec ID LPAREN formalDeclList RPAREN funBody  */
#line 212 "parser.y"
                {
                    (yyval.node) = maketree(FUNC_DECL_NODE);
                    addChild((yyval.node), (yyvsp[-5].node));  // Add type specifier

                    int scope;
                    if (ST_insert((yyvsp[-4].strval), current_type, FUNCTION, &scope) == -1) {
                        yyerror("Function declaration failed");
                    } else {
                        tree* id_node = maketreeWithVal(ID_NODE, scope);
                        addChild((yyval.node), id_node);
                    }

                    current_func = strdup((yyvsp[-4].strval));
                    new_scope((yyvsp[-4].strval));

                    addChild((yyval.node), (yyvsp[-2].node));  // Add formal declarations
                    addChild((yyval.node), (yyvsp[0].node));  // Add function body

                    up_scope();
                    free(current_func);
                    current_func = NULL;
                    free((yyvsp[-4].strval));
                }
#line 1433 "parser.tab.c"
    break;

  case 19: /* funBody: LCRLY_BRKT localDeclList stmtList RCRLY_BRKT  */
#line 238 "parser.y"
                {
                    (yyval.node) = maketree(FUNC_BODY_NODE);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[-1].node));
                }
#line 1443 "parser.tab.c"
    break;

  case 20: /* localDeclList: localDeclList varDecl  */
#line 246 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1452 "parser.tab.c"
    break;

  case 21: /* localDeclList: %empty  */
#line 251 "parser.y"
                {
                    (yyval.node) = maketree(LOCAL_DECL_LIST_NODE);
                }
#line 1460 "parser.tab.c"
    break;

  case 22: /* stmtList: stmtList stmt  */
#line 257 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1469 "parser.tab.c"
    break;

  case 23: /* stmtList: %empty  */
#line 262 "parser.y"
                {
                    (yyval.node) = maketree(STMT_LIST_NODE);
                }
#line 1477 "parser.tab.c"
    break;

  case 24: /* stmt: assignStmt  */
#line 268 "parser.y"
     {
         (yyval.node) = (yyvsp[0].node);
     }
#line 1485 "parser.tab.c"
    break;

  case 25: /* stmt: compoundStmt  */
#line 272 "parser.y"
     {
         (yyval.node) = (yyvsp[0].node);
     }
#line 1493 "parser.tab.c"
    break;

  case 26: /* stmt: condStmt  */
#line 276 "parser.y"
     {
         (yyval.node) = (yyvsp[0].node);
     }
#line 1501 "parser.tab.c"
    break;

  case 27: /* stmt: loopStmt  */
#line 280 "parser.y"
     {
         (yyval.node) = (yyvsp[0].node);
     }
#line 1509 "parser.tab.c"
    break;

  case 28: /* stmt: returnStmt  */
#line 284 "parser.y"
     {
         (yyval.node) = (yyvsp[0].node);
     }
#line 1517 "parser.tab.c"
    break;

  case 29: /* stmt: error SEMICLN  */
#line 288 "parser.y"
     {
         (yyval.node) = maketree(STMT_NODE);
         yyerrok;
     }
#line 1526 "parser.tab.c"
    break;

  case 30: /* $@1: %empty  */
#line 295 "parser.y"
                {
                    new_scope("compound");
                }
#line 1534 "parser.tab.c"
    break;

  case 31: /* compoundStmt: LCRLY_BRKT $@1 stmtList RCRLY_BRKT  */
#line 299 "parser.y"
                {
                    (yyval.node) = maketree(COMPOUND_STMT_NODE);
                    addChild((yyval.node), (yyvsp[-1].node));
                    up_scope();
                }
#line 1544 "parser.tab.c"
    break;

  case 32: /* assignStmt: var OPER_ASGN expression SEMICLN  */
#line 307 "parser.y"
    {
        (yyval.node) = maketree(ASSIGN_STMT_NODE);
        addChild((yyval.node), (yyvsp[-3].node));
        addChild((yyval.node), (yyvsp[-1].node));
        
        if (!is_type_compatible((yyvsp[-3].node)->type, (yyvsp[-1].node)->type)) {
            report_error("Type mismatch in assignment");
        }
    }
#line 1558 "parser.tab.c"
    break;

  case 33: /* condStmt: KWD_IF LPAREN expression RPAREN stmt  */
#line 319 "parser.y"
                {
                    (yyval.node) = maketree(COND_STMT_NODE);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1568 "parser.tab.c"
    break;

  case 34: /* condStmt: KWD_IF LPAREN expression RPAREN stmt KWD_ELSE stmt  */
#line 325 "parser.y"
                {
                    (yyval.node) = maketree(COND_STMT_NODE);
                    addChild((yyval.node), (yyvsp[-4].node));
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1579 "parser.tab.c"
    break;

  case 35: /* $@2: %empty  */
#line 334 "parser.y"
                {
                    in_loop++;
                }
#line 1587 "parser.tab.c"
    break;

  case 36: /* loopStmt: KWD_WHILE $@2 LPAREN expression RPAREN stmt  */
#line 338 "parser.y"
                {
                    (yyval.node) = maketree(LOOP_STMT_NODE);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[0].node));
                    in_loop--;
                }
#line 1598 "parser.tab.c"
    break;

  case 37: /* returnStmt: KWD_RETURN SEMICLN  */
#line 347 "parser.y"
                {
                    (yyval.node) = maketree(RETURN_STMT_NODE);
                    // Check if void return type matches function
                    symEntry* func = ST_lookup(current_func);
                    if (func && func->data_type != VOID_TYPE) {
                        yyerror("Non-void function must return a value");
                    }
                }
#line 1611 "parser.tab.c"
    break;

  case 38: /* returnStmt: KWD_RETURN expression SEMICLN  */
#line 356 "parser.y"
                {
                    (yyval.node) = maketree(RETURN_STMT_NODE);
                    addChild((yyval.node), (yyvsp[-1].node));
                    // Check if return type matches function
                    symEntry* func = ST_lookup(current_func);
                    if (func && !is_type_compatible(func->data_type, (yyvsp[-1].node)->type)) {
                        yyerror("Return type mismatch");
                    }
                }
#line 1625 "parser.tab.c"
    break;

  case 40: /* expression: addExpr relop addExpr  */
#line 369 "parser.y"
          {
              (yyval.node) = maketree(EXPR_NODE);
              addChild((yyval.node), (yyvsp[-2].node));
              addChild((yyval.node), (yyvsp[-1].node));
              addChild((yyval.node), (yyvsp[0].node));

              // Type checking for relational operations
              if (!is_type_compatible((yyvsp[-2].node)->type, (yyvsp[0].node)->type)) {
                  yyerror("Type mismatch in relational expression");
              }
              if ((yyval.node)->type == VOID_TYPE) {
                  yyerror("Invalid expression of type void");
              }
              (yyval.node)->type = (yyvsp[-2].node)->type;
          }
#line 1645 "parser.tab.c"
    break;

  case 41: /* relop: OPER_LTE  */
#line 386 "parser.y"
                           { (yyval.node) = maketreeWithVal(RELOP_NODE, 4); }
#line 1651 "parser.tab.c"
    break;

  case 42: /* relop: OPER_LT  */
#line 387 "parser.y"
                           { (yyval.node) = maketreeWithVal(RELOP_NODE, 0); }
#line 1657 "parser.tab.c"
    break;

  case 43: /* relop: OPER_GT  */
#line 388 "parser.y"
                           { (yyval.node) = maketreeWithVal(RELOP_NODE, 1); }
#line 1663 "parser.tab.c"
    break;

  case 44: /* relop: OPER_GTE  */
#line 389 "parser.y"
                           { (yyval.node) = maketreeWithVal(RELOP_NODE, 5); }
#line 1669 "parser.tab.c"
    break;

  case 45: /* relop: OPER_EQ  */
#line 390 "parser.y"
                           { (yyval.node) = maketreeWithVal(RELOP_NODE, 2); }
#line 1675 "parser.tab.c"
    break;

  case 46: /* relop: OPER_NEQ  */
#line 391 "parser.y"
                           { (yyval.node) = maketreeWithVal(RELOP_NODE, 3); }
#line 1681 "parser.tab.c"
    break;

  case 48: /* addExpr: addExpr addop term  */
#line 396 "parser.y"
                {
                    (yyval.node) = maketree(ADD_EXPR_NODE);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[-1].node));
                    addChild((yyval.node), (yyvsp[0].node));

                    // Type checking for arithmetic operations
                    if (!is_type_compatible((yyvsp[-2].node)->type, (yyvsp[0].node)->type)) {
                        yyerror("Type mismatch in arithmetic expression");
                    }
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1698 "parser.tab.c"
    break;

  case 49: /* addop: OPER_ADD  */
#line 410 "parser.y"
                           { (yyval.node) = maketreeWithVal(ADDOP_NODE, 0); }
#line 1704 "parser.tab.c"
    break;

  case 50: /* addop: OPER_SUB  */
#line 411 "parser.y"
                           { (yyval.node) = maketreeWithVal(ADDOP_NODE, 1); }
#line 1710 "parser.tab.c"
    break;

  case 52: /* term: term mulop factor  */
#line 416 "parser.y"
                {
                    (yyval.node) = maketree(TERM_NODE);
                    addChild((yyval.node), (yyvsp[-2].node));
                    addChild((yyval.node), (yyvsp[-1].node));
                    addChild((yyval.node), (yyvsp[0].node));

                    // Type checking for arithmetic operations
                    if (!is_type_compatible((yyvsp[-2].node)->type, (yyvsp[0].node)->type)) {
                        yyerror("Type mismatch in arithmetic expression");
                    }
                    (yyval.node)->type = (yyvsp[-2].node)->type;
                }
#line 1727 "parser.tab.c"
    break;

  case 53: /* mulop: OPER_MUL  */
#line 430 "parser.y"
                           { (yyval.node) = maketreeWithVal(MULOP_NODE, 0); }
#line 1733 "parser.tab.c"
    break;

  case 54: /* mulop: OPER_DIV  */
#line 431 "parser.y"
                           { (yyval.node) = maketreeWithVal(MULOP_NODE, 1); }
#line 1739 "parser.tab.c"
    break;

  case 55: /* factor: LPAREN expression RPAREN  */
#line 436 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1747 "parser.tab.c"
    break;

  case 56: /* factor: var  */
#line 440 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1755 "parser.tab.c"
    break;

  case 57: /* factor: funcCallExpr  */
#line 444 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1763 "parser.tab.c"
    break;

  case 58: /* factor: INTCONST  */
#line 448 "parser.y"
                {
                    char str[32];
                    snprintf(str, sizeof(str), "%d", (yyvsp[0].value));
                    if (!isValidIntegerConstant(str)) {
                        report_error("Integer constant out of bounds");
                        (yyval.node) = maketreeWithVal(INT_CONST_NODE, 0);
                    } else {
                        (yyval.node) = maketreeWithVal(INT_CONST_NODE, (yyvsp[0].value));
                    }
                    (yyval.node)->type = INT_TYPE;
                }
#line 1779 "parser.tab.c"
    break;

  case 59: /* factor: CHARCONST  */
#line 460 "parser.y"
                {
                    (yyval.node) = maketreeWithVal(CHAR_CONST_NODE, (yyvsp[0].value));
                    (yyval.node)->type = CHAR_TYPE;
                }
#line 1788 "parser.tab.c"
    break;

  case 60: /* var: ID LSQ_BRKT expression RSQ_BRKT  */
#line 467 "parser.y"
    {
        symEntry* entry = ST_lookup((yyvsp[-3].strval));
        if (!entry) {
            report_error("Undeclared variable");
            (yyval.node) = maketreeWithVal(VAR_NODE, -1);
        } else {
            (yyval.node) = maketreeWithVal(VAR_NODE, hash((yyvsp[-3].strval)));
            (yyval.node)->type = entry->data_type;
            
            // Check if variable is an array
            if (entry->symbol_type != ARRAY) {
                report_error("Non-array identifier used as an array");
            } else {
                // Check array index type
                if ((yyvsp[-1].node)->nodeKind == CHAR_CONST_NODE || 
                    (yyvsp[-1].node)->type == CHAR_TYPE) {
                    report_error("Array indexed using non-integer expression");
                }
                // Check bounds for constant indices
                else if ((yyvsp[-1].node)->nodeKind == INT_CONST_NODE && entry->size > 0) {
                    if ((yyvsp[-1].node)->val < 0 || (yyvsp[-1].node)->val >= entry->size) {
                        report_error("Statically sized array indexed with constant, out-of-bounds expression");
                    }
                }
            }
            addChild((yyval.node), (yyvsp[-1].node));
        }
        free((yyvsp[-3].strval));
    }
#line 1822 "parser.tab.c"
    break;

  case 61: /* funcCallExpr: ID LPAREN argList RPAREN  */
#line 499 "parser.y"
    {
        symEntry* entry = ST_lookup((yyvsp[-3].strval));
        if (!entry) {
            report_error("Undefined function");
            (yyval.node) = maketreeWithVal(FUNC_CALL_NODE, -1);
        } else {
            (yyval.node) = maketree(FUNC_CALL_NODE);
            addChild((yyval.node), maketreeWithVal(ID_NODE, hash((yyvsp[-3].strval))));
            addChild((yyval.node), (yyvsp[-1].node));
            
            int expected = get_param_count((yyvsp[-3].strval));
            int actual = count_args((yyvsp[-1].node));
            
            if (actual < expected) {
                report_error("Too few arguments provided in function call");
            } else if (actual > expected) {
                report_error("Too many arguments provided in function call");
            }

            // Check argument types
            param* formal = get_param_list((yyvsp[-3].strval));
            for (int i = 0; i < actual && formal; i++) {
                tree* arg = getChild((yyvsp[-1].node), i);
                if (!check_arg_type(formal, arg)) {
                    report_error("Argument type mismatch in function call");
                }
                formal = formal->next;
            }
            (yyval.node)->type = entry->data_type;
        }
        free((yyvsp[-3].strval));
    }
#line 1859 "parser.tab.c"
    break;

  case 62: /* argList: argList COMMA expression  */
#line 534 "parser.y"
                {
                    (yyval.node) = (yyvsp[-2].node);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1868 "parser.tab.c"
    break;

  case 63: /* argList: expression  */
#line 539 "parser.y"
                {
                    (yyval.node) = maketree(ARG_LIST_NODE);
                    addChild((yyval.node), (yyvsp[0].node));
                }
#line 1877 "parser.tab.c"
    break;

  case 64: /* argList: %empty  */
#line 544 "parser.y"
                {
                    (yyval.node) = maketree(ARG_LIST_NODE);
                }
#line 1885 "parser.tab.c"
    break;


#line 1889 "parser.tab.c"

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

#line 548 "parser.y"


void yyerror(const char *s) {
    if (strcmp(s, "syntax error") == 0) {
        fprintf(stderr, "error: line %d: syntax error\n", yylineno);
    } else {
        fprintf(stderr, "error: line %d: %s\n", yylineno, s);
    }
}

void report_error(const char *format, ...) {
    va_list args;
    va_start(args, format);
    fprintf(stderr, "error: line %d: ", yylineno);
    vfprintf(stderr, format, args);
    fprintf(stderr, ".\n");
    va_end(args);
}

int is_integer_expression(tree* node) {
    return node->type == INT_TYPE || node->nodeKind == INT_CONST_NODE;
}

int yyparse();
