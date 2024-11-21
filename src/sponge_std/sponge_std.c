#include "sponge_std.h"

int memUsage = 0;

void fatalError(int code){
    // Fonction qui permet de quitté un programme avec un code d'erreur (utile pour le debug)
    printf("[ %s Fatal Error %s ] : ", F_RED, F_WHITE);
	printError(code);
    exit(code);
}

void *allocate(size_t size, char *message){
    // Fonction qui permet d'allouer de la mémoire (malloc) (utile pour le debug)
    void *p;
    
    p = malloc((unsigned long)size);
    if (p == NULL){
        fprintf(stderr,"Can't allocate %ld bytes for '%s' \n", size, message);
        fatalError(-1);
    }
    
    memUsage += size;

    return p;    
}