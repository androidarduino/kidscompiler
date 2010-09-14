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
     QSTRING = 258,
     ID = 259,
     COMMENT = 260,
     SCREEN = 261,
     TITLE = 262,
     ITEM = 263,
     COMMAND = 264,
     ACTION = 265,
     EXECUTE = 266,
     EMPTY = 267,
     MENU = 268,
     QUIT = 269,
     IGNORE = 270,
     ATTRIBUTE = 271,
     VISIBLE = 272,
     INVISIBLE = 273,
     END = 274
   };
#endif
/* Tokens.  */
#define QSTRING 258
#define ID 259
#define COMMENT 260
#define SCREEN 261
#define TITLE 262
#define ITEM 263
#define COMMAND 264
#define ACTION 265
#define EXECUTE 266
#define EMPTY 267
#define MENU 268
#define QUIT 269
#define IGNORE 270
#define ATTRIBUTE 271
#define VISIBLE 272
#define INVISIBLE 273
#define END 274




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 13 "mglyac.y"
{
    char    *string;     /* string buffer */
    int    cmd;          /* command value */
}
/* Line 1489 of yacc.c.  */
#line 92 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

