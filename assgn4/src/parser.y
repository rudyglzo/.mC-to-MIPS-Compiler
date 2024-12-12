%{
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
%}

/* Precedence declarations */
%left EQ NEQ LT GT LTE GTE
%right ASSIGN
%left ADDOP SUBOP
%left MULOP DIVOP
%nonassoc IFTOKEN
%nonassoc ELSETOKEN

%union
{
    int value;
    struct treenode *node;
    char *strval;
}

/* Token declarations */
%token <strval> ID
%token <value> INTCONST CHARCONST
%token ADDOP SUBOP MULOP DIVOP
%token EQ NEQ LT GT LTE GTE
%token LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE SEMICLN
%token IFTOKEN ELSETOKEN WHILETOKEN RETURN VOID INT CHAR ASSIGN
%token ERROR

/* Non-terminal type declarations */
%type <node> program declList decl varDecl funDecl statement statementList expression addExpr term factor funcCall argList formalDecl formalDeclList compoundStmt condStmt loopStmt returnStmt relExpr
%type <value> typeSpecifier

%start program

%%

program         : declList
                 {
                    tree* progNode = maketree(PROGRAM);
                    addChild(progNode, $1);
                    ast = progNode;
                 }
                ;

declList        : decl
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, $1);
                    $$ = declListNode;
                 }
                | declList decl
                 {
                    addChild($1, $2);
                    $$ = $1;
                 }
                ;

decl            : varDecl
                | funDecl
                ;

funDecl         : typeSpecifier ID LPAREN formalDeclList RPAREN compoundStmt
                {
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE_NODE, $1));  // Use TYPE_NODE
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, $2));
                    if ($4) {
                        addChild(funDeclNode, $4);  // Add formalDeclList
                    }
                    if ($6) {
                        addChild(funDeclNode, $6);  // Add compoundStmt
                    }
                    ST_insert($2, "", $1, FUNCTION);
                    $$ = funDeclNode;
                    scope = "";
                }
                | typeSpecifier ID LPAREN RPAREN compoundStmt
                {
                    tree* funDeclNode = maketree(FUNDECL);
                    addChild(funDeclNode, maketreeWithVal(TYPE_NODE, $1));  // Use TYPE_NODE
                    addChild(funDeclNode, maketreeWithStrVal(IDENTIFIER, $2));
                    if ($5) {
                        addChild(funDeclNode, $5);  // Add compoundStmt
                    }
                    ST_insert($2, "", $1, FUNCTION);
                    $$ = funDeclNode;
                    scope = "";
                }
                ;

formalDeclList  : formalDecl
                {
                    tree* formalDeclListNode = maketree(FORMALDECLLIST);
                    addChild(formalDeclListNode, $1);
                    $$ = formalDeclListNode;
                }
                | formalDeclList ',' formalDecl
                {
                    addChild($1, $3);
                    $$ = $1;
                }
                ;

formalDecl      : typeSpecifier ID
                {
                    tree* formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, maketreeWithVal(TYPE_NODE, $1));  // Use TYPE_NODE
                    addChild(formalDeclNode, maketreeWithStrVal(IDENTIFIER, $2));
                    ST_insert($2, scope, $1, SCALAR);
                    $$ = formalDeclNode;
                }
                | typeSpecifier ID LBRACKET RBRACKET
                {
                    tree* formalDeclNode = maketree(FORMALDECL);
                    addChild(formalDeclNode, maketreeWithVal(TYPE_NODE, $1));  // Use TYPE_NODE
                    tree* arrayNode = maketree(ARRAY_NODE);  // Use ARRAY_NODE
                    addChild(arrayNode, maketreeWithStrVal(IDENTIFIER, $2));
                    addChild(formalDeclNode, arrayNode);
                    ST_insert($2, scope, $1, ARRAY);
                    $$ = formalDeclNode;
                }
                ;

