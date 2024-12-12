/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "src/parser.y"
{
    int value;
    struct treenode *node;
    char *strval;
}
/* Line 1529 of yacc.c.  */
#line 117 "obj/parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

