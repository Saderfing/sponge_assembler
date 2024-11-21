#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "sponge_errors.h"

char errorMessages[BUFFER_SIZE][BUFFER_SIZE] = { 
    "No error\n",
	"Main : arguments are either missing or wrong\n",
	
	"File : Unable to open this file\n",
    "File : Can't use a closed file\n",


	"Memory : adress out of bound\n",

	"Instruction : unknown instruction\n",
	"Instruction : division by zero\n",

	"Instruction Stream : adress out of bounds\n",

    "This error code does'nt exist\n"
};

void printError(Error errorId){
    if (errorId >= ERROR_COUNT || errorId < 0) {
        errorId = ERROR_COUNT;
    }

    printf("%s\n", errorMessages[errorId]);
}
