/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     GTE = 258,
     LTE = 259,
     GT = 260,
     LT = 261,
     NEQ = 262,
     EQ = 263,
     ASSIGN = 264,
     SUBOP = 265,
     ADDOP = 266,
     DIVOP = 267,
     MULOP = 268,
     IFTOKEN = 269,
     ELSETOKEN = 270,
     ID = 271,
     INTCONST = 272,
     CHARCONST = 273,
     LPAREN = 274,
     RPAREN = 275,
     LBRACKET = 276,
     RBRACKET = 277,
     LBRACE = 278,
     RBRACE = 279,
     SEMICLN = 280,
     WHILETOKEN = 281,
     RETURN = 282,
     VOID = 283,
     INT = 284,
     CHAR = 285,
     ERROR = 286
   };
#endif
/* Tokens.  */
#define GTE 258
#define LTE 259
#define GT 260
#define LT 261
#define NEQ 262
#define EQ 263
#define ASSIGN 264
#define SUBOP 265
#define ADDOP 266
#define DIVOP 267
#define MULOP 268
#define IFTOKEN 269
#define ELSETOKEN 270
#define ID 271
#define INTCONST 272
#define CHARCONST 273
#define LPAREN 274
#define RPAREN 275
#define LBRACKET 276
#define RBRACKET 277
#define LBRACE 278
#define RBRACE 279
#define SEMICLN 280
#define WHILETOKEN 281
#define RETURN 282
#define VOID 283
#define INT 284
#define CHAR 285
#define ERROR 286




/* Copy the first part of user declarations.  */
#line 1 "src/parser.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "src/parser.y"
{
    int value;
    struct treenode *node;
    char *strval;
}
/* Line 193 of yacc.c.  */
#line 179 "obj/parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 192 "obj/parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   183

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNRULES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    21,    27,
      29,    33,    36,    41,    45,    52,    54,    56,    58,    60,
      64,    68,    71,    73,    76,    79,    81,    83,    85,    87,
      89,    91,    95,    97,    99,   101,   105,   109,   113,   117,
     121,   125,   131,   137,   145,   149,   153,   155,   159,   163,
     165,   169,   174,   176,   178,   180,   182,   186,   191,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    36,    -1,    35,    36,    -1,
      40,    -1,    37,    -1,    41,    16,    19,    38,    20,    43,
      -1,    41,    16,    19,    20,    43,    -1,    39,    -1,    38,
      32,    39,    -1,    41,    16,    -1,    41,    16,    21,    22,
      -1,    41,    16,    25,    -1,    41,    16,    21,    17,    22,
      25,    -1,    29,    -1,    30,    -1,    28,    -1,    46,    -1,
      42,    32,    46,    -1,    23,    44,    24,    -1,    23,    24,
      -1,    45,    -1,    44,    45,    -1,    46,    25,    -1,    43,
      -1,    49,    -1,    48,    -1,    54,    -1,    40,    -1,    25,
      -1,    16,     9,    46,    -1,    50,    -1,    47,    -1,    53,
      -1,    46,     6,    46,    -1,    46,     5,    46,    -1,    46,
       8,    46,    -1,    46,     7,    46,    -1,    46,     4,    46,
      -1,    46,     3,    46,    -1,    26,    19,    46,    20,    45,
      -1,    14,    19,    46,    20,    45,    -1,    14,    19,    46,
      20,    45,    15,    45,    -1,    50,    11,    51,    -1,    50,
      10,    51,    -1,    51,    -1,    51,    13,    52,    -1,    51,
      12,    52,    -1,    52,    -1,    19,    46,    20,    -1,    16,
      21,    46,    22,    -1,    16,    -1,    17,    -1,    18,    -1,
      53,    -1,    16,    19,    20,    -1,    16,    19,    42,    20,
      -1,    27,    25,    -1,    27,    46,    25,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    56,    62,    69,    70,    73,    88,   102,
     108,   115,   123,   135,   147,   161,   162,   163,   166,   172,
     179,   187,   193,   201,   210,   211,   212,   213,   214,   215,
     216,   222,   232,   233,   234,   238,   245,   252,   259,   266,
     273,   282,   291,   298,   309,   316,   323,   326,   333,   340,
     343,   347,   357,   364,   368,   372,   375,   380,   388,   392
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "GTE", "LTE", "GT", "LT", "NEQ", "EQ",
  "ASSIGN", "SUBOP", "ADDOP", "DIVOP", "MULOP", "IFTOKEN", "ELSETOKEN",
  "ID", "INTCONST", "CHARCONST", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "SEMICLN", "WHILETOKEN", "RETURN",
  "VOID", "INT", "CHAR", "ERROR", "','", "$accept", "program", "declList",
  "decl", "funDecl", "formalDeclList", "formalDecl", "varDecl",
  "typeSpecifier", "argList", "compoundStmt", "statementList", "statement",
  "expression", "relExpr", "loopStmt", "condStmt", "addExpr", "term",
  "factor", "funcCall", "returnStmt", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    37,    38,
      38,    39,    39,    40,    40,    41,    41,    41,    42,    42,
      43,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    46,    46,    46,    46,    47,    47,    47,    47,    47,
      47,    48,    49,    49,    50,    50,    50,    51,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    54
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     5,     1,
       3,     2,     4,     3,     6,     1,     1,     1,     1,     3,
       3,     2,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     5,     5,     7,     3,     3,     1,     3,     3,     1,
       3,     4,     1,     1,     1,     1,     3,     4,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    15,    16,     0,     2,     3,     6,     5,     0,
       1,     4,     0,     0,     0,    13,     0,     0,     9,     0,
       0,     0,     8,     0,     0,    11,     0,     0,    52,    53,
      54,     0,    21,    30,     0,     0,    29,     0,    25,     0,
      22,     0,    33,    27,    26,    32,    46,    49,    34,    28,
       7,    10,     0,    14,     0,     0,     0,     0,     0,     0,
      58,     0,     0,    20,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,     0,    12,     0,    31,    56,
       0,    18,     0,    50,     0,    59,    40,    39,    36,    35,
      38,    37,    52,    45,    55,    44,    48,    47,     0,    57,
       0,    51,     0,    42,    19,    41,     0,    43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    17,    18,    36,    37,    80,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -39
