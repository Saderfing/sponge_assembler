#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "instruction_encoding.h"

typedef uint64_t EncodedInst; // Encoded instruction

typedef struct instruction{
	uint8_t mnemonic;
	uint8_t isImmediate;
	uint8_t condition;
	uint8_t dataType;
	uint8_t destRegister;
	uint8_t arg1Register;
	uint8_t arg2Register;
	uint32_t immediateValue;
} DecodedInst; // Decoded instruction

typedef DecodedInst Inst; // Easier because im lazy

#define DEFAULT_INSTRUCTION NOP


EncodedInst newEncodedInst();


EncodedInst getPrrInstruction(RegisterCode registerCode);

EncodedInst getCopyInstruction(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, uint64_t value);

EncodedInst getJumpInstruction(uint32_t value);

EncodedInst getLoadStoreInstruction(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value);

EncodedInst getCalculInstruction(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value);


uint32_t getImmediateValue(char *value, int base);

uint8_t getRegisterCode(char *reg);

uint8_t isValidInstruction(EncodedInst inst);

void printInstruction(EncodedInst inst);

#endif