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
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser/parser.y"

#include <stdio.h>
#include "../sponge_std/sponge_std.h"
#include "../encoding/encoding.h"
#include "../hashmap/hashmap.h"
#include "../instruction/instruction_stream.h"

extern FILE *yyin;
extern FILE *yyout;

#line 60 "src/parser/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DATA = 258,                    /* DATA  */
    TEXT = 259,                    /* TEXT  */
    START = 260,                   /* START  */
    BYTE_TYPE = 261,               /* BYTE_TYPE  */
    HWRD_TYPE = 262,               /* HWRD_TYPE  */
    WORD_TYPE = 263,               /* WORD_TYPE  */
    DOUB_TYPE = 264,               /* DOUB_TYPE  */
    BYTE_DECLARATION = 265,        /* BYTE_DECLARATION  */
    HWORD_DECLARATION = 266,       /* HWORD_DECLARATION  */
    WORD_DECLARATION = 267,        /* WORD_DECLARATION  */
    DOUBLE_DECLARATION = 268,      /* DOUBLE_DECLARATION  */
    AL_COND = 269,                 /* AL_COND  */
    NE_COND = 270,                 /* NE_COND  */
    CS_COND = 271,                 /* CS_COND  */
    CC_COND = 272,                 /* CC_COND  */
    VS_COND = 273,                 /* VS_COND  */
    VC_COND = 274,                 /* VC_COND  */
    HI_COND = 275,                 /* HI_COND  */
    LS_COND = 276,                 /* LS_COND  */
    GE_COND = 277,                 /* GE_COND  */
    LT_COND = 278,                 /* LT_COND  */
    GT_COND = 279,                 /* GT_COND  */
    LE_COND = 280,                 /* LE_COND  */
    EQ_COND = 281,                 /* EQ_COND  */
    INST_MOV = 282,                /* INST_MOV  */
    INST_MVN = 283,                /* INST_MVN  */
    INST_AND = 284,                /* INST_AND  */
    INST_ORR = 285,                /* INST_ORR  */
    INST_XOR = 286,                /* INST_XOR  */
    INST_ADD = 287,                /* INST_ADD  */
    INST_SUB = 288,                /* INST_SUB  */
    INST_MUL = 289,                /* INST_MUL  */
    INST_DIV = 290,                /* INST_DIV  */
    INST_REM = 291,                /* INST_REM  */
    INST_LSL = 292,                /* INST_LSL  */
    INST_LSR = 293,                /* INST_LSR  */
    INST_PSH = 294,                /* INST_PSH  */
    INST_POP = 295,                /* INST_POP  */
    INST_LDR = 296,                /* INST_LDR  */
    INST_STR = 297,                /* INST_STR  */
    INST_CMP = 298,                /* INST_CMP  */
    INST_JMP = 299,                /* INST_JMP  */
    INST_PRR = 300,                /* INST_PRR  */
    INST_PRM = 301,                /* INST_PRM  */
    IDENTIFIER = 302,              /* IDENTIFIER  */
    DECLARATION = 303,             /* DECLARATION  */
    IV = 304,                      /* IV  */
    REG0 = 305,                    /* REG0  */
    REG1 = 306,                    /* REG1  */
    REG2 = 307,                    /* REG2  */
    REG3 = 308,                    /* REG3  */
    REG4 = 309,                    /* REG4  */
    REG5 = 310,                    /* REG5  */
    REG6 = 311,                    /* REG6  */
    REG7 = 312,                    /* REG7  */
    REG8 = 313,                    /* REG8  */
    REG9 = 314,                    /* REG9  */
    REG10 = 315,                   /* REG10  */
    REG11 = 316,                   /* REG11  */
    REG12 = 317,                   /* REG12  */
    REG13 = 318,                   /* REG13  */
    REG14 = 319,                   /* REG14  */
    REG15 = 320,                   /* REG15  */
    SEP = 321,                     /* SEP  */
    EL = 322,                      /* EL  */
    END_OF_FILE = 323              /* END_OF_FILE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "src/parser/parser.y"

	char *identifier;
	char *iv;

#line 150 "src/parser/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (InstStream * is, HashMap * symboleTable);


#endif /* !YY_YY_SRC_PARSER_PARSER_H_INCLUDED  */
