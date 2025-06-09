#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "instruction_encoding.h"

typedef uint64_t Inst;

#define DEFAULT_INSTRUCTION NOP


Inst newInst();


Inst getPrrInstruction(RegisterCode registerCode);

Inst getCopyInstruction(InstructionCode ic, uint8_t isImmediate, RegisterCode dest, uint64_t value);

Inst getJumpInstruction(uint32_t value);

Inst getLoadStoreInstruction(InstructionCode ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value);

Inst getCalculInstruction(InstructionCode ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value);


uint32_t getImmediateValue(char *value, int base);

uint8_t getRegisterCode(char *reg);

uint8_t isValidInstruction(Inst inst);

void printInstruction(Inst inst);

#endif