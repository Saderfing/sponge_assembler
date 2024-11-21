#ifndef _ERROR_HANDLING_H_
#define _ERROR_HANDLING_H_
#include <stdio.h>
#include <stdlib.h>
#include "../sponge_std/sponge_std.h"

typedef enum {
	INSTRUCTION,
	CONDITION,
	DATATYPE,
	REGISTER,

	ERROR_CODE_COUNT
} ErrorCode;

void errorHandling(ErrorCode error, u32 line, char yychar);

#endif