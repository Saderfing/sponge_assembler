#ifndef __INSTRUCTION_ENCODING_H__
#define __INSTRUCTION_ENCODING_H__
#include <stdio.h>
#include <stdlib.h>
#include "../sponge_std/sponge_std.h"

/*
Extremely inpired by the ARM instruction set
*/
#define NOT_IMMEDIATE 0
#define IMMEDIATE 1
#define NOT_SET_IMMEDIATE 2

typedef enum condition{
	IC_AL,
	IC_NE,
	IC_CS,
	IC_CC,
	IC_VS,
	IC_VC,
	IC_HI,
	IC_LS,
	IC_GE,
	IC_LT,
	IC_GT,
	IC_LE,
	IC_EQ,
	IC_INVALID_CONDITION,
	CONDITION_COUNT
}ConditionCode;

typedef enum types{
	ID_BYTE, // Byte
	ID_HWRD, // Half-word
	ID_WORD, // Word
	ID_DOUB, // Double
	ID_INVALID_DATATYPE,
	DATATYPES_COUNT
} DataType;

typedef enum regCode{
	IR_R0,
	IR_R1,
	IR_R2,
	IR_R3,
	IR_R4,
	IR_R5,
	IR_R6,
	IR_R7,
	IR_R8,
	IR_R9,
	IR_R10,
	IR_R11, 
	IR_R12, IR_LR=12,
	IR_R13, IR_FP=13,
	IR_R14, IR_SP=14,
	IR_R15, IR_PC=15,
	IR_INVALID_REGISTER,
	REGISTER_COUNT
} RegisterCode;

typedef enum instrName {
	IM_NOP,

	IM_AND,
	IM_ORR,
	IM_XOR,
	IM_ADD,
	IM_SUB,
	IM_MUL,
	IM_DIV,
	IM_REM,
	IM_LSL,
	IM_LSR,

	IM_LDR,
	IM_STR,

	IM_CMP,
	IM_JMP,

	IM_MOV,
	IM_MVN,

	IM_PRR,
	IM_PRM,
	
	IM_HLT,
	IM_INVALID_MNEMONIC,
	MNEMONIC_COUNT
} Mnemonic;

typedef enum instructionMask{
	MNEMONIC_MASK = 0x1F,
	MNEMONIC_SIZE = 5,

	CONDITION_MASK		  = 0xF,
	CONDITION_SIZE		  = 4,

	DATATYPE_MASK			  = 0x3,
	DATATYPE_SIZE			  = 2,

	IS_IMMEDIATE_MASK	  = 0x1,
	IS_IMMEDIATE_SIZE	  = 1,

	REGISTER_CODE_MASK		  = 0xF,
	REGISTER_CODE_SIZE		  = 4,

	IMMEDIATE_VALUE_MASK  = 0xFFFFFFFF,
	IMMEDIATE_VALUE_SIZE  = 32
} InstructionMask;

#endif