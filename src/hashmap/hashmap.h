#ifndef _HASHMAP_H_
#define _HASHMAP_H_
#include <stdio.h>
#include <stdlib.h>
#include "../sponge_std/sponge_std.h"
#include "buckets.h"

#define BASE_BUCKETS_COUNT 2048


typedef struct _HashMap{
	uint32_t length;
	Bucket *buckets[BASE_BUCKETS_COUNT];
} HashMap;

HashMap *newHashMap();

uint32_t getHashMap(char *key, HashMap *hm);

void appendHashMap(char *key, uint32_t value, HashMap *hm);

void setHashMap(char *key, uint32_t newValue, HashMap *hm);

void popHashMap(char *key, HashMap *hm);

void printHashMap(HashMap* hm);

void freeHashMap(HashMap *hm);

#endif