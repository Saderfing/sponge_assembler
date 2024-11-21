#include "instruction_stream.h"

InstStream *newInstStream(){ // NULL = FAIL
	InstStream *is = (InstStream *)allocate(sizeof(InstStream), "InstStream allocation");
	if (is == NULL){
		return NULL;
	}

	is->length = 0;
	is->occupation = 0;
	is->stream = NULL;

	return is;
}

void resetInstStream(InstStream *is){
	if (is != NULL && is->stream != NULL){
		free(is->stream);
		is->stream = NULL;
	}
	if (is != NULL){
		is->occupation = 0;
		is->length = 0;
	}
}

void freeInstrStream(InstStream *is){
	resetInstStream(is);
	if (is != NULL){
		free(is);
	}
}

/* 
Precondition  : is != NULL
PostCondition : if success the is a stream size of newLength else is unchanged
Return code :
0 = SUCCESS; 1 = FAIL TO REALLOC
*/
u32 reallocInstStream(u32 newLength, InstStream *is){
	if (is == NULL){
		return REALLOC_FAILURE;
	}

	if (newLength <= 0){
		freeInstrStream(is);
		return REALLOC_SUCCESS;
 	}

	Inst *newStream = (Inst *)realloc(is->stream, sizeof(Inst) * newLength);
	if (newStream == NULL){
		return REALLOC_FAILURE;
	}

	is->length = newLength;
	is->stream = newStream;

	return REALLOC_SUCCESS;
}

u8 appendInstruction(Inst inst, InstStream *is){
	if (is == NULL){
		return APPEND_EMPTY_STREAM;
	}
	
	if (!isValidInst(inst)){
		return APPEND_INVALID_INSTRUCTION;
	}

	u32 toAlloc = 0;
	u32 reallocCode = REALLOC_SUCCESS;
	if (is->occupation + 1 >= is->length){
		toAlloc = (is->length <= 0) ? 1 : 2 * is->length;
		reallocCode = reallocInstStream(toAlloc, is);
	}

	if (reallocCode != REALLOC_SUCCESS){
		return APPEND_REALLOC_FAILURE;
	}

	is->stream[is->occupation] = inst;
	is->occupation++;

	return APPEND_SUCCESS;
}

void printInstStream(InstStream *is){
	if(is == NULL || is->stream == NULL){
		printf("[]\n");
		return;
	}

	printf("[\n");

	for (int i = 0; i < is->length; i++){
		printInstruction(is->stream[i]);
	}
	printf("]\n");
}