varDecl         : typeSpecifier ID SEMICLN
                 {
                    if ($1 == VOID_TYPE) {
                        yyerror("Variable cannot be of type 'void'");
                        $$ = maketree(ERROR_NODE);  // Use ERROR_NODE
                    } else {
                        tree* varDeclNode = maketree(VARDECL);
                        addChild(varDeclNode, maketreeWithStrVal(IDENTIFIER, $2));
                        $$ = varDeclNode;
                        ST_insert($2, scope, $1, SCALAR);
                    }
                 }
                | typeSpecifier ID LBRACKET INTCONST RBRACKET SEMICLN
                 {
                    if ($1 == VOID_TYPE) {
                        yyerror("Array cannot be of type 'void'");
                        $$ = maketree(ERROR_NODE);  // Use ERROR_NODE
                    } else {
                        tree* arrayDeclNode = maketree(VARDECL);
                        addChild(arrayDeclNode, maketreeWithStrVal(IDENTIFIER, $2));
                        $$ = arrayDeclNode;
                        ST_insert($2, scope, $1, ARRAY);
                    }
                 }
                ;

typeSpecifier   : INT { $$ = INT_TYPE; }
                | CHAR { $$ = CHAR_TYPE; }
                | VOID { $$ = VOID_TYPE; }
                ;

argList         : expression
                {
                    tree* argListNode = maketree(ARGLIST);
                    addChild(argListNode, $1);
                    $$ = argListNode;
                }
                | argList ',' expression
                {
                    addChild($1, $3);
                    $$ = $1;
                }
                ;

compoundStmt    : LBRACE statementList RBRACE
                {
                    tree* compNode = maketree(COMPOUNDSTMT);
                    if ($2) {
                        addChild(compNode, $2);  // Add statementList if it exists
                    }
                    $$ = compNode;
                }
                | LBRACE RBRACE
                {
                    $$ = maketree(COMPOUNDSTMT);
                }
                ;

statementList   : statement
                {
                    tree* stmtListNode = maketree(STMTLIST);
                    if ($1) {
                        addChild(stmtListNode, $1);
                    }
                    $$ = stmtListNode;
                }
                | statementList statement
                {
                    if ($2) {
                        addChild($1, $2);
                    }
                    $$ = $1;
                }
                ;

statement       : expression SEMICLN
                | compoundStmt
                | condStmt
                | loopStmt
                | returnStmt
                | varDecl
                | SEMICLN
                {
                    $$ = NULL;
                }
                ;

