#ifndef _POINT_LIST_H_
#define _POINT_LIST_H_
#include <stdio.h>  
#include <stdlib.h> 
#include "../sponge_std/sponge_std.h"

typedef struct _BucketCell{
	char *key;
	int32_t value;
	struct _BucketCell *next;
} BucketCell;


typedef struct Bucket_{
	unsigned int length;        
	BucketCell *head; 
	BucketCell *tail;  
} Bucket;

Bucket *newBucket();

void appendBucket(char *key, int32_t value, Bucket *L);

int32_t popBucket(char *key, Bucket *l);

void emptyBucket(Bucket *L);

int32_t getValueBucket(char *key, Bucket *l);

void setValueBucket(char *key, uint32_t value, Bucket *l);

void freeBucket(Bucket *L);

void printBucket(Bucket *L);

#endif