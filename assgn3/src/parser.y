%{
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

%}

%union {
    int value;      // For integer constants
    char* strval;   // For identifiers
    tree* node;     // For AST nodes
}

/* Token Declarations */
%token <value> INTCONST CHARCONST
%token <strval> ID

/* Keywords */
%token KWD_IF KWD_ELSE KWD_WHILE KWD_INT KWD_CHAR KWD_RETURN KWD_VOID

/* Operators */
%token OPER_ADD OPER_SUB OPER_MUL OPER_DIV
%token OPER_LT OPER_GT OPER_LTE OPER_GTE OPER_EQ OPER_NEQ
%token OPER_ASGN

/* Punctuation */
%token LPAREN RPAREN LSQ_BRKT RSQ_BRKT LCRLY_BRKT RCRLY_BRKT
%token COMMA SEMICLN

/* Error token */
%token ERROR ILLEGAL_TOK

/* Non-terminal types */
%type <node> program declList decl varDecl funDecl typeSpec
%type <node> formalDeclList formalDecl funBody localDeclList
%type <node> stmtList stmt compoundStmt assignStmt condStmt
%type <node> loopStmt returnStmt expression relop addExpr
%type <node> addop term mulop factor funcCallExpr argList var
%type <value> arrayDecl

/* Operator precedence */
%left OPER_LT OPER_GT OPER_LTE OPER_GTE OPER_EQ OPER_NEQ
%left OPER_ADD OPER_SUB
%left OPER_MUL OPER_DIV

%%

program : declList
        {
            ast = maketree(PROGRAM_NODE);
            addChild(ast, $1);
        }
        ;

declList        : declList decl
                {
                    $$ = $1;
                    addChild($$, $2);
                }
                | decl
                {
                    $$ = maketree(DECL_LIST_NODE);
                    addChild($$, $1);
                }
                ;

decl            : varDecl
                {
                    $$ = $1;
                }
                | funDecl
                {
                    $$ = $1;
                }
                ;

varDecl : typeSpec ID arrayDecl SEMICLN
        {
            $$ = maketree(VAR_DECL_NODE);
            addChild($$, $1);
            int scope;

            if (current_type == VOID_TYPE) {
                report_error("Cannot declare void variable");
                free($2);
                YYERROR;
            }

            if ($3 == 0) { // Regular variable
                if (ST_insert($2, current_type, SCALAR, &scope) != -1) {
                    addChild($$, maketreeWithVal(ID_NODE, scope));
                }
            } else if ($3 > 0) { // Valid array size
                if (ST_insert($2, current_type, ARRAY, &scope) != -1) {
                    tree* id_node = maketreeWithVal(ID_NODE, scope);
                    id_node->array_size = $3;
                    addChild($$, id_node);
                    
                    // Set array size in symbol table
                    symEntry* entry = current_scope->strTable[scope];
                    if (entry) entry->size = $3;
                }
            } else { // Invalid array size (zero or negative)
                report_error("Array variable declared with size of zero");
                if (ST_insert($2, current_type, ARRAY, &scope) != -1) {
                    tree* id_node = maketreeWithVal(ID_NODE, scope);
                    id_node->array_size = 0;
                    addChild($$, id_node);
                }
            }
            free($2);
        }
        ;

typeSpec        : KWD_INT
                {
                    $$ = maketreeWithVal(TYPE_SPEC_NODE, INT_TYPE);
                    current_type = INT_TYPE;
                }
                | KWD_CHAR
                {
                    $$ = maketreeWithVal(TYPE_SPEC_NODE, CHAR_TYPE);
                    current_type = CHAR_TYPE;
                }
                | KWD_VOID
                {
                    $$ = maketreeWithVal(TYPE_SPEC_NODE, VOID_TYPE);
                    current_type = VOID_TYPE;
                }
                ;

arrayDecl : LSQ_BRKT INTCONST RSQ_BRKT
    {
        if ($2 <= 0) {
            $$ = -1;  // Just mark as invalid, don't report here
        } else {
            $$ = $2;
        }
    }
    | LSQ_BRKT RSQ_BRKT  // For parameter arrays without size
    {
        $$ = -1;  // Special marker for unsized arrays
    }
    | /* empty */
    {
        $$ = 0;  // Not an array
    }
    ;

formalDeclList  : formalDeclList COMMA formalDecl
                {
                    $$ = $1;
                    addChild($$, $3);
                }
                | formalDecl
                {
                    $$ = maketree(FORMAL_DECL_LIST_NODE);
                    addChild($$, $1);
                }
                | /* empty */
                {
                    $$ = maketree(FORMAL_DECL_LIST_NODE);
                }
                ;

