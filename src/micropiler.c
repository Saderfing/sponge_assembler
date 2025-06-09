#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "parser.h"
#include "hashmap.h"
#include "instruction_stream.h"

#define PARSING_SUCCESS 0

void writeInstructionStream(FILE *f, InstStream *is){
	Inst buf;
	for (unsigned int i = 0; i < is->length; i++){
		buf = getInstFromInstStream(i, is);
		fwrite(&buf, sizeof(Inst), is->length, f);
	}
}

void printBinary(uint64_t val){
	char buffer[65];
	for (int i = 0; i < 63; i++){
		buffer[i] = '0';
	}
	buffer[64] = '\0';

	int i = 63;
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

	FILE *out = stdout;

	if (argc >= 1){
		yyin = openFile(argv[0], READ_MODE);
	}

	if (argc >= 2){
		out = openFile(argv[1], WRITE_BINARY_MODE);
	}

	InstStream *is = newInstStream();
	HashMap *symboleTable = newHashMap();

	u32 parseCode = yyparse(is, symboleTable);
	printf("\nExiting with code : %d\n", parseCode);
	
	if (parseCode == PARSING_SUCCESS){
		printf(" iiii iccc cttv dddd ffff dddd ssss ssss\n");
		for (unsigned int i = 0; i < is->length; i++){
			printInstruction(getInstFromInstStream(i, is));
			printBinary(getInstFromInstStream(i, is));
			printf("%lx\n", getInstFromInstStream(i, is));
			
		}

		writeInstructionStream(out, is);
	}
	
	freeInstrStream(is);
	freeHashMap(symboleTable);

	// closeFile(yyin);
	closeFile(yyin);
	closeFile(out);

	return 0;
}