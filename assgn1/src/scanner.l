/* definitions */

%{
#include<stdio.h>
#include"tokendef.h"

int scancol = 1;
int yycol = 1;
int scanlineno = 1;

char* yyerror;

void updateCol();
void countLines();
int processString();  // Function to handle string escape sequences
%}

/* Regular Expressions */
newline         \n
whitespace      [ \t]+
integer         0|[1-9][0-9]*
integerlead0    0[0-9]+
character       \'([^\']|\\[nt\\])\'

identifier      [a-zA-Z][a-zA-Z0-9]*
illidentifier   [0-9]+[a-zA-Z][a-zA-Z0-9]*

%%

				//
				/* Keywords */
"if"            { updateCol(); return KWD_IF; }
"else"          { updateCol(); return KWD_ELSE; }
"while"         { updateCol(); return KWD_WHILE; }
"int"		{ updateCol(); return KWD_INT; }
"void"          { updateCol(); return KWD_VOID; }
"return"        { updateCol(); return KWD_RETURN; }
"char"          { updateCol(); return KWD_CHAR; }
"string"        { updateCol(); return KWD_STRING; }

				/* Operators */
\+              { updateCol(); return OPER_ADD; }
\-              { updateCol(); return OPER_SUB; }
\*              { updateCol(); return OPER_MUL; }
\/              { updateCol(); return OPER_DIV; }
"<"             { updateCol(); return OPER_LT; }
">"             { updateCol(); return OPER_GT; }
"<="            { updateCol(); return OPER_LTE; }
">="            { updateCol(); return OPER_GTE; }
"=="            { updateCol(); return OPER_EQ; }
"!="            { updateCol(); return OPER_NEQ; }
"="             { updateCol(); return OPER_ASGN; }
"%"             { updateCol(); return OPER_MOD; }    /* Modulus operator */
"++"            { updateCol(); return OPER_INC; }    /* Increment operator */
"--"            { updateCol(); return OPER_DEC; }    /* Decrement operator */
"&&"            { updateCol(); return OPER_AND; }    /* Logical AND operator */
"||"            { updateCol(); return OPER_OR; }     /* Logical OR operator */
"!"             { updateCol(); return OPER_NOT; }    /* Logical NOT operator */
"@"             { updateCol(); return OPER_AT; }     /* @ operator */

		/* Punctuation and Brackets */
\[              { updateCol(); return LSQ_BRKT; }
\]              { updateCol(); return RSQ_BRKT; }
\{              { updateCol(); return LCRLY_BRKT; }
\}              { updateCol(); return RCRLY_BRKT; }
\(              { updateCol(); return LPAREN; }
\)              { updateCol(); return RPAREN; }
,               { updateCol(); return COMMA; }
;               { updateCol(); return SEMICLN; }

	/* Identifiers */
{identifier}    { updateCol(); printf("<ID, %s> : (%d:%d)\n", yytext, scanlineno, yycol); }
{illidentifier} { updateCol(); yyerror = "Illegal identifier"; return ILLEGAL_TOK; }

	/* Constants */
{integer}       { updateCol(); return INTCONST; }
{character}     { updateCol(); return CHARCONST; }


	/* Strings */
\"([^\"\n]|\\[\"ntbr\\])*\" {
    updateCol();
    int result = processString();
    if (result == ERROR) {
        return ERROR;  // Just return ERROR, don't print
    }
    return STRCONST;
}
\"([^\"\n])*$                  { updateCol(); yyerror = "Unterminated string"; printf("<ERROR, Unterminated string> : (%d:%d)\n", scanlineno, yycol); }

	/* Comments */
"\/\*"([^*]|\*+[^/])*\*+\/     { updateCol(); /* A valid closed comment, no error */ }
"\/\*"([^*]|\*+[^/])*         { updateCol(); yyerror = "Unterminated comment"; return ERROR; }  /* Unterminated comment */

			/* Whitespace and Newlines */
{whitespace}    { updateCol(); /* Skip whitespace */ }
{newline} { countLines(); }

	/* Catch any illegal token */
{integerlead0} { updateCol(); yyerror = "Leading zero in integer"; printf("<ILLEGAL TOKEN>\n"); return ERROR; }
.              { updateCol(); yyerror = "Illegal token"; printf("<ILLEGAL TOKEN>\n"); }

%%

/* user routines */

/* Update column number */
void updateCol() {
    yycol = scancol;
    scancol += yyleng;
}

/* Count lines */
void countLines() {
    scanlineno++;
    scancol = 1;
}

/* Process string literals */
int processString() {
    char *str = yytext;

    for (int i = 0; i < yyleng; i++) {
        if (str[i] == '\\') {
            // Check for valid escape sequences
            if (str[i+1] == 'n' || str[i+1] == 't' || str[i+1] == '"' || str[i+1] == '\\') {
                i++; // Skip valid escape sequences
            } else {
                // Invalid escape sequence detected, just return ERROR, don't print here
		yyerror = "Invalid escape sequence"; // sets a proper error message                
		return ERROR;
            }
        }
    }
    return STRCONST;  // Return string constant if no error
}

int yywrap() {
    return 1;
}
