/* definitions */

%{
#include<stdio.h>
#include "parser.tab.h"

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

void updateCol();
void countLines();
%}

newline         \n
whitespace      [ \t]+
integer         0|[1-9][0-9]*
integerlead0    0[0-9]+
character       \'([^\']|\\[\\nt\'])\'

comment         \/\*\/?([^\n\/]|[^\*]\/)*\*\/
multlncomment   \/\*\/?([^\/]|[^\*]\/)*\n([^\/]|[^\*]\/)*\*\/
untermcomment   \/\*\/?([^\/\n]|[^\*]\/)*

identifier      [a-zA-Z][a-zA-Z0-9]*
illidentifier   [0-9]+[a-zA-Z][a-zA-Z0-9]*

yylineno = 1;

%%

 /* rules */

 /* Keywords */
"if"            {updateCol(); return IFTOKEN;}
"else"          {updateCol(); return ELSETOKEN;}
"while"         {updateCol(); return WHILETOKEN;}
"int"           {updateCol(); return INT;}
"char"          {updateCol(); return CHAR;}
"return"        {updateCol(); return RETURN;}
"void"          {updateCol(); return VOID;}

 /* Operators */
\+              {updateCol(); return ADDOP;}
\-              {updateCol(); return SUBOP;}
\*              {updateCol(); return MULOP;}
\/              {updateCol(); return DIVOP;}
\<=             {updateCol(); return LTE;}
\>=             {updateCol(); return GTE;}
\<              {updateCol(); return LT;}
\>              {updateCol(); return GT;}
==              {updateCol(); return EQ;}
!=              {updateCol(); return NEQ;}
=               {updateCol(); return ASSIGN;}

 /* Punctuation */
\[              {updateCol(); return LBRACKET;}  
\]              {updateCol(); return RBRACKET;}
\{              {updateCol(); return LBRACE;}
\}              {updateCol(); return RBRACE;}
\(              {updateCol(); return LPAREN;}
\)              {updateCol(); return RPAREN;}
,               {updateCol(); return ',';}  // Comma should be returned as itself
;               {updateCol(); return SEMICLN;}  // Semicolon should map to SEMICLN

 /* Identifiers */
{identifier}    {updateCol();
                 yylval.strval = (char *) malloc(yyleng * sizeof(char));
                 strcpy(yylval.strval, yytext);
                 return ID;}
{illidentifier} {updateCol(); return ERROR;}

 /* Constants */
{integer}       {updateCol(); yylval.value = atoi(yytext); return INTCONST;}
{integerlead0}  {updateCol(); return ERROR;}
{character}     {updateCol(); return CHARCONST;}

 /* Comments */
{comment}       {updateCol(); /* skip comments */}
{untermcomment} {updateCol(); return ERROR;}
{multlncomment} {updateCol(); countLines(); return ERROR;}

 /* Other */
{newline}       {scancol = 1; scanlineno++; yylineno = scanlineno;}
{whitespace}    {updateCol(); /* skip whitespace */}
.               {return ERROR;}  // Changed ILLEGAL_TOKEN to ERROR

%%

/* user routines */

void updateCol(){
    yycol = scancol;
    scancol += yyleng;
}

void countLines(){
    yylineno = scanlineno;
    for (int i=0; i<yyleng; i++){
        if (yytext[i] == '\n')
            scanlineno++;
    }
}
