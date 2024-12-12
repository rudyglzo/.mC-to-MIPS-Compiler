/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 2
#define YYMINOR 0
#define YYPATCH 20210109

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "src/parser.y"
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

/* Global variables*/
tree* ast = NULL;  /* AST root*/
int current_type;  /* Track current declaration type*/
int in_loop = 0;   /* Track if we're in a loop*/
char* current_func = NULL;  /* Track current function for return type checking*/

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 25 "src/parser.y"
typedef union {
    int value;      /* For integer constants*/
    char* strval;   /* For identifiers*/
    tree* node;     /* For AST nodes*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "obj/y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INTCONST 257
#define CHARCONST 258
#define ID 259
#define KWD_IF 260
#define KWD_ELSE 261
#define KWD_WHILE 262
#define KWD_INT 263
#define KWD_CHAR 264
#define KWD_RETURN 265
#define KWD_VOID 266
#define OPER_ADD 267
#define OPER_SUB 268
#define OPER_MUL 269
#define OPER_DIV 270
#define OPER_LT 271
#define OPER_GT 272
#define OPER_LTE 273
#define OPER_GTE 274
#define OPER_EQ 275
#define OPER_NEQ 276
#define OPER_ASGN 277
#define LPAREN 278
#define RPAREN 279
#define LSQ_BRKT 280
#define RSQ_BRKT 281
#define LCRLY_BRKT 282
#define RCRLY_BRKT 283
#define COMMA 284
#define SEMICLN 285
#define ERROR 286
#define ILLEGAL_TOK 287
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    2,    3,    5,    5,    5,   27,
   27,   27,    6,    6,    6,    7,    4,    8,    9,    9,
   10,   10,   11,   11,   11,   11,   11,   11,   28,   12,
   13,   14,   14,   29,   15,   16,   16,   17,   17,   18,
   18,   18,   18,   18,   18,   19,   19,   20,   20,   21,
   21,   22,   22,   23,   23,   23,   23,   23,   26,   24,
   25,   25,   25,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    1,    1,    4,    1,    1,    1,    3,
    2,    0,    3,    1,    0,    3,    6,    4,    2,    0,
    2,    0,    1,    1,    1,    1,    1,    2,    0,    4,
    4,    5,    7,    0,    6,    2,    3,    1,    3,    1,
    1,    1,    1,    1,    1,    1,    3,    1,    1,    1,
    3,    1,    1,    3,    1,    1,    1,    1,    4,    4,
    3,    1,    0,
};
static const YYINT yydefred[] = {                         0,
    7,    8,    9,    0,    0,    3,    4,    5,    0,    2,
    0,    0,    0,    0,    0,    0,   14,    0,   11,    6,
    0,    0,    0,   10,   16,   20,   17,   13,    0,   19,
    0,    0,    0,    0,    0,    0,   34,    0,   29,   18,
   21,   24,   23,   25,   26,   27,    0,   28,    0,    0,
    0,   57,   58,    0,    0,   36,    0,    0,    0,   50,
   56,   55,   22,    0,    0,    0,    0,    0,    0,   37,
   48,   49,   41,   42,   40,   43,   44,   45,    0,    0,
   52,   53,    0,    0,    0,   59,    0,    0,   62,    0,
   54,    0,    0,   51,   30,   31,    0,    0,   60,    0,
    0,   35,   61,   33,
};
static const YYINT yydgoto[] = {                          4,
    5,    6,    7,    8,    9,   16,   17,   27,   29,   32,
   41,   42,   43,   44,   45,   46,   57,   79,   58,   80,
   59,   83,   60,   61,   90,   62,   14,   63,   51,
};
static const YYINT yysindex[] = {                      -236,
    0,    0,    0,    0, -236,    0,    0,    0, -258,    0,
 -222, -236, -245, -259, -244, -270,    0, -250,    0,    0,
 -233, -232, -236,    0,    0,    0,    0,    0, -236,    0,
 -202, -249, -233, -210, -217, -193,    0, -253,    0,    0,
    0,    0,    0,    0,    0,    0, -181,    0, -235, -235,
 -186,    0,    0, -185, -235,    0, -178, -140, -251,    0,
    0,    0,    0, -235, -173, -180, -235, -235, -169,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -235, -235,
    0,    0, -235, -221, -163,    0, -182, -156,    0, -242,
    0, -208, -251,    0,    0,    0, -136, -182,    0, -235,
 -182,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,  138,    0,    0,    0,    0,    0,
 -144, -198,    0,    0,    0,    0,    0,    0,    0,    0,
 -190,    0,    0,    0,    0,    0,    0,    0, -211,    0,
    0,    0, -144,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -197, -170,    0,
    0,    0,    0,    0,    0,    0,    0, -139,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -142, -155,    0,    0,    0, -192,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  139,  117,    0,   17,    0,  124,    0,    0,   85,
  -22,    0,    0,    0,    0,    0,  -47,    0,   70,    0,
   71,    0,   67,    0,    0,  -32,  131,    0,    0,
};
#define YYTABLESIZE 152
static const YYINT yytable[] = {                         47,
   11,   65,   66,   52,   53,   54,   34,   69,   22,   35,
   36,   18,   37,   23,   21,   38,   85,   81,   82,   88,
   89,   52,   53,   54,   55,   20,    1,    2,   15,    3,
   24,   56,   39,   40,   34,   19,   99,   35,   36,   15,
   37,  100,   55,   38,   22,   31,   13,   22,   22,   26,
   22,   47,  103,   22,   47,   12,   33,   13,   71,   72,
   39,   95,   49,   32,   97,   47,   32,   32,   47,   32,
   22,   22,   32,   34,   48,  102,   35,   36,  104,   37,
   15,   38,   38,   38,   50,   15,   38,   38,   12,   32,
   32,   67,   68,   12,   49,   64,   46,   46,   87,   39,
   46,   46,   46,   46,   46,   46,   70,   86,   46,   91,
   46,   47,   47,   46,   46,   47,   47,   47,   47,   47,
   47,   96,   98,   47,  101,   47,   71,   72,   47,   47,
   73,   74,   75,   76,   77,   78,   39,    1,   39,   63,
   12,   39,   39,   10,   63,   30,   28,   84,   92,   94,
   93,   25,
};
static const YYINT yycheck[] = {                         32,
  259,   49,   50,  257,  258,  259,  256,   55,  279,  259,
  260,  257,  262,  284,  259,  265,   64,  269,  270,   67,
   68,  257,  258,  259,  278,  285,  263,  264,   12,  266,
  281,  285,  282,  283,  256,  281,  279,  259,  260,   23,
  262,  284,  278,  265,  256,   29,  280,  259,  260,  282,
  262,   84,  100,  265,   87,  278,  259,  280,  267,  268,
  282,  283,  280,  256,   87,   98,  259,  260,  101,  262,
  282,  283,  265,  256,  285,   98,  259,  260,  101,  262,
  279,  279,  265,  281,  278,  284,  284,  285,  279,  282,
  283,  278,  278,  284,  280,  277,  267,  268,  279,  282,
  271,  272,  273,  274,  275,  276,  285,  281,  279,  279,
  281,  267,  268,  284,  285,  271,  272,  273,  274,  275,
  276,  285,  279,  279,  261,  281,  267,  268,  284,  285,
  271,  272,  273,  274,  275,  276,  279,    0,  281,  279,
  285,  284,  285,    5,  284,   29,   23,   63,   79,   83,
   80,   21,
};
#define YYFINAL 4
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 287
#define YYUNDFTOKEN 319
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INTCONST","CHARCONST","ID",
"KWD_IF","KWD_ELSE","KWD_WHILE","KWD_INT","KWD_CHAR","KWD_RETURN","KWD_VOID",
"OPER_ADD","OPER_SUB","OPER_MUL","OPER_DIV","OPER_LT","OPER_GT","OPER_LTE",
"OPER_GTE","OPER_EQ","OPER_NEQ","OPER_ASGN","LPAREN","RPAREN","LSQ_BRKT",
"RSQ_BRKT","LCRLY_BRKT","RCRLY_BRKT","COMMA","SEMICLN","ERROR","ILLEGAL_TOK",0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : declList",
"declList : declList decl",
"declList : decl",
"decl : varDecl",
"decl : funDecl",
"varDecl : typeSpec ID arrayDecl SEMICLN",
"typeSpec : KWD_INT",
"typeSpec : KWD_CHAR",
"typeSpec : KWD_VOID",
"arrayDecl : LSQ_BRKT INTCONST RSQ_BRKT",
"arrayDecl : LSQ_BRKT RSQ_BRKT",
"arrayDecl :",
"formalDeclList : formalDeclList COMMA formalDecl",
"formalDeclList : formalDecl",
"formalDeclList :",
"formalDecl : typeSpec ID arrayDecl",
"funDecl : typeSpec ID LPAREN formalDeclList RPAREN funBody",
"funBody : LCRLY_BRKT localDeclList stmtList RCRLY_BRKT",
"localDeclList : localDeclList varDecl",
"localDeclList :",
"stmtList : stmtList stmt",
"stmtList :",
"stmt : assignStmt",
"stmt : compoundStmt",
"stmt : condStmt",
"stmt : loopStmt",
"stmt : returnStmt",
"stmt : error SEMICLN",
"$$1 :",
"compoundStmt : LCRLY_BRKT $$1 stmtList RCRLY_BRKT",
"assignStmt : var OPER_ASGN expression SEMICLN",
"condStmt : KWD_IF LPAREN expression RPAREN stmt",
"condStmt : KWD_IF LPAREN expression RPAREN stmt KWD_ELSE stmt",
"$$2 :",
"loopStmt : KWD_WHILE $$2 LPAREN expression RPAREN stmt",
"returnStmt : KWD_RETURN SEMICLN",
"returnStmt : KWD_RETURN expression SEMICLN",
"expression : addExpr",
"expression : addExpr relop addExpr",
"relop : OPER_LTE",
"relop : OPER_LT",
"relop : OPER_GT",
"relop : OPER_GTE",
"relop : OPER_EQ",
"relop : OPER_NEQ",
"addExpr : term",
"addExpr : addExpr addop term",
"addop : OPER_ADD",
"addop : OPER_SUB",
"term : factor",
"term : term mulop factor",
"mulop : OPER_MUL",
"mulop : OPER_DIV",
"factor : LPAREN expression RPAREN",
"factor : var",
"factor : funcCallExpr",
"factor : INTCONST",
"factor : CHARCONST",
"var : ID LSQ_BRKT expression RSQ_BRKT",
"funcCallExpr : ID LPAREN argList RPAREN",
"argList : argList COMMA expression",
"argList : expression",
"argList :",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 549 "src/parser.y"

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
#line 381 "obj/y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 1:
#line 66 "src/parser.y"
	{
            ast = maketree(PROGRAM_NODE);
            addChild(ast, yystack.l_mark[0].node);
        }
break;
case 2:
#line 73 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[-1].node;
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 3:
#line 78 "src/parser.y"
	{
                    yyval.node = maketree(DECL_LIST_NODE);
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 4:
#line 85 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[0].node;
                }
break;
case 5:
#line 89 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[0].node;
                }
break;
case 6:
#line 95 "src/parser.y"
	{
            yyval.node = maketree(VAR_DECL_NODE);
            addChild(yyval.node, yystack.l_mark[-3].node);
            int scope;

            if (current_type == VOID_TYPE) {
                report_error("Cannot declare void variable");
                free(yystack.l_mark[-2].strval);
                YYERROR;
            }

            if (yystack.l_mark[-1].value == 0) { /* Regular variable*/
                if (ST_insert(yystack.l_mark[-2].strval, current_type, SCALAR, &scope) != -1) {
                    addChild(yyval.node, maketreeWithVal(ID_NODE, scope));
                }
            } else if (yystack.l_mark[-1].value > 0) { /* Valid array size*/
                if (ST_insert(yystack.l_mark[-2].strval, current_type, ARRAY, &scope) != -1) {
                    tree* id_node = maketreeWithVal(ID_NODE, scope);
                    id_node->array_size = yystack.l_mark[-1].value;
                    addChild(yyval.node, id_node);
                    
                    /* Set array size in symbol table*/
                    symEntry* entry = current_scope->strTable[scope];
                    if (entry) entry->size = yystack.l_mark[-1].value;
                }
            } else { /* Invalid array size (zero or negative)*/
                report_error("Array variable declared with size of zero");
                if (ST_insert(yystack.l_mark[-2].strval, current_type, ARRAY, &scope) != -1) {
                    tree* id_node = maketreeWithVal(ID_NODE, scope);
                    id_node->array_size = 0;
                    addChild(yyval.node, id_node);
                }
            }
            free(yystack.l_mark[-2].strval);
        }