expression      : ID ASSIGN expression
                {
                    if (ST_lookup($1, scope) == -1 && ST_lookup($1, "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, $1);
                    }
                    tree* assgnNode = maketree(ASSIGNSTMT);
                    addChild(assgnNode, maketreeWithStrVal(IDENTIFIER, $1));
                    addChild(assgnNode, $3);
                    $$ = assgnNode;
                }
                | addExpr
                | relExpr
                | funcCall
                ;

relExpr
    : expression LT expression
      {
          tree* relNode = maketree(LT_NODE);  // Use LT_NODE
          addChild(relNode, $1);
          addChild(relNode, $3);
          $$ = relNode;
      }
    | expression GT expression
      {
          tree* relNode = maketree(GT_NODE);  // Use GT_NODE
          addChild(relNode, $1);
          addChild(relNode, $3);
          $$ = relNode;
      }
    | expression EQ expression
      {
          tree* relNode = maketree(EQ_NODE);  // Use EQ_NODE
          addChild(relNode, $1);
          addChild(relNode, $3);
          $$ = relNode;
      }
    | expression NEQ expression
      {
          tree* relNode = maketree(NEQ_NODE);  // Use NEQ_NODE
          addChild(relNode, $1);
          addChild(relNode, $3);
          $$ = relNode;
      }
    | expression LTE expression
      {
          tree* relNode = maketree(LTE_NODE);  // Use LTE_NODE
          addChild(relNode, $1);
          addChild(relNode, $3);
          $$ = relNode;
      }
    | expression GTE expression
      {
          tree* relNode = maketree(GTE_NODE);  // Use GTE_NODE
          addChild(relNode, $1);
          addChild(relNode, $3);
          $$ = relNode;
      }
    ;

loopStmt        : WHILETOKEN LPAREN expression RPAREN statement
                {
                    tree* whileNode = maketree(WHILESTMT);
                    addChild(whileNode, $3);
                    addChild(whileNode, $5);
                    $$ = whileNode;
                }
                ;

condStmt        : IFTOKEN LPAREN expression RPAREN statement
                {
                    tree* ifNode = maketree(IFSTMT);
                    addChild(ifNode, $3);
                    addChild(ifNode, $5);
                    $$ = ifNode;
                }
                | IFTOKEN LPAREN expression RPAREN statement ELSETOKEN statement
                {
                    tree* ifElseNode = maketree(IFSTMT);
                    addChild(ifElseNode, $3);
                    addChild(ifElseNode, $5);
                    addChild(ifElseNode, $7);
                    $$ = ifElseNode;
                }
                ;

addExpr
    : addExpr ADDOP term
      {
          tree* addExprNode = maketree(ADDOP_NODE);  // Use ADDOP_NODE
          addChild(addExprNode, $1);
          addChild(addExprNode, $3);
          $$ = addExprNode;
      }
    | addExpr SUBOP term
      {
          tree* subExprNode = maketree(SUBOP_NODE);  // Use SUBOP_NODE
          addChild(subExprNode, $1);
          addChild(subExprNode, $3);
          $$ = subExprNode;
      }
    | term
    ;

term            : term MULOP factor
                {
                    tree* mulExprNode = maketree(MULOP_NODE);  // Use MULOP_NODE
                    addChild(mulExprNode, $1);
                    addChild(mulExprNode, $3);
                    $$ = mulExprNode;
                }
                | term DIVOP factor
                {
                    tree* divExprNode = maketree(DIVOP_NODE);  // Use DIVOP_NODE
                    addChild(divExprNode, $1);
                    addChild(divExprNode, $3);
                    $$ = divExprNode;
                }
                | factor
                ;

factor          : LPAREN expression RPAREN
                {
                    $$ = $2;
                }
                | ID LBRACKET expression RBRACKET
                {
                    if (ST_lookup($1, scope) == -1 && ST_lookup($1, "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, $1);
                    }
                    tree* arrayNode = maketree(ARRAY_ACCESS);
                    addChild(arrayNode, maketreeWithStrVal(IDENTIFIER, $1));
                    addChild(arrayNode, $3);
                    $$ = arrayNode;
                }
                | ID
                {
                    if (ST_lookup($1, scope) == -1 && ST_lookup($1, "") == -1) {
                        printf("warning: line %d: '%s' undeclared (first use in this function)\n", yylineno, $1);
                    }
                    $$ = maketreeWithStrVal(IDENTIFIER, $1);
                }
                | INTCONST
                {
                    $$ = maketreeWithVal(INTEGER, $1);
                }
                | CHARCONST
                {
                    $$ = maketreeWithVal(CHAR_NODE, $1);  // Use CHAR_NODE
                }
                | funcCall
                ;

funcCall        : ID LPAREN RPAREN
                {
                    tree* callNode = maketreeWithStrVal(FUNCCALL, $1);
                    $$ = callNode;
                }
                | ID LPAREN argList RPAREN
                {
                    tree* callNode = maketreeWithStrVal(FUNCCALL, $1);
                    addChild(callNode, $3);
                    $$ = callNode;
                }
                ;

returnStmt      : RETURN SEMICLN
                {
                    $$ = maketree(RETURNSTMT);
                }
                | RETURN expression SEMICLN
                {
                    tree* returnNode = maketree(RETURNSTMT);
                    addChild(returnNode, $2);
                    $$ = returnNode;
                }
                ;

%%

int yywarning(char * msg){
    printf("warning: line %d: %s\n", yylineno, msg);
    return 0;
}

int yyerror(char * msg){
    printf("error: line %d: %s\n", yylineno, msg);
    return 0;
}