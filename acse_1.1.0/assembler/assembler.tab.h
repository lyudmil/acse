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
     OPCODE3 = 258,
     OPCODE2 = 259,
     OPCODEI = 260,
     CCODE = 261,
     HALT = 262,
     NOP = 263,
     _WORD = 264,
     _SPACE = 265,
     REG = 266,
     LPAR = 267,
     RPAR = 268,
     COLON = 269,
     MINUS = 270,
     BEGIN_IMMEDIATE = 271,
     BEGIN_COMMENT = 272,
     END_COMMENT = 273,
     COMMENT = 274,
     ETI = 275,
     IMM = 276
   };
#endif
/* Tokens.  */
#define OPCODE3 258
#define OPCODE2 259
#define OPCODEI 260
#define CCODE 261
#define HALT 262
#define NOP 263
#define _WORD 264
#define _SPACE 265
#define REG 266
#define LPAR 267
#define RPAR 268
#define COLON 269
#define MINUS 270
#define BEGIN_IMMEDIATE 271
#define BEGIN_COMMENT 272
#define END_COMMENT 273
#define COMMENT 274
#define ETI 275
#define IMM 276




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "assembler.y"
{
	char *svalue;
	int immediate;
	int opcode;
	t_asm_address *address;
	t_asm_data *dataVal;
   t_asm_instruction *instr;
   t_asm_label *label;
   t_asm_register *reg;
}
/* Line 1529 of yacc.c.  */
#line 102 "assembler.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

