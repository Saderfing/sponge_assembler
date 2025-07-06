#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "instruction_encoding.h"

typedef uint64_t EncodedInst; // Encoded instruction

typedef struct instruction{
	Mnemonic mnemonic;
	uint8_t isImmediate;
	ConditionCode condition;
	DataType dataType;
	RegisterCode destRegister;
	RegisterCode arg1Register;
	RegisterCode arg2Register;
	uint32_t immediateValue;
} DecodedInst; // Decoded instruction

typedef DecodedInst Inst; // Easier because im lazy

#define DEFAULT_INSTRUCTION NOP

EncodedInst newEncodedInst();

void resetDecodedInst(DecodedInst *inst);

DecodedInst *newDecodedInst();

void freeDecodedInst(DecodedInst **inst);

void setBits(uint64_t *dest, uint64_t src, uint64_t mask, uint64_t shift);

uint64_t getBits(uint64_t src, uint64_t mask, uint64_t shift);

// -=-=-=-=[ Valid ]=-=-=-=-
bool isValidMnemonic(Mnemonic mnemonic);

bool isValidIsImmediateValue(uint8_t isImmediate);

bool isValidConditionCode(ConditionCode condition);

bool isValidDataType(DataType datatype);

bool isValidRegisterCode(RegisterCode registerCode);

bool isValidEncodedInst(EncodedInst inst);

bool isCalculInstruction(Mnemonic mnemonic);

bool isLoadStoreInstruction(Mnemonic mnemonic);

bool isBinInstruction(Mnemonic mnemonic);

bool isJumpInstruction(Mnemonic mnemonic);

bool isPrintRegisterInstruction(Mnemonic mnemonic);

bool isPrintMemoryRegisterInstruction(Mnemonic mnemonic);

bool isValidCalculInstruction(DecodedInst *i);

bool isValidLoadStoreInstruction(DecodedInst *i);

bool isValidBinOperation(DecodedInst *i);

bool isValidJumpInstruction(DecodedInst *i);

bool isValidPrintRegisterInstruction(DecodedInst *i);

bool isValidPrintMemoryInstruction(DecodedInst *i);

// -=-=-=-=[ Create encoded instruction ]=-=-=-=-
EncodedInst getPrrEncodedInst(RegisterCode registerCode);

EncodedInst getCopyEncodedInst(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, uint64_t value);

EncodedInst getJumpEncodedInst(uint8_t isImmediate, uint32_t value);

EncodedInst getLoadStoreEncodedInst(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value);

EncodedInst getCalculEncodedInst(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value);

uint32_t getImmediateValue(char *value, int base);

uint8_t getRegisterCode(char *reg);

// -=-=-=-= [ Decoder ] =-=-=-=-

/* Decode the mnemonic of the instruction
		Return : mnemonic
		INSTRUCTION_COUNT if invalid */
Mnemonic decodeMnemonic(EncodedInst inst, uint64_t shift);

uint8_t decodeIsImmediate(EncodedInst inst, uint64_t shift);

ConditionCode decodeConditionCode(EncodedInst inst, uint64_t shift);

DataType decodeDataType(EncodedInst inst, uint64_t shift);

RegisterCode decodeRegister(EncodedInst inst, uint64_t shift);

uint32_t decodeImmediateValue(EncodedInst inst, uint64_t shift);

void decodeCalculInstruction(EncodedInst eInst, DecodedInst *dInst);

uint8_t decodeLoadStoreInstruction(EncodedInst eInst, DecodedInst *dInst);

DecodedInst *decodeInst(EncodedInst inst);

// -=-=-=-= [ Print ] =-=-=-=-

void printMnemonic(Mnemonic mnemonic);

void printConditionCode(ConditionCode cond);

void printDataType(DataType datatype);

void printRegister(RegisterCode reg);

void printImmediateValue(uint32_t im);

void printDecodedInst(DecodedInst *inst);

void printEncodedInst(EncodedInst inst);

#endif