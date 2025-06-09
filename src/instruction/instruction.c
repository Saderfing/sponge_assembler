#include "instruction.h"
#include <errno.h>


static const char *instRepr[INSTRUCTION_COUNT] = {"NOP", "AND", "ORR", "XOR", "ADD", "SUB", "MUL", "DIV", "REM", "LSL", "LSR", "LDR", "STR", "CMP", "JMP", "MOV", "MVN", "PRR", "PRM", "HLT"};

static const char *registerRepr[REGISTER_COUNT] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "lr", "fp", "sp", "pc"};

static const char *datatypeRepr[DATATYPES_COUNT] = {"B", "H", "W", "D"};

static const char *conditionRepr[CONDITION_COUNT] = {"AL", "NE", "CS", "CC", "VS", "VC", "HI", "LS", "GE", "LT", "GT", "LE", "EQ"};

EncodedInst newEncodedInst(){
	return IM_NOP;
}

DecodedInst *newDecodedInst(){
	DecodedInst *inst = (DecodedInst *)malloc(sizeof(DecodedInst));
	if (!inst){
		return NULL;
	}

	inst->mnemonic      = IM_NOP;
	inst->isImmediate    = 0;
	inst->condition      = IC_AL;
	inst->dataType       = ID_DOUB;
	inst->destRegister   = 0;
	inst->arg1Register   = 0;
	inst->arg2Register   = 0;
	inst->immediateValue = 0;

	return inst;
}

void setBits(uint64_t *dest, uint64_t src, uint64_t mask, uint64_t shift){
	*dest = ((*dest & ~(mask << shift)) | (src << shift));
}

uint64_t getBits(uint64_t src, uint64_t mask, uint64_t shift){
	return (src & ~(mask << shift)) >> mask;
}

uint8_t isValideRegisterCode(RegisterCode registerCode){
	return 0 <= registerCode && registerCode <= 15;
}


EncodedInst getPrrDecodedInst(RegisterCode registerCode){
	EncodedInst inst = newInst();

	uint64_t shift = (64 - MNEUMONIC_SIZE);
	setBits(&inst, IM_PRR, MNEUMONIC_MASK, shift);

	shift -= REGISTER_CODE_SIZE;
	setBits(&inst, registerCode, REGISTER_CODE_MASK, shift);

	return inst;
}

EncodedInst getCopyDecodedInst(Mnemonic  ic, uint8_t isImmediate, RegisterCode dest, uint64_t value){
	EncodedInst inst = newInst();
	
	uint64_t shift = 64 - MNEUMONIC_SIZE;
	setBits(&inst, ic, MNEUMONIC_MASK, shift);

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

EncodedInst getJumpDecodedInst(uint32_t value){
	EncodedInst inst = newInst();
	
	uint64_t shift = 64 - MNEUMONIC_SIZE;
	setBits(&inst, IM_JMP, MNEUMONIC_MASK, shift);

	shift = shift - IS_IMMEDIATE_SIZE;
	setBits(&inst, IMMEDIATE, IS_IMMEDIATE_MASK, shift);

	// TODO condition and datatype

	shift = shift - IMMEDIATE_VALUE_SIZE;
	setBits(&inst, value, IMMEDIATE_VALUE_MASK, shift);

	return inst;
}

EncodedInst getLoadStoreDecodedInst(Mnemonic   ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value){
	EncodedInst inst = newInst();
	
	uint64_t shift = 64 - MNEUMONIC_SIZE;
	setBits(&inst, ic, MNEUMONIC_MASK, shift);

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

EncodedInst getCalculDecodedInst(Mnemonic   ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value){
	EncodedInst inst = newInst();
	
	uint64_t shift = 64 - MNEUMONIC_SIZE;
	setBits(&inst, ic, MNEUMONIC_MASK, shift);

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

	reg++; // skipping the [rR] prefix

	uint8_t result = strtoul(reg, NULL, 10);
	
	fprintf(stderr, "reg : %d\n", result);

	return result;
}

uint8_t isValidDecodedInst(EncodedInst inst){
	return 1;
}

uint8_t decodeMnemonic(EncodedInst inst, DecodedInst){
	uint8_t mneumonic = getBits(inst, MNEUMONIC_MASK, sizeof(Inst) - MNEUMONIC_SIZE);

}

uint8_t decodeRegister(EncodedInst inst){

}

DecodedInst *decodeInst(EncodedInst inst){
	DecodedInst *i = newDecodedInst();
	uint8_t shift = 64 - MNEUMONIC_SIZE;
	
	printMnemonic(i->mnemonic);
	switch (i->mnemonic){
		case IM_AND:
		case IM_ORR:
		case IM_XOR:
		case IM_ADD:
		case IM_SUB:
		case IM_MUL:
		case IM_DIV:
		case IM_REM:
		case IM_LSL:
		case IM_LSR:
			shift -= IS_IMMEDIATE_SIZE;
			i->isImmediate = getBits(inst, IS_IMMEDIATE_MASK, shift);

			shift -= REGISTER_CODE_SIZE;
			i->destRegister = getBits(inst, REGISTER_CODE_MASK, shift);

			shift -= REGISTER_CODE_SIZE;
			i->destRegister = getBits(inst, REGISTER_CODE_MASK, shift);

			if (i->isImmediate){
				shift -= IMMEDIATE_VALUE_SIZE;
				i->immediateValue = getBits(inst, IMMEDIATE_VALUE_MASK, shift);
				printImmediateValue();
			} else {
				shift -= REGISTER_CODE_SIZE;
				i->destRegister = getBits(inst, REGISTER_CODE_MASK, shift);
				printRegister(i->destRegister);
			}

			break;


		case IM_LDR:
		case IM_STR:

		case IM_CMP:
		case IM_JMP:

		case IM_MOV:
		case IM_MVN:

		case IM_PRR:
			shift -= REGISTER_CODE_SIZE;
			i->destRegister = getBits(inst, REGISTER_CODE_MASK, shift);
			printRegister(i->destRegister);
			break;

		case IM_PRM:
			shift -= IS_IMMEDIATE_SIZE;
			i->isImmediate = getBits(inst, IS_IMMEDIATE_MASK, shift);

			if (i->isImmediate){
				shift -= IMMEDIATE_VALUE_SIZE;
				i->immediateValue = getBits(inst, IMMEDIATE_VALUE_MASK, shift);
				printImmediateValue();
			} else {
				shift -= REGISTER_CODE_SIZE;
				i->destRegister = getBits(inst, REGISTER_CODE_MASK, shift);
				printRegister(i->destRegister);
			}
			break;

		case IM_NOP:
		case IM_HLT:
			break;

		default:
			printf("Unknowned inst");
			break;
	}

	printf("\n");
}


void printMnemonic(uint8_t mnemonic){
	if (mnemonic >= INSTRUCTION_COUNT){
		printf("Unknown mnemonic");
		return;
	}

	printf("%s", instRepr[mnemonic]);
}

void printRegister(uint8_t reg){
	if (reg >= REGISTER_COUNT){
		printf("Unknown registerCode");
		return;
	}

	printf("r%s\n", registerRepr[reg]);
}



void printDecodedInst(EncodedInst inst){
	DecodedInst *i = decodeInst(inst);


}