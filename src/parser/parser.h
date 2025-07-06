/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser/parser.y"


	#include <stdio.h>
	#include "sponge_std.h"
	#include "instruction_encoding.h"
	#include "instruction_stream.h"
	#include "instruction.h"
	#include "hashmap.h"
	#include "string.h"

	extern int yylineno;
	extern FILE *yyin;

#line 63 "src/parser/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MT_YYEMPTY = -2,
    MT_YYEOF = 0,                  /* "end of file"  */
    MT_YYerror = 256,              /* error  */
    MT_YYUNDEF = 257,              /* "invalid token"  */
    MT_SECTION_NAME = 258,         /* SECTION_NAME  */
    MT_VARIABLE_DEF = 259,         /* VARIABLE_DEF  */
    MT_PROG_SECTION = 260,         /* PROG_SECTION  */
    MT_DATA_SECTION = 261,         /* DATA_SECTION  */
    MT_BSS_SECTION = 262,          /* BSS_SECTION  */
    MT_NEW_LINE = 263,             /* NEW_LINE  */
    MT_INST_MOV = 264,             /* INST_MOV  */
    MT_INST_MVN = 265,             /* INST_MVN  */
    MT_INST_AND = 266,             /* INST_AND  */
    MT_INST_ORR = 267,             /* INST_ORR  */
    MT_INST_XOR = 268,             /* INST_XOR  */
    MT_INST_ADD = 269,             /* INST_ADD  */
    MT_INST_SUB = 270,             /* INST_SUB  */
    MT_INST_MUL = 271,             /* INST_MUL  */
    MT_INST_DIV = 272,             /* INST_DIV  */
    MT_INST_REM = 273,             /* INST_REM  */
    MT_INST_LSL = 274,             /* INST_LSL  */
    MT_INST_LSR = 275,             /* INST_LSR  */
    MT_INST_LDR = 276,             /* INST_LDR  */
    MT_INST_STR = 277,             /* INST_STR  */
    MT_INST_CMP = 278,             /* INST_CMP  */
    MT_INST_JMP = 279,             /* INST_JMP  */
    MT_INST_PRR = 280,             /* INST_PRR  */
    MT_INST_PRM = 281,             /* INST_PRM  */
    MT_IDENTIFIER = 282,           /* IDENTIFIER  */
    MT_BIN_VALUE = 283,            /* BIN_VALUE  */
    MT_DEC_VALUE = 284,            /* DEC_VALUE  */
    MT_HEX_VALUE = 285,            /* HEX_VALUE  */
    MT_REGISTER = 286,             /* REGISTER  */
    MT_SEP = 287,                  /* SEP  */
    MT_EL = 288                    /* EL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "src/parser/parser.y"

	char *identifier;
	char *rawImmediateValue;
	char *rawRegister;
	uint32_t immediatValue;
	EncodedInst instruction;
	RegisterCode registerCode;

#line 122 "src/parser/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (InstStream * is, HashMap * symboleTable);


#endif /* !YY_YY_SRC_PARSER_PARSER_H_INCLUDED  */
