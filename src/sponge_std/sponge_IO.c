#include "sponge_IO.h"

#define END_STRING '\0'

char *F_RED = "\033[0;31m";
char *F_GREEN = "\033[0;32m";
char *F_YELLOW = "\033[0;33m";
char *F_BLUE = "\033[0;34m";
char *F_WHITE = "\033[0;39m";

bool isNullFile(FILE *f){
    return f == NULL;
}

FILE *openFile(char *fileName, char *mode){
    FILE *f = fopen(fileName, mode);

    if (isNullFile(f)){
        fatalError(FILE_OPENNING_ERROR);
    }

    return f;
}

/*Read a line in the */
int getLine(FILE *f, char destBuffer[], int destSize){
    if (feof(f) || destBuffer <= 0){
        return 1;
    }
    char c = fgetc(f);
    int i = 0;
    

    while (c != EOF && c != '\n' && i + 1 < destSize){
        destBuffer[i] = c;
        c = fgetc(f);
        i++;
    }

    destBuffer[i] = '\0';

    return 0;
}

void printRawChar(char c){
	if (c == ' '){
		printf("(space) ");

	} else if (c == '\n'){
		printf("\\n\n");

	} else if (c == '\t'){
		printf("\\t\t");

	} else {
		printf("%c", c);
	}
}
