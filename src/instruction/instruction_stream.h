#ifndef _INSTRUCTION_STREAM_H_
#define _INSTRUCTION_STREAM_H_
#include <stdio.h>
#include <stdlib.h>
#include "sponge_std.h"
#include "instruction.h"

typedef struct instStream {
	uint64_t length;
	uint64_t occupation;
	Inst *stream;
} InstStream;

InstStream *newInstStream();

void resetInstStream(InstStream *is);

void freeInstrStream(InstStream *is);

/* 
Precondition  : is != NULL
PostCondition : if success the is a stream size of newLength else is unchanged
Return code :
0 = SUCCESS; 1 = FAIL TO REALLOC
*/
#define REALLOC_SUCCESS 0
#define REALLOC_FAILURE 1
uint64_t reallocInstStream(uint64_t newLength, InstStream *is);

#define APPEND_SUCCESS 0
#define APPEND_EMPTY_STREAM 1
#define APPEND_INVALID_INSTRUCTION 2
#define APPEND_REALLOC_FAILURE 3 // esta il gros shit
u8 appendInstruction(Inst inst, InstStream *is);

Inst getInstFromInstStream(uint64_t index, InstStream *is);

void printInstStream(InstStream *is);

#endif