formalDecl: typeSpec ID arrayDecl
    {
        $$ = maketree(FORMAL_DECL_NODE);
        addChild($$, $1);
        int scope;
        if ($3 != 0) {  // Array parameter (both sized and unsized)
            if (ST_insert($2, current_type, ARRAY, &scope) == -1) {
                yyerror("Formal parameter array declaration failed");
            }
            tree* id_node = maketreeWithVal(ID_NODE, scope);
            id_node->array_size = $3;
            addChild($$, id_node);
            add_param(current_type, ARRAY);
        } else {  // Scalar parameter
            if (current_type == VOID_TYPE) {
                report_error("Cannot have void parameter");
                YYERROR;
            }
            if (ST_insert($2, current_type, SCALAR, &scope) == -1) {
                yyerror("Formal parameter declaration failed");
            }
            addChild($$, maketreeWithVal(ID_NODE, scope));
            add_param(current_type, SCALAR);
        }
        free($2);
    }
    ;

funDecl         : typeSpec ID LPAREN formalDeclList RPAREN funBody
                {
                    $$ = maketree(FUNC_DECL_NODE);
                    addChild($$, $1);  // Add type specifier

                    int scope;
                    if (ST_insert($2, current_type, FUNCTION, &scope) == -1) {
                        yyerror("Function declaration failed");
                    } else {
                        tree* id_node = maketreeWithVal(ID_NODE, scope);
                        addChild($$, id_node);
                    }

                    current_func = strdup($2);
                    new_scope($2);

                    addChild($$, $4);  // Add formal declarations
                    addChild($$, $6);  // Add function body

                    up_scope();
                    free(current_func);
                    current_func = NULL;
                    free($2);
                }
                ;

funBody         : LCRLY_BRKT localDeclList stmtList RCRLY_BRKT
                {
                    $$ = maketree(FUNC_BODY_NODE);
                    addChild($$, $2);
                    addChild($$, $3);
                }
                ;

localDeclList   : localDeclList varDecl
                {
                    $$ = $1;
                    addChild($$, $2);
                }
                | /* empty */
                {
                    $$ = maketree(LOCAL_DECL_LIST_NODE);
                }
                ;

stmtList        : stmtList stmt
                {
                    $$ = $1;
                    addChild($$, $2);
                }
                | /* empty */
                {
                    $$ = maketree(STMT_LIST_NODE);
                }
                ;

stmt : assignStmt
     {
         $$ = $1;
     }
     | compoundStmt 
     {
         $$ = $1;
     }
     | condStmt
     {
         $$ = $1;
     }
     | loopStmt
     {
         $$ = $1;
     }
     | returnStmt
     {
         $$ = $1;
     }
     | error SEMICLN
     {
         $$ = maketree(STMT_NODE);
         yyerrok;
     }
     ;

compoundStmt    : LCRLY_BRKT
                {
                    new_scope("compound");
                }
                stmtList RCRLY_BRKT
                {
                    $$ = maketree(COMPOUND_STMT_NODE);
                    addChild($$, $3);
                    up_scope();
                }
                ;

assignStmt: var OPER_ASGN expression SEMICLN
    {
        $$ = maketree(ASSIGN_STMT_NODE);
        addChild($$, $1);
        addChild($$, $3);
        
        if (!is_type_compatible($1->type, $3->type)) {
            report_error("Type mismatch in assignment");
        }
    }
    ;

condStmt        : KWD_IF LPAREN expression RPAREN stmt
                {
                    $$ = maketree(COND_STMT_NODE);
                    addChild($$, $3);
                    addChild($$, $5);
                }
                | KWD_IF LPAREN expression RPAREN stmt KWD_ELSE stmt
                {
                    $$ = maketree(COND_STMT_NODE);
                    addChild($$, $3);
                    addChild($$, $5);
                    addChild($$, $7);
                }
                ;

loopStmt        : KWD_WHILE
                {
                    in_loop++;
                }
                LPAREN expression RPAREN stmt
                {
                    $$ = maketree(LOOP_STMT_NODE);
                    addChild($$, $4);
                    addChild($$, $6);
                    in_loop--;
                }
                ;

returnStmt      : KWD_RETURN SEMICLN
                {
                    $$ = maketree(RETURN_STMT_NODE);
                    // Check if void return type matches function
                    symEntry* func = ST_lookup(current_func);
                    if (func && func->data_type != VOID_TYPE) {
                        yyerror("Non-void function must return a value");
                    }
                }
                | KWD_RETURN expression SEMICLN
                {
                    $$ = maketree(RETURN_STMT_NODE);
                    addChild($$, $2);
                    // Check if return type matches function
                    symEntry* func = ST_lookup(current_func);
                    if (func && !is_type_compatible(func->data_type, $2->type)) {
                        yyerror("Return type mismatch");
                    }
                }
                ;

expression : addExpr
          | addExpr relop addExpr
          {
              $$ = maketree(EXPR_NODE);
              addChild($$, $1);
              addChild($$, $2);
              addChild($$, $3);

              // Type checking for relational operations
              if (!is_type_compatible($1->type, $3->type)) {
                  yyerror("Type mismatch in relational expression");
              }
              if ($$->type == VOID_TYPE) {
                  yyerror("Invalid expression of type void");
              }
              $$->type = $1->type;
          }
          ;

