#include "instruction.h"
#include <errno.h>


static const char *instRepr[MNEMONIC_COUNT]       = {"NOP", "AND", "ORR", "XOR", "ADD", "SUB", "MUL", "DIV", "REM", "LSL", "LSR", "LDR", "STR", "CMP", "JMP", "MOV", "MVN", "PRR", "PRM", "HLT"};

static const char *registerRepr[REGISTER_COUNT]   = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "lr", "fp", "sp", "pc"};

static const char *datatypeRepr[DATATYPES_COUNT]  = {"B", "H", "W", "D"};

static const char *conditionRepr[CONDITION_COUNT] = {"AL", "NE", "CS", "CC", "VS", "VC", "HI", "LS", "GE", "LT", "GT", "LE", "EQ"};

EncodedInst newEncodedInst(){
	return IM_NOP;
}

void resetDecodedInst(DecodedInst *inst){
	if(!inst){
		return;
	}

	inst->mnemonic       = IM_NOP;
	inst->isImmediate    = NOT_SET_IMMEDIATE;
	inst->condition      = IC_INVALID_CONDITION;
	inst->dataType       = ID_INVALID_DATATYPE;
	inst->destRegister   = IR_INVALID_REGISTER;
	inst->arg1Register   = IR_INVALID_REGISTER;
	inst->arg2Register   = IR_INVALID_REGISTER;
	inst->immediateValue = 0;
}

DecodedInst *newDecodedInst(){
	DecodedInst *inst = (DecodedInst *)malloc(sizeof(DecodedInst));
	if (!inst){
		return NULL;
	}

	resetDecodedInst(inst);
	return inst;
}

void freeDecodedInst(DecodedInst **inst){
	if (!inst || !*inst){
		return;
	}

	resetDecodedInst(*inst);
	
	free(*inst);
	*inst = NULL;
}

void setBits(uint64_t *dest, uint64_t src, uint64_t mask, uint64_t shift){
	*dest = ((*dest & ~(mask << shift)) | (src << shift));
}

uint64_t getBits(uint64_t src, uint64_t mask, uint64_t shift){
	return (src & (mask << shift)) >> shift;
}

// -=-=-=-=[ Valid ]=-=-=-=-
#define IS_VALID_MNEMONIC(mnemonic) (mnemonic < IM_INVALID_MNEMONIC)

#define IS_VALID_IS_IMMEDIATE(isImmediate) (isImmediate < NOT_SET_IMMEDIATE)

#define IS_VALID_CONDITION_CODE(condition) (0 <= condition && condition < IC_INVALID_CONDITION)

#define IS_VALID_DATATYPE(datatype) (0 <= datatype && datatype < ID_INVALID_DATATYPE)

#define IS_VALID_REGISTER_CODE(registerCode) (0 <= registerCode && registerCode < IR_INVALID_REGISTER)

bool isValidEncodedInst(EncodedInst inst){
	return 1;
}

bool isCalculInstruction(Mnemonic mnemonic){
	switch(mnemonic){
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
			return true;

		default:
			return false;
	}
}

bool isLoadStoreInstruction(Mnemonic mnemonic){
	switch(mnemonic){
		case IM_LDR:
		case IM_STR:
			return true;

		default:
			return false;
	}
}

bool isBinInstruction(Mnemonic mnemonic){
	switch(mnemonic){
		case IM_CMP:
		case IM_MVN:
		case IM_MOV:
			return true;

		default:
			return false;
	}
}

bool isJumpInstruction(Mnemonic mnemonic){
	switch(mnemonic){
		case IM_JMP:
			return true;

		default:
			return false;
	}
}

bool isPrintRegisterInstruction(Mnemonic mnemonic){
	switch(mnemonic){
		case IM_PRR:
			return true;

		default:
			return false;
	}
}

bool isPrintMemoryRegisterInstruction(Mnemonic mnemonic){
	switch(mnemonic){
		case IM_PRM:
			return true;

		default:
			return false;
	}
}


bool isValidCalculInstruction(DecodedInst *i){
	if (!isCalculInstruction(i->mnemonic) || !IS_VALID_IS_IMMEDIATE(i->isImmediate)){
		return false;
	}

	if (i->immediateValue){
		return IS_VALID_REGISTER_CODE(i->destRegister) && IS_VALID_REGISTER_CODE(i->arg1Register);
	} else {
		return IS_VALID_REGISTER_CODE(i->destRegister) && IS_VALID_REGISTER_CODE(i->arg1Register) && IS_VALID_REGISTER_CODE(i->arg2Register);
	}
}