break;
case 7:
#line 133 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(TYPE_SPEC_NODE, INT_TYPE);
                    current_type = INT_TYPE;
                }
break;
case 8:
#line 138 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(TYPE_SPEC_NODE, CHAR_TYPE);
                    current_type = CHAR_TYPE;
                }
break;
case 9:
#line 143 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(TYPE_SPEC_NODE, VOID_TYPE);
                    current_type = VOID_TYPE;
                }
break;
case 10:
#line 150 "src/parser.y"
	{
        if (yystack.l_mark[-1].value <= 0) {
            yyval.value = -1;  /* Just mark as invalid, don't report here*/
        } else {
            yyval.value = yystack.l_mark[-1].value;
        }
    }
break;
case 11:
#line 158 "src/parser.y"
	{
        yyval.value = -1;  /* Special marker for unsized arrays*/
    }
break;
case 12:
#line 162 "src/parser.y"
	{
        yyval.value = 0;  /* Not an array*/
    }
break;
case 13:
#line 168 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[-2].node;
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 14:
#line 173 "src/parser.y"
	{
                    yyval.node = maketree(FORMAL_DECL_LIST_NODE);
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 15:
#line 178 "src/parser.y"
	{
                    yyval.node = maketree(FORMAL_DECL_LIST_NODE);
                }
break;
case 16:
#line 184 "src/parser.y"
	{
        yyval.node = maketree(FORMAL_DECL_NODE);
        addChild(yyval.node, yystack.l_mark[-2].node);
        int scope;
        if (yystack.l_mark[0].value != 0) {  /* Array parameter (both sized and unsized)*/
            if (ST_insert(yystack.l_mark[-1].strval, current_type, ARRAY, &scope) == -1) {
                yyerror("Formal parameter array declaration failed");
            }
            tree* id_node = maketreeWithVal(ID_NODE, scope);
            id_node->array_size = yystack.l_mark[0].value;
            addChild(yyval.node, id_node);
            add_param(current_type, ARRAY);
        } else {  /* Scalar parameter*/
            if (current_type == VOID_TYPE) {
                report_error("Cannot have void parameter");
                YYERROR;
            }
            if (ST_insert(yystack.l_mark[-1].strval, current_type, SCALAR, &scope) == -1) {
                yyerror("Formal parameter declaration failed");
            }
            addChild(yyval.node, maketreeWithVal(ID_NODE, scope));
            add_param(current_type, SCALAR);
        }
        free(yystack.l_mark[-1].strval);
    }
break;
case 17:
#line 212 "src/parser.y"
	{
                    yyval.node = maketree(FUNC_DECL_NODE);
                    addChild(yyval.node, yystack.l_mark[-5].node);  /* Add type specifier*/

                    int scope;
                    if (ST_insert(yystack.l_mark[-4].strval, current_type, FUNCTION, &scope) == -1) {
                        yyerror("Function declaration failed");
                    } else {
                        tree* id_node = maketreeWithVal(ID_NODE, scope);
                        addChild(yyval.node, id_node);
                    }

                    current_func = strdup(yystack.l_mark[-4].strval);
                    new_scope(yystack.l_mark[-4].strval);

                    addChild(yyval.node, yystack.l_mark[-2].node);  /* Add formal declarations*/
                    addChild(yyval.node, yystack.l_mark[0].node);  /* Add function body*/

                    up_scope();
                    free(current_func);
                    current_func = NULL;
                    free(yystack.l_mark[-4].strval);
                }
break;
case 18:
#line 238 "src/parser.y"
	{
                    yyval.node = maketree(FUNC_BODY_NODE);
                    addChild(yyval.node, yystack.l_mark[-2].node);
                    addChild(yyval.node, yystack.l_mark[-1].node);
                }
break;
case 19:
#line 246 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[-1].node;
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 20:
#line 251 "src/parser.y"
	{
                    yyval.node = maketree(LOCAL_DECL_LIST_NODE);
                }
break;
case 21:
#line 257 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[-1].node;
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 22:
#line 262 "src/parser.y"
	{
                    yyval.node = maketree(STMT_LIST_NODE);
                }
break;
case 23:
#line 268 "src/parser.y"
	{
         yyval.node = yystack.l_mark[0].node;
     }
break;
case 24:
#line 272 "src/parser.y"
	{
         yyval.node = yystack.l_mark[0].node;
     }
break;
case 25:
#line 276 "src/parser.y"
	{
         yyval.node = yystack.l_mark[0].node;
     }
break;
case 26:
#line 280 "src/parser.y"
	{
         yyval.node = yystack.l_mark[0].node;
     }
break;
case 27:
#line 284 "src/parser.y"
	{
         yyval.node = yystack.l_mark[0].node;
     }
break;
case 28:
#line 288 "src/parser.y"
	{
         yyval.node = maketree(STMT_NODE);
         yyerrok;
     }
break;
case 29:
#line 295 "src/parser.y"
	{
                    new_scope("compound");
                }
break;
case 30:
#line 299 "src/parser.y"
	{
                    yyval.node = maketree(COMPOUND_STMT_NODE);
                    addChild(yyval.node, yystack.l_mark[-1].node);
                    up_scope();
                }
break;
case 31:
#line 307 "src/parser.y"
	{
        yyval.node = maketree(ASSIGN_STMT_NODE);
        addChild(yyval.node, yystack.l_mark[-3].node);
        addChild(yyval.node, yystack.l_mark[-1].node);
        
        if (!is_type_compatible(yystack.l_mark[-3].node->type, yystack.l_mark[-1].node->type)) {
            report_error("Type mismatch in assignment");
        }
    }
break;
case 32:
#line 319 "src/parser.y"
	{
                    yyval.node = maketree(COND_STMT_NODE);
                    addChild(yyval.node, yystack.l_mark[-2].node);
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 33:
#line 325 "src/parser.y"
	{
                    yyval.node = maketree(COND_STMT_NODE);
                    addChild(yyval.node, yystack.l_mark[-4].node);
                    addChild(yyval.node, yystack.l_mark[-2].node);
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 34:
#line 334 "src/parser.y"
	{
                    in_loop++;
                }
break;
case 35:
#line 338 "src/parser.y"
	{
                    yyval.node = maketree(LOOP_STMT_NODE);
                    addChild(yyval.node, yystack.l_mark[-2].node);
                    addChild(yyval.node, yystack.l_mark[0].node);
                    in_loop--;
                }
break;
case 36:
#line 347 "src/parser.y"
	{
                    yyval.node = maketree(RETURN_STMT_NODE);
                    /* Check if void return type matches function*/
                    symEntry* func = ST_lookup(current_func);
                    if (func && func->data_type != VOID_TYPE) {
                        yyerror("Non-void function must return a value");
                    }
                }
break;
case 37:
#line 356 "src/parser.y"
	{
                    yyval.node = maketree(RETURN_STMT_NODE);
                    addChild(yyval.node, yystack.l_mark[-1].node);
                    /* Check if return type matches function*/
                    symEntry* func = ST_lookup(current_func);
                    if (func && !is_type_compatible(func->data_type, yystack.l_mark[-1].node->type)) {
                        yyerror("Return type mismatch");
                    }
                }
break;
case 39:
#line 369 "src/parser.y"
	{
              yyval.node = maketree(EXPR_NODE);
              addChild(yyval.node, yystack.l_mark[-2].node);
              addChild(yyval.node, yystack.l_mark[-1].node);
              addChild(yyval.node, yystack.l_mark[0].node);

              /* Type checking for relational operations*/
              if (!is_type_compatible(yystack.l_mark[-2].node->type, yystack.l_mark[0].node->type)) {
                  yyerror("Type mismatch in relational expression");
              }
              if (yyval.node->type == VOID_TYPE) {
                  yyerror("Invalid expression of type void");
              }
              yyval.node->type = yystack.l_mark[-2].node->type;
          }
break;
case 40:
#line 386 "src/parser.y"
	{ yyval.node = maketreeWithVal(RELOP_NODE, 4); }
break;
case 41:
#line 387 "src/parser.y"
	{ yyval.node = maketreeWithVal(RELOP_NODE, 0); }
break;
case 42:
#line 388 "src/parser.y"
	{ yyval.node = maketreeWithVal(RELOP_NODE, 1); }
break;
case 43:
#line 389 "src/parser.y"
	{ yyval.node = maketreeWithVal(RELOP_NODE, 5); }
break;
case 44:
#line 390 "src/parser.y"
	{ yyval.node = maketreeWithVal(RELOP_NODE, 2); }
break;
case 45:
#line 391 "src/parser.y"
	{ yyval.node = maketreeWithVal(RELOP_NODE, 3); }
break;
case 47:
#line 396 "src/parser.y"
	{
                    yyval.node = maketree(ADD_EXPR_NODE);
                    addChild(yyval.node, yystack.l_mark[-2].node);
                    addChild(yyval.node, yystack.l_mark[-1].node);
                    addChild(yyval.node, yystack.l_mark[0].node);

                    /* Type checking for arithmetic operations*/
                    if (!is_type_compatible(yystack.l_mark[-2].node->type, yystack.l_mark[0].node->type)) {
                        yyerror("Type mismatch in arithmetic expression");
                    }
                    yyval.node->type = yystack.l_mark[-2].node->type;
                }
break;
case 48:
#line 410 "src/parser.y"
	{ yyval.node = maketreeWithVal(ADDOP_NODE, 0); }
break;
case 49:
#line 411 "src/parser.y"
	{ yyval.node = maketreeWithVal(ADDOP_NODE, 1); }
break;
case 51:
#line 416 "src/parser.y"
	{
                    yyval.node = maketree(TERM_NODE);
                    addChild(yyval.node, yystack.l_mark[-2].node);
                    addChild(yyval.node, yystack.l_mark[-1].node);
                    addChild(yyval.node, yystack.l_mark[0].node);

                    /* Type checking for arithmetic operations*/
                    if (!is_type_compatible(yystack.l_mark[-2].node->type, yystack.l_mark[0].node->type)) {
                        yyerror("Type mismatch in arithmetic expression");
                    }
                    yyval.node->type = yystack.l_mark[-2].node->type;
                }
break;
case 52:
#line 430 "src/parser.y"
	{ yyval.node = maketreeWithVal(MULOP_NODE, 0); }
break;
case 53:
#line 431 "src/parser.y"
	{ yyval.node = maketreeWithVal(MULOP_NODE, 1); }
break;
case 54:
#line 436 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[-1].node;
                }
break;
case 55:
#line 440 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[0].node;
                }
break;
case 56:
#line 444 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[0].node;
                }
