%{
#include<stdio.h>
#include <limits.h>
#include "../src/tree.h"
#include"../obj/y.tab.h"

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerrormsg;

void updateCol();
void countLines();
int processChar();
void reportError(char* msg);
%}

newline         \n
whitespace      [ \t]+
integer         0|[1-9][0-9]*
integerlead0    0[0-9]+
character       \'([^\'\n]|\\[\\nt\'])\'
multichar       \'([^\'\n]|\\[\\nt\']){2,}\'
untermchar      \'([^\'\n]|\\[\\nt\'])*\n
illegalchar     \'\\[^\\nt\']\'

/* Enhanced comment patterns */
comment         \/\*([^*]|\*[^\/])*\*\/
untermcomment   \/\*([^*]|\*[^\/])*
multicomment    \/\*([^*]|\*[^\/])*\*\/\n[^\n]*

identifier      [a-zA-Z][a-zA-Z0-9]*
illidentifier   [0-9]+[a-zA-Z][a-zA-Z0-9]*

%%

 /* Keywords */
"if"            {updateCol(); return KWD_IF;}
"else"          {updateCol(); return KWD_ELSE;}
"while"         {updateCol(); return KWD_WHILE;}
"int"           {updateCol(); return KWD_INT;}
"char"          {updateCol(); return KWD_CHAR;}
"return"        {updateCol(); return KWD_RETURN;}
"void"          {updateCol(); return KWD_VOID;}

 /* Operators */
\+              {updateCol(); return OPER_ADD;}
\-              {updateCol(); return OPER_SUB;}
\*              {updateCol(); return OPER_MUL;}
\/              {updateCol(); return OPER_DIV;}
\<=             {updateCol(); return OPER_LTE;}
\>=             {updateCol(); return OPER_GTE;}
\<              {updateCol(); return OPER_LT;}
\>              {updateCol(); return OPER_GT;}
==              {updateCol(); return OPER_EQ;}
!=              {updateCol(); return OPER_NEQ;}
=               {updateCol(); return OPER_ASGN;}

 /* Punctuation */
\[              {updateCol(); return LSQ_BRKT;}
\]              {updateCol(); return RSQ_BRKT;}
\{              {updateCol(); return LCRLY_BRKT;}
\}              {updateCol(); return RCRLY_BRKT;}
\(              {updateCol(); return LPAREN;}
\)              {updateCol(); return RPAREN;}
,               {updateCol(); return COMMA;}
;               {updateCol(); return SEMICLN;}

 /* Enhanced error handling for identifiers */
{identifier}    {
                 updateCol();
                 yylval.strval = strdup(yytext);
                 return ID;
                }
{illidentifier} {
                 reportError("Error: Identifier cannot start with a digit");
                 return ERROR;
                }

 /* Enhanced error handling for constants */
{integer}       {
                 updateCol();
                 char* endptr;
                 long long val = strtoll(yytext, &endptr, 10);
                 if (val > INT_MAX || val < INT_MIN) {
                     reportError("Integer constant out of bounds");
                     return ERROR;
                 }
                 yylval.value = (int)val;
                 return INTCONST;
                }
{integerlead0}  {
                 reportError("Error: Integer cannot have leading zeros");
                 return ERROR;
                }
{character}     {
                 updateCol();
                 return processChar();
                }
{multichar}     {
                 reportError("Error: Character constant contains multiple characters");
                 return ERROR;
                }
{untermchar}    {
                 reportError("Error: Unterminated character constant");
                 return ERROR;
                }
{illegalchar}   {
                 reportError("Error: Illegal escape sequence in character constant");
                 return ERROR;
                }

 /* Enhanced comment handling */
{comment}       {
                 countLines();
                 updateCol();
                }
{untermcomment} {
                 reportError("Error: Unterminated comment");
                 return ERROR;
                }
{multicomment}  {
                 reportError("Error: Comments cannot span multiple lines");
                 return ERROR;
                }

 /* Other */
{newline}       {scancol = 1; scanlineno++; yylineno = scanlineno;}
{whitespace}    {updateCol();}
.               {
                 reportError("Error: Illegal character");
                 return ILLEGAL_TOK;
                }

%%

void updateCol() {
    yycol = scancol;
    scancol += yyleng;
}

void countLines() {
    yylineno = scanlineno;
    for(int i = 0; i < yyleng; i++) {
        if(yytext[i] == '\n') {
            scanlineno++;
        }
    }
}

void reportError(char* msg) {
    updateCol();
    yyerrormsg = msg;
    fprintf(stderr, "Line %d, Col %d: %s\n", scanlineno, yycol, msg);
}

int processChar() {
    if(yytext[1] == '\\') {
        switch(yytext[2]) {
            case '\'': yylval.value = '\''; break;
            case 'n': yylval.value = '\n'; break;
            case 't': yylval.value = '\t'; break;
            case '\\': yylval.value = '\\'; break;
            default:
                reportError("Error: Invalid escape sequence");
                return ERROR;
        }
    } else {
        yylval.value = yytext[1];
    }
    return CHARCONST;
}