bool isValidLoadStoreInstruction(DecodedInst *i){
	if (!isLoadStoreInstruction(i->mnemonic) || !IS_VALID_IS_IMMEDIATE(i->isImmediate)){
		return false;
	}

	if (i->immediateValue){
		return IS_VALID_REGISTER_CODE(i->destRegister) && IS_VALID_REGISTER_CODE(i->arg1Register);
	} else {
		return IS_VALID_REGISTER_CODE(i->destRegister) && IS_VALID_REGISTER_CODE(i->arg1Register) && IS_VALID_REGISTER_CODE(i->arg2Register);
	}
}

bool isValidBinOperation(DecodedInst *i){
	if (!isBinInstruction(i->mnemonic) || !IS_VALID_IS_IMMEDIATE(i->isImmediate)){
		return false;
	}

	if (i->immediateValue){
		return IS_VALID_REGISTER_CODE(i->destRegister);
	} else {
		return IS_VALID_REGISTER_CODE(i->destRegister) && IS_VALID_REGISTER_CODE(i->arg1Register);
	}
}

bool isValidJumpInstruction(DecodedInst *i){
	if (!isJumpInstruction(i->mnemonic) || !IS_VALID_IS_IMMEDIATE(i->isImmediate)){
		return false;
	}

	if (!i->immediateValue){
		return IS_VALID_REGISTER_CODE(i->destRegister);
	}

	return true;
}


bool isValidPrintRegisterInstruction(DecodedInst *i){
	if (!isPrintRegisterInstruction(i->mnemonic) || !IS_VALID_IS_IMMEDIATE(i->isImmediate)){
		return false;
	}

	if (i->immediateValue){
		return IS_VALID_REGISTER_CODE(i->destRegister) && IS_VALID_REGISTER_CODE(i->arg1Register);
	} else {
		return IS_VALID_REGISTER_CODE(i->destRegister) && IS_VALID_REGISTER_CODE(i->arg1Register) && IS_VALID_REGISTER_CODE(i->arg2Register);
	}
}


bool isValidPrintMemoryInstruction(DecodedInst *i){
	if (!isPrintMemoryRegisterInstruction(i->mnemonic) || !IS_VALID_IS_IMMEDIATE(i->isImmediate)){
		return false;
	}

	if (!i->immediateValue){
		return IS_VALID_REGISTER_CODE(i->destRegister);
	}

	return true;
}

// -=-=-=-=[ Create encoded instruction ]=-=-=-=-
EncodedInst getPrrEncodedInst(RegisterCode registerCode){
	EncodedInst inst = newEncodedInst();

	uint64_t shift = (64 - MNEMONIC_SIZE);
	setBits(&inst, IM_PRR, MNEMONIC_MASK, shift);

	shift -= REGISTER_CODE_SIZE;
	setBits(&inst, registerCode, REGISTER_CODE_MASK, shift);

	return inst;
}