relop           : OPER_LTE { $$ = maketreeWithVal(RELOP_NODE, 4); }
                | OPER_LT  { $$ = maketreeWithVal(RELOP_NODE, 0); }
                | OPER_GT  { $$ = maketreeWithVal(RELOP_NODE, 1); }
                | OPER_GTE { $$ = maketreeWithVal(RELOP_NODE, 5); }
                | OPER_EQ  { $$ = maketreeWithVal(RELOP_NODE, 2); }
                | OPER_NEQ { $$ = maketreeWithVal(RELOP_NODE, 3); }
                ;

addExpr         : term
                | addExpr addop term
                {
                    $$ = maketree(ADD_EXPR_NODE);
                    addChild($$, $1);
                    addChild($$, $2);
                    addChild($$, $3);

                    // Type checking for arithmetic operations
                    if (!is_type_compatible($1->type, $3->type)) {
                        yyerror("Type mismatch in arithmetic expression");
                    }
                    $$->type = $1->type;
                }
                ;

addop           : OPER_ADD { $$ = maketreeWithVal(ADDOP_NODE, 0); }
                | OPER_SUB { $$ = maketreeWithVal(ADDOP_NODE, 1); }
                ;

term            : factor
                | term mulop factor
                {
                    $$ = maketree(TERM_NODE);
                    addChild($$, $1);
                    addChild($$, $2);
                    addChild($$, $3);

                    // Type checking for arithmetic operations
                    if (!is_type_compatible($1->type, $3->type)) {
                        yyerror("Type mismatch in arithmetic expression");
                    }
                    $$->type = $1->type;
                }
                ;

mulop           : OPER_MUL { $$ = maketreeWithVal(MULOP_NODE, 0); }
                | OPER_DIV { $$ = maketreeWithVal(MULOP_NODE, 1); }
                ;


factor          : LPAREN expression RPAREN
                {
                    $$ = $2;
                }
                | var
                {
                    $$ = $1;
                }
                | funcCallExpr
                {
                    $$ = $1;
                }
                | INTCONST
                {
                    char str[32];
                    snprintf(str, sizeof(str), "%d", $1);
                    if (!isValidIntegerConstant(str)) {
                        report_error("Integer constant out of bounds");
                        $$ = maketreeWithVal(INT_CONST_NODE, 0);
                    } else {
                        $$ = maketreeWithVal(INT_CONST_NODE, $1);
                    }
                    $$->type = INT_TYPE;
                }
                | CHARCONST
                {
                    $$ = maketreeWithVal(CHAR_CONST_NODE, $1);
                    $$->type = CHAR_TYPE;
                }
                ;

var : ID LSQ_BRKT expression RSQ_BRKT
    {
        symEntry* entry = ST_lookup($1);
        if (!entry) {
            report_error("Undeclared variable");
            $$ = maketreeWithVal(VAR_NODE, -1);
        } else {
            $$ = maketreeWithVal(VAR_NODE, hash($1));
            $$->type = entry->data_type;
            
            // Check if variable is an array
            if (entry->symbol_type != ARRAY) {
                report_error("Non-array identifier used as an array");
            } else {
                // Check array index type
                if ($3->nodeKind == CHAR_CONST_NODE || 
                    $3->type == CHAR_TYPE) {
                    report_error("Array indexed using non-integer expression");
                }
                // Check bounds for constant indices
                else if ($3->nodeKind == INT_CONST_NODE && entry->size > 0) {
                    if ($3->val < 0 || $3->val >= entry->size) {
                        report_error("Statically sized array indexed with constant, out-of-bounds expression");
                    }
                }
            }
            addChild($$, $3);
        }
        free($1);
    }
    ;

funcCallExpr: ID LPAREN argList RPAREN
    {
        symEntry* entry = ST_lookup($1);
        if (!entry) {
            report_error("Undefined function");
            $$ = maketreeWithVal(FUNC_CALL_NODE, -1);
        } else {
            $$ = maketree(FUNC_CALL_NODE);
            addChild($$, maketreeWithVal(ID_NODE, hash($1)));
            addChild($$, $3);
            
            int expected = get_param_count($1);
            int actual = count_args($3);
            
            if (actual < expected) {
                report_error("Too few arguments provided in function call");
            } else if (actual > expected) {
                report_error("Too many arguments provided in function call");
            }

            // Check argument types
            param* formal = get_param_list($1);
            for (int i = 0; i < actual && formal; i++) {
                tree* arg = getChild($3, i);
                if (!check_arg_type(formal, arg)) {
                    report_error("Argument type mismatch in function call");
                }
                formal = formal->next;
            }
            $$->type = entry->data_type;
        }
        free($1);
    }
    ;

argList         : argList COMMA expression
                {
                    $$ = $1;
                    addChild($$, $3);
                }
                | expression
                {
                    $$ = maketree(ARG_LIST_NODE);
                    addChild($$, $1);
                }
                | /* empty */
                {
                    $$ = maketree(ARG_LIST_NODE);
                }
                ;
%%

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
