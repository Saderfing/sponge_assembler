%code requires {
#include <stdio.h>
#include "../sponge_std/sponge_std.h"
#include "../encoding/encoding.h"
#include "../hashmap/hashmap.h"
#include "../instruction/instruction_stream.h"

extern FILE *yyin;
extern FILE *yyout;
}

%code top {
#include "parser.h"
#include "../error_handling/error_handling.h"

extern int yylex();

int yydebug = 1;
u32 line = 1;
u32 programAddress = 0;
Inst curInst = NOP;
RegisterCode curReg;
}

%union{
	char *identifier;
	char *iv;
};

%token DATA TEXT START

// DATATYPES
%token BYTE_TYPE HWRD_TYPE WORD_TYPE DOUB_TYPE

%token BYTE_DECLARATION HWORD_DECLARATION WORD_DECLARATION DOUBLE_DECLARATION

%token AL_COND NE_COND CS_COND CC_COND VS_COND VC_COND HI_COND LS_COND GE_COND LT_COND GT_COND LE_COND EQ_COND

%token INST_MOV INST_MVN INST_AND INST_ORR INST_XOR INST_ADD INST_SUB INST_MUL INST_DIV INST_REM INST_LSL INST_LSR INST_PSH INST_POP INST_LDR INST_STR INST_CMP INST_JMP INST_PRR INST_PRM

%token <identifier> IDENTIFIER DECLARATION
%token <iv> IV
%type <iv> small_iv
%type <iv> large_iv

%token REG0 REG1 REG2 REG3 REG4 REG5 REG6 REG7 REG8 REG9 REG10 REG11 REG12 REG13 REG14 REG15

%token SEP EL END_OF_FILE

%start program

%parse-param {InstStream * is} {HashMap * symboleTable}
%%

program:
	|text data
	|data text
	;

text:
	TEXT EL text_content 		{line++;}
	|TEXT start EL text_content {line++;}
	;

start:
	START IDENTIFIER
	;

text_content:
	|sep instruction el text_content
	|sep DECLARATION instruction el text_content
	;