static const yytype_int16 yypact[] =
{
      -8,   -39,   -39,   -39,     2,    -8,   -39,   -39,   -39,    77,
     -39,   -39,    42,   111,    49,   -39,    72,   -14,   -39,   106,
     116,    73,   -39,    72,    -8,   108,   147,   156,    -4,   -39,
     -39,    67,   -39,   -39,   157,   126,   -39,   161,   -39,    90,
     -39,     6,   -39,   -39,   -39,   101,   115,   -39,   148,   -39,
     -39,   -39,   158,   -39,    67,    67,   130,    67,    50,    67,
     -39,    37,     8,   -39,   -39,    67,    67,    67,    67,    67,
      67,   -39,   146,   146,   146,   146,   -39,    68,   -39,   -39,
     -13,   149,    43,   -39,    74,   -39,   -39,   -39,   -39,   -39,
     -39,   -39,    11,   115,   -39,   115,   -39,   -39,   107,   -39,
      67,   -39,   107,   163,   149,   -39,   107,   -39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -39,   -39,   -39,   174,   -39,   -39,   159,   105,     3,   -39,
      36,   -39,   -38,   -31,   -39,   -39,   -39,   -39,    98,    99,
      94,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int8 yytable[] =
{
      58,    64,    10,     9,    61,    55,    23,    99,     9,    65,
      66,    67,    68,    69,    70,    56,    19,    57,    24,   100,
       1,     2,     3,    77,    78,    81,    82,    19,    84,    14,
      56,    71,    57,    15,    86,    87,    88,    89,    90,    91,
      65,    66,    67,    68,    69,    70,    65,    66,    67,    68,
      69,    70,    22,    65,    66,    67,    68,    69,    70,    50,
     103,    13,    85,    14,   105,   101,    20,    15,   107,   104,
      83,    65,    66,    67,    68,    69,    70,    65,    66,    67,
      68,    69,    70,    28,    29,    30,    31,    27,    98,    28,
      29,    30,    31,    12,   102,    21,    21,    32,    33,    34,
      35,     1,     2,     3,    27,     8,    28,    29,    30,    31,
       8,    72,    73,    21,    63,    33,    34,    35,     1,     2,
       3,    27,    25,    28,    29,    30,    31,    74,    75,    52,
      21,    16,    33,    34,    35,     1,     2,     3,    26,     1,
       2,     3,    28,    29,    30,    31,    28,    29,    30,    31,
      79,    60,    65,    66,    67,    68,    69,    70,   -55,   -55,
     -55,   -55,    92,    29,    30,    31,    94,    94,    94,    94,
      93,    95,    53,    96,    97,    54,    59,    62,   106,    11,
      76,     0,     0,    51
};

static const yytype_int8 yycheck[] =
{
      31,    39,     0,     0,    35,     9,    20,    20,     5,     3,
       4,     5,     6,     7,     8,    19,    13,    21,    32,    32,
      28,    29,    30,    54,    55,    56,    57,    24,    59,    21,
      19,    25,    21,    25,    65,    66,    67,    68,    69,    70,
       3,     4,     5,     6,     7,     8,     3,     4,     5,     6,
       7,     8,    16,     3,     4,     5,     6,     7,     8,    23,
      98,    19,    25,    21,   102,    22,    17,    25,   106,   100,
      20,     3,     4,     5,     6,     7,     8,     3,     4,     5,
       6,     7,     8,    16,    17,    18,    19,    14,    20,    16,
      17,    18,    19,    16,    20,    23,    23,    24,    25,    26,
      27,    28,    29,    30,    14,     0,    16,    17,    18,    19,
       5,    10,    11,    23,    24,    25,    26,    27,    28,    29,
      30,    14,    16,    16,    17,    18,    19,    12,    13,    21,
      23,    20,    25,    26,    27,    28,    29,    30,    22,    28,
      29,    30,    16,    17,    18,    19,    16,    17,    18,    19,
      20,    25,     3,     4,     5,     6,     7,     8,    10,    11,
      12,    13,    16,    17,    18,    19,    72,    73,    74,    75,
      72,    73,    25,    74,    75,    19,    19,    16,    15,     5,
      22,    -1,    -1,    24
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    28,    29,    30,    34,    35,    36,    37,    40,    41,
       0,    36,    16,    19,    21,    25,    20,    38,    39,    41,
      17,    23,    43,    20,    32,    16,    22,    14,    16,    17,
      18,    19,    24,    25,    26,    27,    40,    41,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      43,    39,    21,    25,    19,     9,    19,    21,    46,    19,
      25,    46,    16,    24,    45,     3,     4,     5,     6,     7,
       8,    25,    10,    11,    12,    13,    22,    46,    46,    20,
      42,    46,    46,    20,    46,    25,    46,    46,    46,    46,
      46,    46,    16,    51,    53,    51,    52,    52,    20,    20,
      32,    22,    20,    45,    46,    45,    15,    45
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 49 "src/parser.y"
    {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, (yyvsp[(1) - (1)].node));
                    ast = progNode;
                 ;}
    break;

  case 3:
#line 57 "src/parser.y"
    {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = declListNode;
                 ;}
    break;

  case 4:
#line 63 "src/parser.y"
    {
                    addChild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
                    (yyval.node) = (yyvsp[(1) - (2)].node);
                 ;}
    break;

  case 7:
#line 74 "src/parser.y"
    {
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE_NODE, (yyvsp[(1) - (6)].value)));  // Use TYPE_NODE
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(2) - (6)].strval)));
                    if ((yyvsp[(4) - (6)].node)) {
                        addChild(funDeclNode, (yyvsp[(4) - (6)].node));  // Add formalDeclList
                    }
                    if ((yyvsp[(6) - (6)].node)) {
                        addChild(funDeclNode, (yyvsp[(6) - (6)].node));  // Add compoundStmt
                    }
                    ST_insert((yyvsp[(2) - (6)].strval), "", (yyvsp[(1) - (6)].value), FUNCTION);
                    (yyval.node) = funDeclNode;
                    scope = "";
                ;}
    break;

  case 8:
