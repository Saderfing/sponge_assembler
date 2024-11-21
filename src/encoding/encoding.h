#ifndef _ENCODING_H_
#define _ENCODING_H_
#include <stdio.h>
#include <stdlib.h>
#include "../sponge_std/sponge_std.h"

typedef enum condition{
	AL,
	NE,
	CS,
	CC,
	VS,
	VC,
	HI,
	LS,
	GE,
	LT,
	GT,
	LE,
	EQ,
	CONDITION_COUNT
}ConditionCode;

typedef enum types{
	B, // Byte
	H, // Half-word
	W, // Word
	D, // Double
	DATATYPES_COUNT
} DataTypes;

typedef enum regCode{
	R0,
	R1,
	R2,
	R3,
	R4,
	R5,
	R6,
	R7,
	R8,
	R9,
	R10,
	R11, 
	R12, LR=12,
	R13, FP=13,
	R14, SP=14,
	R15, PC=15,
	REGISTER_COUNT
} RegisterCode;

typedef enum instrName {
	NOP,
	MOV,
	MVN,

	AND,
	ORR,
	XOR,
	ADD,
	SUB,
	MUL,
	DIV,
	REM,
	LSL,
	LSR,

	PSH,
	POP,

	LDR,
	LDREND,
	STR,
	CMP,
	JMP,
	PRR,
	PRM,
	END,
	INSTRUCTION_COUNT
} InstructionCode;

typedef enum instructionMask{
	instructionMask		= 0x1F,
	instructionShift	= 27,

	conditionMask		= 0xF,
	conditionShift		= 23,

	typeMask			= 0x3, // 0000 0000 0110
	typeShift			= 21,

	isImmediateMask		= 0x1, // 0000 0000 0001
	isImmediateShift	= 20,

	destRegisterMask	= 0xF,
	destRegisterShift	= 16,

	simpleIVArgMask		= 0xFFFF,
	simpleIVArgShift	= 0,

	firstRegArgMask		= 0xF,
	firstRegArgShift	= 12,

	secondRegArgMask	= 0xF,
	secondRegArgShift	= 8,

	secondIVArgMask		= 0xFF,
	secondIVArgShift	= 0
}InstructionMask;


#endif