%code requires {

	#include <stdio.h>
	#include "sponge_std.h"
	#include "instruction_encoding.h"
	#include "instruction_stream.h"
	#include "instruction.h"
	#include "hashmap.h"
	#include "string.h"

	extern int yylineno;
	extern FILE *yyin;
}

%code top {
	#include "parser.h"
	#include "error_handling.h"

	extern int yylex();
	int yyerror(InstStream *is, HashMap *symboleTable, const char *s);

	int yydebug = 1;
	u32 programAddress = 0;
}


%define api.symbol.prefix {MS_}	// Micropiler Symbol
%define api.token.prefix {MT_}	// Micropiler Token


%token SECTION_NAME VARIABLE_DEF

%token PROG_SECTION DATA_SECTION BSS_SECTION

%token NEW_LINE

%token INST_MOV INST_MVN INST_AND INST_ORR INST_XOR INST_ADD INST_SUB INST_MUL INST_DIV INST_REM INST_LSL INST_LSR INST_LDR INST_STR INST_CMP INST_JMP INST_PRR INST_PRM

%union {
	char *identifier;
	char *rawImmediateValue;
	char *rawRegister;
	uint32_t immediatValue;
	Inst instruction;
	RegisterCode registerCode;
}

%token <identifier> IDENTIFIER
%token <rawImmediateValue> BIN_VALUE DEC_VALUE HEX_VALUE 
%token <rawRegister> REGISTER

%nterm <immediatValue> immediat_value
%nterm <instruction> copy_operation calc_operation jump load_store
%nterm <registerCode> reg

%token SEP EL

%start program

%parse-param {InstStream * is} {HashMap * symboleTable}
%%

program:
	 %empty
	|SECTION_NAME NEW_LINE section_content program {}
	;

section_content:
	 prog_section
	;


prog_section:
	 %empty
	|NEW_LINE prog_section
	|declaration instruction NEW_LINE prog_section
	|declaration NEW_LINE prog_section
	|instruction NEW_LINE prog_section
	;

declaration:
	 IDENTIFIER ':' {appendHashMap($1, yylineno, symboleTable);}
	;

instruction:
	 copy_operation		{appendInstruction($1, is);}
	|calc_operation		{appendInstruction($1, is);}
	|jump				{appendInstruction($1, is);}
	|load_store			{appendInstruction($1, is); printInstStream(is);}
	;

copy_operation:
	 INST_MOV reg immediat_value {$$ = getCopyInstruction(IM_MOV, IMMEDIATE, $2, $3);}
	|INST_MOV reg reg			 {$$ = getCopyInstruction(IM_MOV, IMMEDIATE, $2, $3);}
	;

calc_operation:
	 INST_ADD reg reg immediat_value {$$ = getCalculInstruction(IM_ADD, IMMEDIATE, $2, $3, $4);}
	|INST_ADD reg reg reg			 {$$ = getCalculInstruction(IM_ADD, IMMEDIATE, $2, $3, $4);}
	;

jump:
	 INST_JMP IDENTIFIER	 {$$ = getJumpInstruction(getHashMap($2, symboleTable)); free($2);}
	|INST_JMP immediat_value {$$ = getJumpInstruction($2);}
	;
	
load_store:
	 INST_LDR reg reg reg {$$ = getLoadStoreInstruction(IM_LDR, NOT_IMMEDIATE, $2, $3, $4);}
	|INST_STR reg reg reg {$$ = getLoadStoreInstruction(IM_STR, IMMEDIATE, $2, $3, $4);}
	;

immediat_value:
	 BIN_VALUE	{$$ = getImmediateValue($1, 2); free($1);  printf("%s : %d %x", $1, $$, $$);}
	|DEC_VALUE	{$$ = getImmediateValue($1, 10); free($1); printf("%s : %d %x", $1, $$, $$);}
	|HEX_VALUE	{$$ = getImmediateValue($1, 16); free($1); printf("%s : %d %x", $1, $$, $$);}
	;

reg:
	REGISTER		{$$ = getRegisterCode($1); free($1);}
	;

%%

int yyerror(InstStream *is, HashMap *symboleTable, const char *s){
	resetInstStream(is);
	printf("Line : %d | Instruction : %d\n", yylineno, programAddress);

	return 0;
}

int yywarp(){
	return 1;
}
