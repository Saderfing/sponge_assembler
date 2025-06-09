#include "instruction.h"
#include <errno.h>


char *instructionRepr[INSTRUCTION_COUNT] = {"NOP", "MOV", "MVN", "AND", "ORR", "XOR", "ADD", "SUB", "MUL", "DIV", "REM", "LSL", "LSR", "LDR", "STR", "CMP", "JMP", "PRR", "PRM", "HLT"};

char *registerRepr[REGISTER_COUNT] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "lr", "fp", "sp", "pc"};

char *datatypeRepr[DATATYPES_COUNT] = {"B", "H", "W", "D"};

char *conditionRepr[CONDITION_COUNT] = {"AL", "NE", "CS", "CC", "VS", "VC", "HI", "LS", "GE", "LT", "GT", "LE", "EQ"};

Inst newInst(){
	return IM_NOP;
}

void setBits(uint64_t *dest, uint64_t data, uint64_t mask, uint64_t shift){
	*dest = ((*dest & ~(mask << shift)) | (data << shift));
}

uint8_t isValideRegisterCode(RegisterCode registerCode){
	return 0 <= registerCode && registerCode <= 15;
}

Inst getPrrInstruction(RegisterCode registerCode){
	Inst inst = newInst();

	uint64_t shift = (64 - INSTRUCTION_CODE_SIZE);
	setBits(&inst, IM_PRR, INSTRUCTION_CODE_MASK, shift);

	shift -= REGISTER_CODE_SIZE;
	setBits(&inst, registerCode, REGISTER_CODE_MASK, shift);

	return inst;
}

Inst getCopyInstruction(InstructionCode ic, uint8_t isImmediate, RegisterCode dest, uint64_t value){
	Inst inst = newInst();
	
	uint64_t shift = 64 - INSTRUCTION_CODE_SIZE;
	setBits(&inst, ic, INSTRUCTION_CODE_MASK, shift);

	shift = shift - IS_IMMEDIATE_SIZE;
	setBits(&inst, isImmediate, IS_IMMEDIATE_MASK, shift);

	// TODO condition and datatype

	shift = shift - REGISTER_CODE_SIZE;
	setBits(&inst, dest, REGISTER_CODE_MASK, shift);

	if (isImmediate){
		shift = shift - IMMEDIATE_VALUE_SIZE;
		setBits(&inst, value, IMMEDIATE_VALUE_MASK, shift);
	} else {
		shift = shift - REGISTER_CODE_SIZE;
		setBits(&inst, value, REGISTER_CODE_MASK, shift);
	}

	return inst;
}

Inst getJumpInstruction(uint32_t value){
	Inst inst = newInst();
	
	uint64_t shift = 64 - INSTRUCTION_CODE_SIZE;
	setBits(&inst, IM_JMP, INSTRUCTION_CODE_MASK, shift);

	shift = shift - IS_IMMEDIATE_SIZE;
	setBits(&inst, IMMEDIATE, IS_IMMEDIATE_MASK, shift);

	// TODO condition and datatype

	shift = shift - IMMEDIATE_VALUE_SIZE;
	setBits(&inst, value, IMMEDIATE_VALUE_MASK, shift);

	return inst;
}

Inst getLoadStoreInstruction(InstructionCode ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value){
	Inst inst = newInst();
	
	uint64_t shift = 64 - INSTRUCTION_CODE_SIZE;
	setBits(&inst, ic, INSTRUCTION_CODE_MASK, shift);

	shift = shift  - IS_IMMEDIATE_SIZE;
	setBits(&inst, isImmediate, IS_IMMEDIATE_MASK, shift);

	// TODO condition and datatype

	shift = shift - REGISTER_CODE_SIZE;
	setBits(&inst, dest, REGISTER_CODE_MASK, shift);

	shift = shift - REGISTER_CODE_SIZE;
	setBits(&inst, src, REGISTER_CODE_MASK, shift);

	if (isImmediate){
		shift = shift - IMMEDIATE_VALUE_SIZE;
		setBits(&inst, value, IMMEDIATE_VALUE_MASK, shift);
	} else {
		shift = shift - REGISTER_CODE_SIZE;
		setBits(&inst, value, REGISTER_CODE_MASK, shift);
	}

	return inst;
}

Inst getCalculInstruction(InstructionCode ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value){
	Inst inst = newInst();
	
	uint64_t shift = 64 - INSTRUCTION_CODE_SIZE;
	setBits(&inst, ic, INSTRUCTION_CODE_MASK, shift);

	shift = shift  - IS_IMMEDIATE_SIZE;
	setBits(&inst, isImmediate, IS_IMMEDIATE_MASK, shift);

	// TODO condition and datatype

	shift = shift - REGISTER_CODE_SIZE;
	setBits(&inst, dest, REGISTER_CODE_MASK, shift);

	shift = shift - REGISTER_CODE_SIZE;
	setBits(&inst, src, REGISTER_CODE_MASK, shift);

	if (isImmediate){
		shift = shift - IMMEDIATE_VALUE_SIZE;
		setBits(&inst, value, IMMEDIATE_VALUE_MASK, shift);
	} else {
		shift = shift - REGISTER_CODE_SIZE;
		setBits(&inst, value, REGISTER_CODE_MASK, shift);
	}

	return inst;
}

// -------- [  ] ---------

uint32_t getImmediateValue(char *value, int base){
	if (value == NULL){
		return 0;
	}

	if (base != 10 && strlen(value) > 2){ // we are expecting a 2 character long prefix for every bases other then 10
		value += 2;
	}

	uint32_t result = strtoul(value, NULL, base);

	if (errno == EINVAL){
		fatalError(INVALIDE_IMMEDIATE_VALUE);
	}

	if (errno == ERANGE){
		fprintf(stderr, "Warning : %s is out of range, value truncated to %d", value, result);
	}

	return result;
}

uint8_t getRegisterCode(char *reg){
	if (reg == NULL){
		fatalError(NULL_REGISTER);
	}



	uint8_t result = strtoul(reg, NULL, 10);
	
	fprintf(stderr, "reg : %d\n", result);

	return result;
}

uint8_t isValidInstruction(Inst inst){
	return 1;
}

void printInstruction(Inst inst){
	printAsBinary(inst);
}