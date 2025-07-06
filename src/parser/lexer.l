%option noinput nounput noyywrap
%option yylineno

%{
	#include "parser.h"
	#include "instruction_encoding.h"

	#define END_PARSING 0
%}



BIN_PREFIX 0b
DEC_PREFIX [+-]?
HEX_PREFIX 0x

BIN_NUM	[01]
DEC_NUM	[0-9]
HEX_NUM	[0-9a-fA-F]

REGISTER_PREFIX [rR]

ALPHA		[a-zA-Z]
ALPHANUM	[0-9A-Za-z]
IDENTIFIER 	{ALPHANUM}*{ALPHA}+{ALPHANUM}*

A	[aA]
B	[bB]
C	[cC]
D	[dD]
E	[eE]
F	[fF]
G	[gG]
H	[hH]
I	[iI]
J	[jJ]
K	[kK]
L	[lL]
M	[mM]
N	[nN]
O	[oO]
P	[pP]
Q	[qQ]
R	[rR]
S	[sS]
T	[tT]
U	[uU]
V	[vV]
W	[wW]
X	[xX]
Y	[yY]
Z	[zZ]

%x COMMENT
%x IDENTIFIER

%%
<<EOF>>			{return EOF;}


[\t ]	
\n+				 {return MT_NEW_LINE;}
"//" 			 {BEGIN(COMMENT);}
<COMMENT>[^\n\r] {BEGIN(INITIAL);}	

"."{IDENTIFIER}":"  {return MT_SECTION_NAME;}

{M}{O}{V}	{return MT_INST_MOV; BEGIN(IDENTIFIER);}
{A}{D}{D}	{return MT_INST_ADD; BEGIN(IDENTIFIER);}
{L}{D}{R}	{return MT_INST_LDR; BEGIN(IDENTIFIER);}
{J}{M}{P}	{return MT_INST_JMP; BEGIN(IDENTIFIER);}


{REGISTER_PREFIX}([0-9]|1[0-5])	{yylval.rawRegister = strdup(yytext); return MT_REGISTER;}
{L}{R}							{yylval.rawRegister = strdup("r12"); return MT_REGISTER;}
{F}{P}							{yylval.rawRegister = strdup("r13"); return MT_REGISTER;}
{S}{P}							{yylval.rawRegister = strdup("r14"); return MT_REGISTER;}
{P}{C}							{yylval.rawRegister = strdup("r15"); return MT_REGISTER;}

{BIN_PREFIX}{BIN_NUM}+			{yylval.rawImmediateValue = strdup(yytext); return MT_BIN_VALUE;}
{DEC_PREFIX}{DEC_NUM}+			{yylval.rawImmediateValue = strdup(yytext); return MT_DEC_VALUE;}
{HEX_PREFIX}{HEX_NUM}+			{yylval.rawImmediateValue = strdup(yytext); return MT_HEX_VALUE;}

<IDENTIFIER>{IDENTIFIER}		{yylval.identifier = strdup(yytext); BEGIN(INITIAL); return MT_IDENTIFIER;}

.
%%