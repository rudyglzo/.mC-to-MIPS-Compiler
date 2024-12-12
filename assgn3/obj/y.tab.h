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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int value;      /* For integer constants*/
    char* strval;   /* For identifiers*/
    tree* node;     /* For AST nodes*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
