#ifndef _SPONGE_ERRORS_H_
#define _SPONGE_ERRORS_H_

typedef enum {
    NO_ERROR,
	USAGE_ERROR,

	FILE_OPENNING_ERROR,
    FILE_CLOSED,

	OUT_OF_BOUND,

	UNKOWN_INSTRUCTION,
	ZERO_DIVID,

	SEGMENTATION_FAULT,

    ERROR_COUNT
} Error;

void printError(Error errorId);

#endif