break;
case 57:
#line 448 "src/parser.y"
	{
                    char str[32];
                    snprintf(str, sizeof(str), "%d", yystack.l_mark[0].value);
                    if (!isValidIntegerConstant(str)) {
                        report_error("Integer constant out of bounds");
                        yyval.node = maketreeWithVal(INT_CONST_NODE, 0);
                    } else {
                        yyval.node = maketreeWithVal(INT_CONST_NODE, yystack.l_mark[0].value);
                    }
                    yyval.node->type = INT_TYPE;
                }
break;
case 58:
#line 460 "src/parser.y"
	{
                    yyval.node = maketreeWithVal(CHAR_CONST_NODE, yystack.l_mark[0].value);
                    yyval.node->type = CHAR_TYPE;
                }
break;
case 59:
#line 467 "src/parser.y"
	{
        symEntry* entry = ST_lookup(yystack.l_mark[-3].strval);
        if (!entry) {
            report_error("Undeclared variable");
            yyval.node = maketreeWithVal(VAR_NODE, -1);
        } else {
            yyval.node = maketreeWithVal(VAR_NODE, hash(yystack.l_mark[-3].strval));
            yyval.node->type = entry->data_type;
            
            /* Check if variable is an array*/
            if (entry->symbol_type != ARRAY) {
                report_error("Non-array identifier used as an array");
            } else {
                /* Check array index type*/
                if (yystack.l_mark[-1].node->nodeKind == CHAR_CONST_NODE || 
                    yystack.l_mark[-1].node->type == CHAR_TYPE) {
                    report_error("Array indexed using non-integer expression");
                }
                /* Check bounds for constant indices*/
                else if (yystack.l_mark[-1].node->nodeKind == INT_CONST_NODE && entry->size > 0) {
                    if (yystack.l_mark[-1].node->val < 0 || yystack.l_mark[-1].node->val >= entry->size) {
                        report_error("Statically sized array indexed with constant, out-of-bounds expression");
                    }
                }
            }
            addChild(yyval.node, yystack.l_mark[-1].node);
        }
        free(yystack.l_mark[-3].strval);
    }