#line 89 "src/parser.y"
    {
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE_NODE, (yyvsp[(1) - (5)].value)));  // Use TYPE_NODE
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(2) - (5)].strval)));
                    if ((yyvsp[(5) - (5)].node)) {
                        addChild(funDeclNode, (yyvsp[(5) - (5)].node));  // Add compoundStmt
                    }
                    ST_insert((yyvsp[(2) - (5)].strval), "", (yyvsp[(1) - (5)].value), FUNCTION);
                    (yyval.node) = funDeclNode;
                    scope = "";
                ;}
    break;

  case 9:
#line 103 "src/parser.y"
    {
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    addChild(formalDeclListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = formalDeclListNode;
                ;}
    break;

  case 10:
#line 109 "src/parser.y"
    {
                    addChild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                    (yyval.node) = (yyvsp[(1) - (3)].node);
                ;}
    break;

  case 11:
#line 116 "src/parser.y"
    {
                    tree* formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, maketreeWithVal(TYPE_NODE, (yyvsp[(1) - (2)].value)));  // Use TYPE_NODE
                    addChild(formalDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(2) - (2)].strval)));
                    ST_insert((yyvsp[(2) - (2)].strval), scope, (yyvsp[(1) - (2)].value), SCALAR);
                    (yyval.node) = formalDeclNode;
                ;}
    break;

  case 12:
