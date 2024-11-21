#include "instruction.h"

char *instructionRepr[INSTRUCTION_COUNT] = {"NOP", "MOV", "MVN", "AND", "ORR", "XOR", "ADD", "SUB", "MUL", "DIV", "REM", "LSL", "LSR", "PSH", "POP", "LDR", "LDREND", "STR", "CMP", "JMP", "PRR", "PRM", "END"};

char *registerRepr[REGISTER_COUNT] = {"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "lr", "fp", "sp", "pc"};

char *datatypeRepr[DATATYPES_COUNT] = {"B", "H", "W", "D"};

char *conditionRepr[CONDITION_COUNT] = {"AL", "NE", "CS", "CC", "VS", "VC", "HI", "LS", "GE", "LT", "GT", "LE", "EQ"};

#define MINUS_SIGN '-'

i16 ivExtraction(char *value){
	// i16 iv = 0;
	// i8 sign = 1;
	// u32 i = 1; // As the 1st caracter is always a # we can ignore it
	// while (value[i] != END_STRING){
	// 	if (isdigit(value[i])){
	// 		iv *= 10;
	// 		iv += (value[i] - '0');
	// 	} else if (value[i] == MINUS_SIGN){
	// 		sign = -1;
	// 	}
	// 	i++;
	// }
	
	// return (sign * iv) % INT16_MAX;
	return 0xFF;
}

Inst newInst(){
	return NOP;
}

Inst setInstructionCode(Inst inst, InstructionCode code){
	return (inst & ~(u32)(instructionMask << instructionShift)) | (code << instructionShift);
}

Inst setConditionCode(Inst inst, ConditionCode code){
	return (inst & ~(conditionMask << conditionShift)) | (code << conditionShift);
}

Inst setTypeCode(Inst inst, DataTypes code){
	return (inst & ~(typeMask << typeShift)) | (code << typeShift);
}

Inst setAsImmediate(Inst inst, bool code){
	return (inst & ~(isImmediateMask << isImmediateShift)) | (code << isImmediateShift);
}

Inst setDestRegister(Inst inst, RegisterCode code){
	return (inst & ~(destRegisterMask << destRegisterShift)) | (code << destRegisterShift);
}

Inst setLargeIV(Inst inst, char *iv){
	i8 value = ivExtraction(iv);
	return (inst & ~(simpleIVArgMask << simpleIVArgShift)) | (value << simpleIVArgShift);
}

Inst setFirstRegister(Inst inst, RegisterCode code){
	return (inst & ~(firstRegArgMask << firstRegArgShift)) | (code << firstRegArgShift);
}

Inst setSecondRegister(Inst inst, RegisterCode code){
	return (inst & ~(secondRegArgMask << secondRegArgShift)) | (code << secondRegArgShift);
}

Inst setSmallIV(Inst inst, char *iv){;
	i8 value = ivExtraction(iv);
	return (inst & ~(secondIVArgMask << secondIVArgShift)) | (value << secondIVArgShift);
}



bool isValidInst(Inst inst){
	InstructionCode instCode	= (inst & (instructionMask << instructionShift)) >> instructionShift;
	ConditionCode condCode		= (inst & (conditionMask << conditionShift)) >> conditionShift;
	DataTypes dataCode			= (inst & (typeMask << typeShift)) >> typeShift;
	RegisterCode destRegister	= (inst & (destRegisterMask << destRegisterShift)) >> destRegisterShift;
	RegisterCode fr				= (inst & (firstRegArgMask << firstRegArgShift)) >> firstRegArgShift;
	RegisterCode sr				= (inst & (secondRegArgMask << secondRegArgShift)) >> secondRegArgShift;

	return instCode < INSTRUCTION_COUNT && condCode < CONDITION_COUNT && dataCode < DATATYPES_COUNT && destRegister < REGISTER_COUNT && fr < REGISTER_COUNT && sr < REGISTER_COUNT;
}

void printInstruction(Inst inst){
	if (!isValidInst(inst)){
		printf("ERROR : Unkown instruction\n");
		return;
	}

	// probably not optimized (>>)
	InstructionCode instCode	= (inst & (instructionMask << instructionShift)) >> instructionShift;
	ConditionCode condCode		= (inst & (conditionMask << conditionShift)) >> conditionShift;
	DataTypes dataCode			= (inst & (typeMask << typeShift)) >> typeShift;
	RegisterCode destRegister	= (inst & (destRegisterMask << destRegisterShift)) >> destRegisterShift;
	
	bool isImmediat = 0;
	u16 largeIV = 0;
	RegisterCode fr				= (inst & (firstRegArgMask << firstRegArgShift)) >> firstRegArgShift;
	RegisterCode sr				= (inst & (secondRegArgMask << secondRegArgShift)) >> secondRegArgShift;
	u8 smallIV = 0;

	//printf("Inst : %d & cond : %d & data %d & dr : %d & im : %d & large iv : %d & fr : %d & sr : %d & smalliv : %d\n", instCode, condCode, dataCode, destRegister, isImmediat, largeIV, fr, sr, smallIV);

	switch (instCode){
	case ADD:
	case AND:
	case DIV:
	case LSL:
	case LSR:
	case MUL:
	case ORR:
	case REM:
	case SUB:
	case XOR:
		printf("%s%s%s %s %s ", instructionRepr[instCode], conditionRepr[condCode], datatypeRepr[dataCode], registerRepr[destRegister], registerRepr[fr]);
		isImmediat = (inst & (isImmediateMask << isImmediateShift)) >> isImmediateShift;
		
		if (isImmediat){
			smallIV = (inst & (secondIVArgMask << secondIVArgShift)) >> secondIVArgShift;
			printf("#%d\n", smallIV);
		} else {
			printf("%s\n", registerRepr[sr]);
		}
		break;
	
	case CMP:
	case MOV:
	case MVN:
	case STR:
		printf("%s%s%s %s ", instructionRepr[instCode], conditionRepr[condCode], datatypeRepr[dataCode], registerRepr[destRegister]);
		isImmediat = (inst & (isImmediateMask << isImmediateShift)) >> isImmediateShift;
		
		if (isImmediat){
			largeIV = (inst & (simpleIVArgMask << simpleIVArgShift)) >> simpleIVArgShift;
			printf("#%d\n", largeIV);
		} else {
			fr = 
			printf("%s\n", registerRepr[fr]);
		}
		break;
	
	case PRM:
	case PRR:
	case PSH:
	case POP:
		printf("%s%s%s %s ", instructionRepr[instCode], conditionRepr[condCode], datatypeRepr[dataCode], registerRepr[destRegister]);
		break;

	case LDR:
	case LDREND:
			printf("%s%s%s %s ", instructionRepr[instCode], conditionRepr[condCode], datatypeRepr[dataCode], registerRepr[destRegister]);
		break;	
	case JMP:


	default:
		break;
	}

}