#include <stdio.h>
#include <stdlib.h>
#include "sponge_std/sponge_std.h"
#include "parser/parser.h"
#include "hashmap/hashmap.h"
#include "instruction/instruction_stream.h"

#define PARSING_SUCCESS 0

void writeInstructionStream(FILE *f, InstStream *is){
	for (int i = 0; i < is->length; i++){
		fwrite(is->stream, sizeof(Inst), is->length, f);
	}
}

void printBinary(u32 val){
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
	
	i = 0;
	while (buffer[i] != '\0'){
		if (i % 4 == 0){
			printf(" ");
		}
		printf("%c", buffer[i]);
		i++;
	}
	printf("\n");
}


int main(int argc, char *argv[]){
	argc--; argv++;
	
	yyin = stdin;
	FILE *yyout = stdout;

	if (argc >= 1){
		yyin = openFile(argv[0], READ_MODE);
	}

	if (argc >= 2){
		yyout = openFile(argv[1], WRITE_BINARY_MODE);
	}

	InstStream *is = newInstStream();
	HashMap *symboleTable = newHashMap();

	u32 parseCode = yyparse(is, symboleTable);
	printf("\nExiting with code : %d\n", parseCode);
	
	if (parseCode == PARSING_SUCCESS){
		printf(" iiii iccc cttv dddd ffff dddd ssss ssss\n");
		for (int i = 0; i < is->length; i++){
			printInstruction(is->stream[i]);
			printBinary(is->stream[i]);
		}

		writeInstructionStream(yyout, is);
	}
	
	closeFile(yyin);
	closeFile(yyout);

	return 0;
}