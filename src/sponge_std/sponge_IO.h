#ifndef _SPONGE_FILES_H_
#define _SPONGE_FILES_H_

#include "sponge_std.h"
#include "sponge_errors.h"
//#include "token.h"

#define READ_MODE "r"
#define READ_BINARY_MODE "rb"
#define READ_MODE_PLUS "r+"
#define WRITE_MODE "w"
#define WRITE_BINARY_MODE "wb"
#define WRITE_MODE_PLUS "w+"
#define APPEND_MODE "a"
#define APPEND_MODE_PLUS "a+"

extern char *F_RED;
extern char *F_GREEN;
extern char *F_YELLOW;
extern char *F_BLUE;
extern char *F_WHITE;

#define closeFile fclose

bool isNullFile(FILE *f);

FILE *openFile(char *fileName, char *mode);

/*Read a line in the */
int getLine(FILE *f, char destBuffer[], int destSize);


#endif
