/* major stuff */
#define ID         251
#define INTCONST   252
#define CHARCONST  253
#define STRCONST   254
#define ERROR      300        // Added for error handling
#define ILLEGAL_TOK 301        // Added for illegal tokens

/* keywords */
#define KWD_IF     255
#define KWD_ELSE   256
#define KWD_WHILE  257
#define KWD_INT    258
#define KWD_STRING 259
#define KWD_CHAR   260
#define KWD_RETURN 261
#define KWD_VOID   262

/* operators */
#define OPER_ADD    263
#define OPER_SUB    264
#define OPER_MUL    265
#define OPER_DIV    266
#define OPER_LT     267
#define OPER_GT     268
#define OPER_GTE    269
#define OPER_LTE    270
#define OPER_EQ     271
#define OPER_NEQ    272
#define OPER_ASGN   273
#define OPER_INC    274       // Added for increment (++)
#define OPER_DEC    275       // Added for decrement (--)
#define OPER_AND    276       // Added for logical AND (&&)
#define OPER_OR     277       // Added for logical OR (||)
#define OPER_NOT    278       // Added for logical NOT (!)
#define OPER_MOD    279       // Added for modulus (%)
#define OPER_AT     280       // Added if @ is used

/* brackets & parens */
#define LSQ_BRKT    281
#define RSQ_BRKT    282
#define LCRLY_BRKT  283
#define RCRLY_BRKT  284
#define LPAREN      285
#define RPAREN      286

/* punctuation */
#define COMMA      287
#define SEMICLN    288