EncodedInst getCopyEncodedInst(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, uint64_t value){
	EncodedInst inst = newEncodedInst();
	
	uint64_t shift = 64 - MNEMONIC_SIZE;
	setBits(&inst, ic, MNEMONIC_MASK, shift);

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

EncodedInst getJumpEncodedInst(uint8_t isImmediate, uint32_t value){
	EncodedInst inst = newEncodedInst();
	
	uint64_t shift = 64 - MNEMONIC_SIZE;
	setBits(&inst, IM_JMP, MNEMONIC_MASK, shift);

	shift = shift - IS_IMMEDIATE_SIZE;
	setBits(&inst, isImmediate, IS_IMMEDIATE_MASK, shift);

	// TODO condition and datatype

	shift = shift - IMMEDIATE_VALUE_SIZE;
	setBits(&inst, value, IMMEDIATE_VALUE_MASK, shift);

	return inst;
}

EncodedInst getLoadStoreEncodedInst(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value){
	EncodedInst inst = newEncodedInst();
	
	uint64_t shift = 64 - MNEMONIC_SIZE;
	setBits(&inst, ic, MNEMONIC_MASK, shift);

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

EncodedInst getCalculEncodedInst(Mnemonic ic, uint8_t isImmediate, RegisterCode dest, RegisterCode src, uint32_t value){
	EncodedInst inst = newEncodedInst();
	
	uint64_t shift = 64 - MNEMONIC_SIZE;
	setBits(&inst, ic, MNEMONIC_MASK, shift);

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

// -=-=-=-= [ Decoder ] =-=-=-=-

/* Decode the mnemonic of the instruction
		Return : mnemonic
		INSTRUCTION_COUNT if invalid */
Mnemonic decodeMnemonic(EncodedInst inst, uint64_t shift){
	uint64_t mnemonic = getBits(inst, MNEMONIC_MASK, shift);
	if (IS_VALID_MNEMONIC(mnemonic)){
		return mnemonic;
	}

	return IM_INVALID_MNEMONIC;
}

uint8_t decodeIsImmediate(EncodedInst inst, uint64_t shift){
	return getBits(inst, IS_IMMEDIATE_MASK, shift);
}

ConditionCode decodeConditionCode(EncodedInst inst, uint64_t shift){
	ConditionCode cond = getBits(inst, CONDITION_MASK, shift);
	if (IS_VALID_CONDITION_CODE(cond)){
		return cond;
	}

	return IC_INVALID_CONDITION;
}

DataType decodeDataType(EncodedInst inst, uint64_t shift){
	DataType dt = getBits(inst, DATATYPE_MASK, shift);
	if (IS_VALID_DATATYPE(dt)){
		return dt;
	}

	return ID_INVALID_DATATYPE;
}

RegisterCode decodeRegister(EncodedInst inst, uint64_t shift){
	RegisterCode reg = getBits(inst, REGISTER_CODE_MASK, shift);
	if (IS_VALID_REGISTER_CODE(reg)){
		return reg;
	}

	return IR_INVALID_REGISTER;
}

uint32_t decodeImmediateValue(EncodedInst inst, uint64_t shift){
	return getBits(inst, IMMEDIATE_VALUE_MASK, shift);
}

void decodeCalculInstruction(EncodedInst eInst, DecodedInst *dInst){
	uint8_t shift = 64 - MNEMONIC_SIZE;
	dInst->mnemonic = decodeMnemonic(eInst, shift);

	shift -= IS_IMMEDIATE_SIZE;
	dInst->isImmediate = decodeIsImmediate(eInst, shift);

	shift -= REGISTER_CODE_SIZE;
	dInst->destRegister = decodeRegister(eInst, shift);

	shift -= REGISTER_CODE_SIZE;
	dInst->arg1Register = decodeRegister(eInst, shift);

	if (dInst->isImmediate){
		shift -= IMMEDIATE_VALUE_SIZE;
		dInst->immediateValue = decodeImmediateValue(eInst, shift);
	} else {
		shift -= REGISTER_CODE_SIZE;
		dInst->arg2Register = decodeRegister(eInst, shift);
	}
}

uint8_t decodeLoadStoreInstruction(EncodedInst eInst, DecodedInst *dInst){
	uint8_t shift = 64 - MNEMONIC_SIZE;
	dInst->mnemonic = decodeMnemonic(eInst, shift);

	if (!isLoadStoreInstruction(dInst->mnemonic)){
		resetDecodedInst(dInst);
		return -1;
	}

	shift -= IS_IMMEDIATE_SIZE;
	dInst->isImmediate = decodeIsImmediate(eInst, shift);

	shift -= REGISTER_CODE_SIZE;
	dInst->destRegister = decodeRegister(eInst, shift);

	shift -= REGISTER_CODE_SIZE;
	dInst->arg1Register = decodeRegister(eInst, shift);

	if (dInst->isImmediate){
		shift -= IMMEDIATE_VALUE_SIZE;
		dInst->immediateValue = decodeImmediateValue(eInst, shift);
	} else {
		shift -= REGISTER_CODE_SIZE;
		dInst->arg2Register = decodeRegister(eInst, shift);
	}

	return isValidLoadStoreInstruction(dInst);
}

void decodeBinaryInstruction(EncodedInst inst, DecodedInst *dInst){
	uint8_t shift = 64 - MNEMONIC_SIZE;

	shift -= IS_IMMEDIATE_SIZE;
	dInst->isImmediate = decodeIsImmediate(inst, shift);

	shift -= REGISTER_CODE_SIZE;
	dInst->destRegister = decodeRegister(inst, shift);

	if (dInst->isImmediate){
		shift -= IMMEDIATE_VALUE_SIZE;
		dInst->immediateValue = decodeImmediateValue(inst, shift);
	} else {
		shift -= REGISTER_CODE_SIZE;
		dInst->arg1Register = decodeRegister(inst, shift);
	}
}

void decodeJumpInstruction(EncodedInst inst, DecodedInst *dInst){
	uint8_t shift = 64 - MNEMONIC_SIZE;

	shift -= IS_IMMEDIATE_SIZE;
	dInst->isImmediate = decodeIsImmediate(inst, shift);

	if (dInst->isImmediate){
		shift -= IMMEDIATE_VALUE_SIZE;
		dInst->immediateValue = decodeImmediateValue(inst, shift);
	} else {
		shift -= REGISTER_CODE_SIZE;
		dInst->destRegister = decodeRegister(inst, shift);
	}
}

DecodedInst *decodeInst(EncodedInst inst){
	DecodedInst *dInst = newDecodedInst();
	uint8_t shift = 64 - MNEMONIC_SIZE;
	dInst->mnemonic = decodeMnemonic(inst, shift);

	switch (dInst->mnemonic){
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
			decodeCalculInstruction(inst, dInst);
			break;

		case IM_LDR:
		case IM_STR:
			decodeLoadStoreInstruction(inst, dInst);
			break;

		case IM_CMP:
		case IM_MVN:
		case IM_MOV:
			decodeBinaryInstruction(inst, dInst);
			break;

		case IM_JMP:
			decodeJumpInstruction(inst, dInst);
			break;

		case IM_PRR:
			shift -= REGISTER_CODE_SIZE;
			dInst->destRegister = getBits(inst, REGISTER_CODE_MASK, shift);
			break;

		case IM_PRM:
			shift -= IS_IMMEDIATE_SIZE;
			dInst->isImmediate = getBits(inst, IS_IMMEDIATE_MASK, shift);

			if (dInst->isImmediate){
				shift -= IMMEDIATE_VALUE_SIZE;
				dInst->immediateValue = getBits(inst, IMMEDIATE_VALUE_MASK, shift);
				printImmediateValue(dInst->isImmediate);
			} else {
				shift -= REGISTER_CODE_SIZE;
				dInst->destRegister = getBits(inst, REGISTER_CODE_MASK, shift);
				printRegister(dInst->destRegister);
			}
			break;

		case IM_NOP:
		case IM_HLT:
			break;

		default:
			resetDecodedInst(dInst);
			break;
	}

	return dInst;
}

// -=-=-=-= [ Print ] =-=-=-=-

void printMnemonic(Mnemonic mnemonic){
	if (!IS_VALID_MNEMONIC(mnemonic)){
		printf("Unknown mnemonic");
		return;
	}

	printf("%s", instRepr[mnemonic]);
}

void printConditionCode(ConditionCode cond){
	if (!IS_VALID_CONDITION_CODE(cond)){
		printf("Unknown cond");
		return;
	}

	printf("%s", conditionRepr[cond]);
}

void printDataType(DataType datatype){
	if (!IS_VALID_DATATYPE(datatype)){
		printf("Unknown datatype");
		return;
	}

	printf("%s", datatypeRepr[datatype]);
}

void printRegister(RegisterCode reg){
	if (!IS_VALID_REGISTER_CODE(reg)){
		printf("Unknown registerCode");
		return;
	}

	printf("%s", registerRepr[reg]);
}

void printImmediateValue(uint32_t im){
	printf("#%x", im);
}

void printDecodedInst(DecodedInst *inst){
	switch (inst->mnemonic){
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
			printMnemonic(inst->mnemonic);
			printf(" ");
			printRegister(inst->destRegister);
			printf(" ");
			printRegister(inst->arg1Register);
			printf(" ");

			if(inst->isImmediate){
				printImmediateValue(inst->immediateValue);
			} else {
				printRegister(inst->arg2Register);
			}
			printf("\n");
			break;

		case IM_LDR:
		case IM_STR:
			printMnemonic(inst->mnemonic);
			printf(" ");
			printRegister(inst->destRegister);
			printf(" ");
			printRegister(inst->arg1Register);
			printf(" ");

			if(inst->isImmediate){
				printImmediateValue(inst->immediateValue);
			} else {
				printRegister(inst->arg2Register);
			}
			printf("\n");
			break;

		case IM_CMP:
		case IM_MVN:
		case IM_MOV:
			printMnemonic(inst->mnemonic);
			printf(" ");
			printRegister(inst->destRegister);
			printf(" ");

			if(inst->isImmediate){
				printImmediateValue(inst->immediateValue);
			} else {
				printRegister(inst->arg1Register);
			}
			printf("\n");
			break;

		case IM_JMP:
			printMnemonic(inst->mnemonic);
			printf(" ");

			if(inst->isImmediate){
				printImmediateValue(inst->immediateValue);
			} else {
				printRegister(inst->arg2Register);
			}
			printf("\n");
			break;

		case IM_PRR:
			printMnemonic(inst->mnemonic);
			printf(" ");
			printRegister(inst->destRegister);
			printf("\n");
			break;

		case IM_PRM:
			printMnemonic(inst->mnemonic);
			printf(" ");
			printRegister(inst->destRegister);
			printf(" ");
			printRegister(inst->arg1Register);
			printf(" ");

			if(inst->isImmediate){
				printImmediateValue(inst->immediateValue);
			} else {
				printRegister(inst->arg2Register);
			}
			printf("\n");	
			break;

		case IM_NOP:
		case IM_HLT:
			printMnemonic(inst->mnemonic);
			break;

		default:
			printf("Unknown instruction\n");
			resetDecodedInst(inst);
			break;
	}
}

void printEncodedInst(EncodedInst inst){
	DecodedInst *dInst = decodeInst(inst);
	printf("Inst : %lx\n", inst);
	printf(DOUBLE_TO_BINARY_PATTERN"\n", DOUBLE_TO_BINARY(inst));
	printDecodedInst(dInst);
	freeDecodedInst(&dInst);
}
