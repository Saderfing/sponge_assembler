#ifndef _POINT_LIST_H_
#define _POINT_LIST_H_
#include <stdio.h>  
#include <stdlib.h> 
#include "sponge_std.h"

typedef struct _BucketCell{
	char *key;
	uint64_t value;
	struct _BucketCell *next;
} BucketCell;


typedef struct Bucket_{
	uint64_t length;        
	BucketCell *head; 
	BucketCell *tail;  
} Bucket;

Bucket *newBucket();

void appendBucket(char *key, uint64_t value, Bucket *L);

uint64_t popBucket(char *key, Bucket *l);

void emptyBucket(Bucket *L);

uint64_t getValueBucket(char *key, Bucket *l);

void setValueBucket(char *key, uint64_t value, Bucket *l);

void freeBucket(Bucket *L);

void printBucket(Bucket *L);

#endif