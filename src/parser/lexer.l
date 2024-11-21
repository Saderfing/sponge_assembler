%{
#include "parser.h"
#include "../encoding/encoding.h"

#define END_PARSING 0
%}

%x PARSE_ID

%%
<<EOF>>				{return END_PARSING;}
[ \t]				{return SEP;}	 			
\n					{return EL;}

.data:				{return DATA;}
.text:				{return TEXT;}

.start[ \t]*:		{return START; }
.byte[ \t]*:		{return BYTE_DECLARATION;}
.hword[ \t]*:		{return HWORD_DECLARATION;}
.word[ \t]*:		{return WORD_DECLARATION;}
.double[ \t]*:		{return DOUBLE_DECLARATION;}

(?i:MOV)			{return INST_MOV; BEGIN(PARSE_ID);}
(?i:MVN)			{return INST_MVN; BEGIN(PARSE_ID);}
(?i:AND)			{return INST_AND; BEGIN(PARSE_ID);}
(?i:ORR)			{return INST_ORR; BEGIN(PARSE_ID);}
(?i:XOR)			{return INST_XOR; BEGIN(PARSE_ID);}
(?i:ADD)			{return INST_ADD; BEGIN(PARSE_ID);}
(?i:SUB)			{return INST_SUB; BEGIN(PARSE_ID);}
(?i:MUL)			{return INST_MUL; BEGIN(PARSE_ID);}
(?i:DIV)			{return INST_DIV; BEGIN(PARSE_ID);}
(?i:REM)			{return INST_REM; BEGIN(PARSE_ID);}
(?i:LSL)			{return INST_LSL; BEGIN(PARSE_ID);}
(?i:LSR)			{return INST_LSR; BEGIN(PARSE_ID);}
(?i:PSH)			{return INST_PSH; BEGIN(PARSE_ID);}
(?i:POP)			{return INST_POP; BEGIN(PARSE_ID);}
(?i:LDR)			{return INST_LDR; BEGIN(PARSE_ID);}
(?i:STR)			{return INST_STR; BEGIN(PARSE_ID);}
(?i:CMP)			{return INST_CMP; BEGIN(PARSE_ID);}
(?i:JMP)			{return INST_JMP; BEGIN(PARSE_ID);}
(?i:PRR)			{return INST_PRR; BEGIN(PARSE_ID);}
(?i:PRM)			{return INST_PRM; BEGIN(PARSE_ID); }

(?i:R0)				{return REG0; BEGIN(PARSE_ID);}
(?i:R1)				{return REG1; BEGIN(PARSE_ID);}
(?i:R2)				{return REG2; BEGIN(PARSE_ID);}
(?i:R3)				{return REG3; BEGIN(PARSE_ID);}
(?i:R4)				{return REG4; BEGIN(PARSE_ID);}
(?i:R5)				{return REG5; BEGIN(PARSE_ID);}
(?i:R6)				{return REG6; BEGIN(PARSE_ID);}
(?i:R7)				{return REG7; BEGIN(PARSE_ID);}
(?i:R8)				{return REG8; BEGIN(PARSE_ID);}
(?i:R9)				{return REG9; BEGIN(PARSE_ID);}
(?i:R10)			{return REG10; BEGIN(PARSE_ID);}
(?i:R11)			{return REG11; BEGIN(PARSE_ID);}
(?i:R12)|(?i:lr)	{return REG12; BEGIN(PARSE_ID);}
(?i:R13)|(?i:fp)	{return REG13; BEGIN(PARSE_ID);}
(?i:R14)|(?i:sp)	{return REG14; BEGIN(PARSE_ID);}
(?i:R15)|(?i:pc)	{return REG15; BEGIN(PARSE_ID);}

(?i:B)				{return BYTE_TYPE; BEGIN(PARSE_ID);}
(?i:H)				{return HWRD_TYPE; BEGIN(PARSE_ID);}
(?i:W)				{return WORD_TYPE; BEGIN(PARSE_ID);}
(?i:D)				{return DOUB_TYPE; BEGIN(PARSE_ID);}

(?i:AL)				{return AL_COND; BEGIN(PARSE_ID);}
(?i:NE)				{return NE_COND; BEGIN(PARSE_ID);}
(?i:CS)				{return CS_COND; BEGIN(PARSE_ID);}
(?i:CC)				{return CC_COND; BEGIN(PARSE_ID);}
(?i:VS)				{return VS_COND; BEGIN(PARSE_ID);}
(?i:VC)				{return VC_COND; BEGIN(PARSE_ID);}
(?i:HI)				{return HI_COND; BEGIN(PARSE_ID);}
(?i:LS)				{return LS_COND; BEGIN(PARSE_ID);}
(?i:GE)				{return GE_COND; BEGIN(PARSE_ID);}
(?i:LT)				{return LT_COND; BEGIN(PARSE_ID);}
(?i:GT)				{return GT_COND; BEGIN(PARSE_ID);}
(?i:LE)				{return LE_COND; BEGIN(PARSE_ID);}
(?i:EQ)				{return EQ_COND; BEGIN(PARSE_ID);}

#-?[0-9]+				{ECHO; return IV;}
[0-9a-zA-Z_-]*[a-zA-Z][a-zA-Z0-9_-]*:	{return DECLARATION;}
<PARSE_ID>[0-9a-zA-Z_-]*[a-zA-Z][a-zA-Z0-9_-]*	{return IDENTIFIER; BEGIN(0);}
%%
