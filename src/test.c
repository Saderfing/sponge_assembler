#include <stdio.h>
#include <stdlib.h>
#include "sponge_std/sponge_std.h"
#include "parser/parser.h"
#include "hashmap/hashmap.h"
#include "instruction/instruction_stream.h"

void printBinary(char *name, u32 val){
	printf("%s", name);
	char buffer[33];
	for (int i = 0; i < 31; i++){
		buffer[i] = '0';
	}
	buffer[32] = '\0';

	int i = 31;
	while (val > 0){
		buffer[i] = (val % 2) + '0';
		val = val / 2;
		i--;
	}
	printf("%s\n", buffer);
}

void printTitle(char *title){
	printf("\n-=-=-=-=-=- [ %s ] -=-=-=-=-=-\n\n", title);
}

int main(int argc, char *argv[]){
	srand(atoi(argv[1]));
	
	Inst inst = newInst();
	printInstruction(inst);
	printTitle("Mask");

	printBinary("Inst    : ", instructionMask << instructionShift);
	printBinary("Cond    : ", conditionMask << conditionShift);
	printBinary("Type    : ", typeMask << typeShift);
	printBinary("IsImm   : ", isImmediateMask << isImmediateShift);
	printBinary("Dr      : ", destRegisterMask << destRegisterShift);
	printBinary("SmallIV : ", simpleIVArgMask << simpleIVArgShift);
	printBinary("Fr      : ", firstRegArgMask << firstRegArgShift);
	printBinary("Dr      : ", secondRegArgMask << secondRegArgShift);
	printBinary("LargeIV : ", secondIVArgMask << secondIVArgShift);

	printTitle("Instruction");

	return 0;
}