instruction:
	una_inst	{appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
	|bin_inst	{appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
	|ter_inst	{appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
	|jump		{appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
	|load		{appendInstruction(curInst, is); curInst = newInst(); programAddress++;}
	;

load:
	INST_LDR condition datatype sep dr sep fr {curInst = setInstructionCode(curInst, LDR);}
	;

jump:
	INST_JMP condition datatype sep dr				{curInst = setInstructionCode(curInst, JMP);}
	|INST_JMP condition datatype sep large_iv		{curInst = setInstructionCode(curInst, JMP);}
	|INST_JMP condition datatype sep IDENTIFIER		{curInst = setInstructionCode(curInst, JMP);}
	;

una_inst:
	inst_code_una condition datatype sep dr
	|inst_code_una condition datatype sep large_iv
	;

bin_inst:
	inst_code_bin condition datatype sep dr sep fr
	|inst_code_bin condition datatype sep dr sep small_iv
	;

ter_inst:
	inst_code_ter condition datatype sep dr sep fr sep sr
	|inst_code_ter condition datatype sep dr sep fr sep small_iv
	;

small_iv:
	IV			{curInst = setAsImmediate(curInst, true); curInst = setSmallIV(curInst, $1);}
	;

large_iv:
	IV			{curInst = setAsImmediate(curInst, true); curInst = setLargeIV(curInst, $1);}
	;


el:
	| EL el				{line++;}
	;

sep: 
	| SEP sep
	;	

inst_code_una:
	INST_PRM		{curInst = setInstructionCode(curInst, PRM);}
	|INST_PRR		{curInst = setInstructionCode(curInst, PRR);}
	|INST_PSH		{curInst = setInstructionCode(curInst, PSH);}
	|INST_POP		{curInst = setInstructionCode(curInst, POP);}
	;

inst_code_bin:
	INST_CMP		{curInst = setInstructionCode(curInst, CMP);}
	|INST_MOV		{curInst = setInstructionCode(curInst, MOV);}
	|INST_MVN		{curInst = setInstructionCode(curInst, MVN);}
	|INST_STR		{curInst = setInstructionCode(curInst, STR);}
	;

inst_code_ter:
	INST_ADD		{curInst = setInstructionCode(curInst, ADD);}
	|INST_AND		{curInst = setInstructionCode(curInst, AND);}
	|INST_DIV		{curInst = setInstructionCode(curInst, DIV);}
	|INST_LSL		{curInst = setInstructionCode(curInst, LSL);}
	|INST_LSR		{curInst = setInstructionCode(curInst, LSR);}
	|INST_MUL		{curInst = setInstructionCode(curInst, MUL);}
	|INST_ORR		{curInst = setInstructionCode(curInst, ORR);}
	|INST_REM		{curInst = setInstructionCode(curInst, REM);}
	|INST_SUB		{curInst = setInstructionCode(curInst, SUB);}
	|INST_XOR		{curInst = setInstructionCode(curInst, XOR);}
	;

datatype:				{curInst = setTypeCode(curInst, W);}
	|BYTE_TYPE			{curInst = setTypeCode(curInst, B);}
	|HWRD_TYPE			{curInst = setTypeCode(curInst, H);}
	|WORD_TYPE			{curInst = setTypeCode(curInst, W);}
	|DOUB_TYPE			{curInst = setTypeCode(curInst, D);}
	;

condition:				{curInst = setConditionCode(curInst, AL);}
	|AL_COND			{curInst = setConditionCode(curInst, AL);}
	|NE_COND			{curInst = setConditionCode(curInst, NE);}
	|CS_COND			{curInst = setConditionCode(curInst, CS);}
	|CC_COND			{curInst = setConditionCode(curInst, CC);}
	|VS_COND			{curInst = setConditionCode(curInst, VS);}
	|VC_COND			{curInst = setConditionCode(curInst, VC);}
	|HI_COND			{curInst = setConditionCode(curInst, HI);}
	|LS_COND			{curInst = setConditionCode(curInst, LS);}
	|GE_COND			{curInst = setConditionCode(curInst, GE);}
	|LT_COND			{curInst = setConditionCode(curInst, LT);}
	|GT_COND			{curInst = setConditionCode(curInst, GT);}
	|LE_COND			{curInst = setConditionCode(curInst, LE);}
	|EQ_COND			{curInst = setConditionCode(curInst, EQ);}
	;

dr:
	REG0 				{curInst = setDestRegister(curInst, R0);}
	|REG1 				{curInst = setDestRegister(curInst, R1);}
	|REG2 				{curInst = setDestRegister(curInst, R2);}
	|REG3 				{curInst = setDestRegister(curInst, R3);}
	|REG4 				{curInst = setDestRegister(curInst, R4);}
	|REG5 				{curInst = setDestRegister(curInst, R5);}
	|REG6 				{curInst = setDestRegister(curInst, R6);}
	|REG7 				{curInst = setDestRegister(curInst, R7);}
	|REG8 				{curInst = setDestRegister(curInst, R8);}
	|REG9 				{curInst = setDestRegister(curInst, R9);}
	|REG10 				{curInst = setDestRegister(curInst, R10);}
	|REG11 				{curInst = setDestRegister(curInst, R11);}
	|REG12 				{curInst = setDestRegister(curInst, R12);}
	|REG13 				{curInst = setDestRegister(curInst, R13);}
	|REG14 				{curInst = setDestRegister(curInst, R14);}
	|REG15 				{curInst = setDestRegister(curInst, R15);}
	;

fr:
	REG0 				{curInst = setFirstRegister(curInst, R0);}
	|REG1 				{curInst = setFirstRegister(curInst, R1);}
	|REG2 				{curInst = setFirstRegister(curInst, R2);}
	|REG3 				{curInst = setFirstRegister(curInst, R3);}
	|REG4 				{curInst = setFirstRegister(curInst, R4);}
	|REG5 				{curInst = setFirstRegister(curInst, R5);}
	|REG6 				{curInst = setFirstRegister(curInst, R6);}
	|REG7 				{curInst = setFirstRegister(curInst, R7);}
	|REG8 				{curInst = setFirstRegister(curInst, R8);}
	|REG9 				{curInst = setFirstRegister(curInst, R9);}
	|REG10 				{curInst = setFirstRegister(curInst, R10);}
	|REG11 				{curInst = setFirstRegister(curInst, R11);}
	|REG12 				{curInst = setFirstRegister(curInst, R12);}
	|REG13 				{curInst = setFirstRegister(curInst, R13);}
	|REG14 				{curInst = setFirstRegister(curInst, R14);}
	|REG15 				{curInst = setFirstRegister(curInst, R15);}
	;

sr:
	REG0 				{curInst = setSecondRegister(curInst, R0);}
	|REG1 				{curInst = setSecondRegister(curInst, R1);}
	|REG2 				{curInst = setSecondRegister(curInst, R2);}
	|REG3 				{curInst = setSecondRegister(curInst, R3);}
	|REG4 				{curInst = setSecondRegister(curInst, R4);}
	|REG5 				{curInst = setSecondRegister(curInst, R5);}
	|REG6 				{curInst = setSecondRegister(curInst, R6);}
	|REG7 				{curInst = setSecondRegister(curInst, R7);}
	|REG8 				{curInst = setSecondRegister(curInst, R8);}
	|REG9 				{curInst = setSecondRegister(curInst, R9);}
	|REG10 				{curInst = setSecondRegister(curInst, R10);}
	|REG11 				{curInst = setSecondRegister(curInst, R11);}
	|REG12 				{curInst = setSecondRegister(curInst, R12);}
	|REG13 				{curInst = setSecondRegister(curInst, R13);}
	|REG14 				{curInst = setSecondRegister(curInst, R14);}
	|REG15 				{curInst = setSecondRegister(curInst, R15);}
	;

data:
	DATA					{printf("data");}
	;

bss:

%%

int yyerror(InstStream *is, HashMap *symboleTable, const char *s){
	resetInstStream(is);
	printf("Line : %d | Instruction : %d\n", line, programAddress);

	return 0;
}

int yywarp(){
	return 1;
}
