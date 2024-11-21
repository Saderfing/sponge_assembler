#include "error_handling.h"

char *errorRepr[ERROR_CODE_COUNT] = {
	"Unkown instruction",
	"Unkown condition",
	"Unkown datatype",
	"Unkown register code",
};

void errorHandling(ErrorCode error, u32 line, char yychar){
	printf("Line : %d\n", line);
	if (error < ERROR_CODE_COUNT){
		printf("%s\n", errorRepr[error]);
	} else {
		printf("Unkown error\nDx\n");
	}
}