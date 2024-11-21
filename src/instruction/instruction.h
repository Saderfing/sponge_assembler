#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_
#include <stdio.h>
#include <stdlib.h>
#include "../sponge_std/sponge_std.h"
#include "../encoding/encoding.h"

typedef u32 Inst;

Inst newInst();

Inst setInstructionCode(Inst inst, InstructionCode code);

Inst setConditionCode(Inst inst, ConditionCode code);

Inst setTypeCode(Inst inst, DataTypes code);

Inst setAsImmediate(Inst inst, bool code);

Inst setDestRegister(Inst inst, RegisterCode code);

Inst setLargeIV(Inst inst, char *iv);

Inst setFirstRegister(Inst inst, RegisterCode code);

Inst setSecondRegister(Inst inst, RegisterCode code);

Inst setSmallIV(Inst inst, char *iv);

bool isValidInst(Inst inst);

void printInstruction(Inst inst);

#endif