break;
case 60:
#line 499 "src/parser.y"
	{
        symEntry* entry = ST_lookup(yystack.l_mark[-3].strval);
        if (!entry) {
            report_error("Undefined function");
            yyval.node = maketreeWithVal(FUNC_CALL_NODE, -1);
        } else {
            yyval.node = maketree(FUNC_CALL_NODE);
            addChild(yyval.node, maketreeWithVal(ID_NODE, hash(yystack.l_mark[-3].strval)));
            addChild(yyval.node, yystack.l_mark[-1].node);
            
            int expected = get_param_count(yystack.l_mark[-3].strval);
            int actual = count_args(yystack.l_mark[-1].node);
            
            if (actual < expected) {
                report_error("Too few arguments provided in function call");
            } else if (actual > expected) {
                report_error("Too many arguments provided in function call");
            }

            /* Check argument types*/
            param* formal = get_param_list(yystack.l_mark[-3].strval);
            for (int i = 0; i < actual && formal; i++) {
                tree* arg = getChild(yystack.l_mark[-1].node, i);
                if (!check_arg_type(formal, arg)) {
                    report_error("Argument type mismatch in function call");
                }
                formal = formal->next;
            }
            yyval.node->type = entry->data_type;
        }
        free(yystack.l_mark[-3].strval);
    }
break;
case 61:
#line 534 "src/parser.y"
	{
                    yyval.node = yystack.l_mark[-2].node;
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 62:
#line 539 "src/parser.y"
	{
                    yyval.node = maketree(ARG_LIST_NODE);
                    addChild(yyval.node, yystack.l_mark[0].node);
                }
break;
case 63:
#line 544 "src/parser.y"
	{
                    yyval.node = maketree(ARG_LIST_NODE);
                }
break;
#line 1134 "obj/y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