#line 124 "src/parser.y"
    {
                    tree* formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, maketreeWithVal(TYPE_NODE, (yyvsp[(1) - (4)].value)));  // Use TYPE_NODE
                    tree* arrayNode = maketree(ARRAY_NODE);  // Use ARRAY_NODE
                    addChild(arrayNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(2) - (4)].strval)));
                    addChild(formalDeclNode, arrayNode);
                    ST_insert((yyvsp[(2) - (4)].strval), scope, (yyvsp[(1) - (4)].value), ARRAY);
                    (yyval.node) = formalDeclNode;
                ;}
    break;

  case 13:
#line 136 "src/parser.y"
    {
                    if ((yyvsp[(1) - (3)].value) == VOID_TYPE) {
                        yyerror("Variable cannot be of type 'void'");
                        (yyval.node) = maketree(ERROR_NODE);  // Use ERROR_NODE
                    } else {
                        tree* varDeclNode = maketree(VARDECL);
                        addChild(varDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(2) - (3)].strval)));
                        (yyval.node) = varDeclNode;
                        ST_insert((yyvsp[(2) - (3)].strval), scope, (yyvsp[(1) - (3)].value), SCALAR);
                    }
                 ;}
    break;

  case 14:
#line 148 "src/parser.y"
    {
                    if ((yyvsp[(1) - (6)].value) == VOID_TYPE) {
                        yyerror("Array cannot be of type 'void'");
                        (yyval.node) = maketree(ERROR_NODE);  // Use ERROR_NODE
                    } else {
                        tree* arrayDeclNode = maketree(VARDECL);
                        addChild(arrayDeclNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(2) - (6)].strval)));
                        (yyval.node) = arrayDeclNode;
                        ST_insert((yyvsp[(2) - (6)].strval), scope, (yyvsp[(1) - (6)].value), ARRAY);
                    }
                 ;}
    break;

  case 15:
#line 161 "src/parser.y"
    { (yyval.value) = INT_TYPE; ;}
    break;

  case 16:
#line 162 "src/parser.y"
    { (yyval.value) = CHAR_TYPE; ;}
    break;

  case 17:
#line 163 "src/parser.y"
    { (yyval.value) = VOID_TYPE; ;}
    break;

  case 18:
#line 167 "src/parser.y"
    {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, (yyvsp[(1) - (1)].node));
                    (yyval.node) = argListNode;
                ;}
    break;

  case 19:
#line 173 "src/parser.y"
    {
                    addChild((yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
                    (yyval.node) = (yyvsp[(1) - (3)].node);
                ;}
    break;

  case 20:
#line 180 "src/parser.y"
    {
                    tree* compNode = maketree(COMPOUNDSTMT);
                    if ((yyvsp[(2) - (3)].node)) {
                        addChild(compNode, (yyvsp[(2) - (3)].node));  // Add statementList if it exists
                    }
                    (yyval.node) = compNode;
                ;}
    break;

  case 21:
#line 188 "src/parser.y"
    {
                    (yyval.node) = maketree(COMPOUNDSTMT);
                ;}
    break;

  case 22:
#line 194 "src/parser.y"
    {
                    tree* stmtListNode = maketree(STMTLIST);
                    if ((yyvsp[(1) - (1)].node)) {
                        addChild(stmtListNode, (yyvsp[(1) - (1)].node));
                    }
                    (yyval.node) = stmtListNode;
                ;}
    break;

  case 23:
#line 202 "src/parser.y"
    {
                    if ((yyvsp[(2) - (2)].node)) {
                        addChild((yyvsp[(1) - (2)].node), (yyvsp[(2) - (2)].node));
                    }
                    (yyval.node) = (yyvsp[(1) - (2)].node);
                ;}
    break;

  case 30:
#line 217 "src/parser.y"
    {
                    (yyval.node) = NULL;
                ;}
    break;

  case 31:
#line 223 "src/parser.y"
    {
                    if (ST_lookup((yyvsp[(1) - (3)].strval), scope) == -1 && ST_lookup((yyvsp[(1) - (3)].strval), "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, (yyvsp[(1) - (3)].strval));
                    }
                    tree* assgnNode = maketree(ASSIGNSTMT);
                    addChild(assgnNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(1) - (3)].strval)));
                    addChild(assgnNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = assgnNode;
                ;}
    break;

  case 35:
#line 239 "src/parser.y"
    {
          tree* relNode = maketree(LT_NODE);  // Use LT_NODE
          addChild(relNode, (yyvsp[(1) - (3)].node));
          addChild(relNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = relNode;
      ;}
    break;

  case 36:
#line 246 "src/parser.y"
    {
          tree* relNode = maketree(GT_NODE);  // Use GT_NODE
          addChild(relNode, (yyvsp[(1) - (3)].node));
          addChild(relNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = relNode;
      ;}
    break;

  case 37:
#line 253 "src/parser.y"
    {
          tree* relNode = maketree(EQ_NODE);  // Use EQ_NODE
          addChild(relNode, (yyvsp[(1) - (3)].node));
          addChild(relNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = relNode;
      ;}
    break;

  case 38:
#line 260 "src/parser.y"
    {
          tree* relNode = maketree(NEQ_NODE);  // Use NEQ_NODE
          addChild(relNode, (yyvsp[(1) - (3)].node));
          addChild(relNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = relNode;
      ;}
    break;

  case 39:
#line 267 "src/parser.y"
    {
          tree* relNode = maketree(LTE_NODE);  // Use LTE_NODE
          addChild(relNode, (yyvsp[(1) - (3)].node));
          addChild(relNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = relNode;
      ;}
    break;

  case 40:
#line 274 "src/parser.y"
    {
          tree* relNode = maketree(GTE_NODE);  // Use GTE_NODE
          addChild(relNode, (yyvsp[(1) - (3)].node));
          addChild(relNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = relNode;
      ;}
    break;

  case 41:
#line 283 "src/parser.y"
    {
                    tree* whileNode = maketree(WHILESTMT);
                    addChild(whileNode, (yyvsp[(3) - (5)].node));
                    addChild(whileNode, (yyvsp[(5) - (5)].node));
                    (yyval.node) = whileNode;
                ;}
    break;

  case 42:
#line 292 "src/parser.y"
    {
                    tree* ifNode = maketree(IFSTMT);
                    addChild(ifNode, (yyvsp[(3) - (5)].node));
                    addChild(ifNode, (yyvsp[(5) - (5)].node));
                    (yyval.node) = ifNode;
                ;}
    break;

  case 43:
#line 299 "src/parser.y"
    {
                    tree* ifElseNode = maketree(IFSTMT);
                    addChild(ifElseNode, (yyvsp[(3) - (7)].node));
                    addChild(ifElseNode, (yyvsp[(5) - (7)].node));
                    addChild(ifElseNode, (yyvsp[(7) - (7)].node));
                    (yyval.node) = ifElseNode;
                ;}
    break;

  case 44:
#line 310 "src/parser.y"
    {
          tree* addExprNode = maketree(ADDOP_NODE);  // Use ADDOP_NODE
          addChild(addExprNode, (yyvsp[(1) - (3)].node));
          addChild(addExprNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = addExprNode;
      ;}
    break;

  case 45:
#line 317 "src/parser.y"
    {
          tree* subExprNode = maketree(SUBOP_NODE);  // Use SUBOP_NODE
          addChild(subExprNode, (yyvsp[(1) - (3)].node));
          addChild(subExprNode, (yyvsp[(3) - (3)].node));
          (yyval.node) = subExprNode;
      ;}
    break;

  case 47:
#line 327 "src/parser.y"
    {
                    tree* mulExprNode = maketree(MULOP_NODE);  // Use MULOP_NODE
                    addChild(mulExprNode, (yyvsp[(1) - (3)].node));
                    addChild(mulExprNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = mulExprNode;
                ;}
    break;

  case 48:
#line 334 "src/parser.y"
    {
                    tree* divExprNode = maketree(DIVOP_NODE);  // Use DIVOP_NODE
                    addChild(divExprNode, (yyvsp[(1) - (3)].node));
                    addChild(divExprNode, (yyvsp[(3) - (3)].node));
                    (yyval.node) = divExprNode;
                ;}
    break;

  case 50:
#line 344 "src/parser.y"
    {
                    (yyval.node) = (yyvsp[(2) - (3)].node);
                ;}
    break;

  case 51:
#line 348 "src/parser.y"
    {
                    if (ST_lookup((yyvsp[(1) - (4)].strval), scope) == -1 && ST_lookup((yyvsp[(1) - (4)].strval), "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, (yyvsp[(1) - (4)].strval));
                    }
                    tree* arrayNode = maketree(ARRAY_ACCESS);
                    addChild(arrayNode, maketreeWithStrVal(IDENTIFIER, (yyvsp[(1) - (4)].strval)));
                    addChild(arrayNode, (yyvsp[(3) - (4)].node));
                    (yyval.node) = arrayNode;
                ;}
    break;

  case 52:
#line 358 "src/parser.y"
    {
                    if (ST_lookup((yyvsp[(1) - (1)].strval), scope) == -1 && ST_lookup((yyvsp[(1) - (1)].strval), "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, (yyvsp[(1) - (1)].strval));
                    }
                    (yyval.node) = maketreeWithStrVal(IDENTIFIER, (yyvsp[(1) - (1)].strval));
                ;}
    break;

  case 53:
#line 365 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(INTEGER, (yyvsp[(1) - (1)].value));
                ;}
    break;

  case 54:
#line 369 "src/parser.y"
    {
                    (yyval.node) = maketreeWithVal(CHAR_NODE, (yyvsp[(1) - (1)].value));  // Use CHAR_NODE
                ;}
    break;

  case 56:
#line 376 "src/parser.y"
    {
                    tree* callNode = maketreeWithStrVal(FUNCCALL, (yyvsp[(1) - (3)].strval));
                    (yyval.node) = callNode;
                ;}
    break;

  case 57:
#line 381 "src/parser.y"
    {
                    tree* callNode = maketreeWithStrVal(FUNCCALL, (yyvsp[(1) - (4)].strval));
                    addChild(callNode, (yyvsp[(3) - (4)].node));
                    (yyval.node) = callNode;
                ;}
    break;

  case 58:
#line 389 "src/parser.y"
    {
                    (yyval.node) = maketree(RETURNSTMT);
                ;}
    break;

  case 59:
#line 393 "src/parser.y"
    {
                    tree* returnNode = maketree(RETURNSTMT);
                    addChild(returnNode, (yyvsp[(2) - (3)].node));
                    (yyval.node) = returnNode;
                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 1922 "obj/parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 400 "src/parser.y"


int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}
