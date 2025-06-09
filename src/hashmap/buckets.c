#include "buckets.h"


BucketCell *newBucketCell(char *key, uint64_t value){
	BucketCell *cell;
	cell = (BucketCell *)allocate(sizeof(BucketCell), "Bucket cell creation");

	if (key){
		cell->key = strdup(key);
	} else {
		cell->key = NULL;
	}

	cell->value = value;
	cell->next = NULL;
	return cell;
}

Bucket *newBucket(){
	Bucket *pl = (Bucket *)allocate(sizeof(Bucket), "Bucket creation");
	
	pl->length = 0;
	pl->head = NULL;
	pl->tail = NULL;

	return pl;
}

void appendBucket(char *key, uint64_t value, Bucket *L){
	BucketCell *el = newBucketCell(key, value);
	if (L->length == 0){ 
		L->head = L->tail = el;
	} else {
		L->tail->next = el;
		L->tail = el;
	}
	(L->length)++;
}

uint64_t popBucket(char *key, Bucket *l){
	if (l == NULL){
		fatalError(11); // TODO :change error code
	}

	BucketCell *p = l->head;
	uint64_t value;
	BucketCell *toFree = NULL;

	if (p == NULL){
		fatalError(9); // TODO : change error code
	}

	if (strcmp(p->key, key) == 0){
		value = p->value;
		l->head = p->next;
		l->length--;
		if (l->length == 0){
			l->tail = l->head;
		}
		free(p);
		return value;
	}

	while (p->next != NULL && strcmp(p->next->key, key) != 0){
		p = p->next;
	}

	if (p == NULL || p->next == NULL){
		fatalError(10); // TODO : error not found
	} else if (p->next->next == NULL){
		value = p->value;
		l->length--;
		l->tail = p;
	}


	toFree = p->next;
	p->next = NULL;
	free(toFree);
	return value;
}

uint64_t getValueBucket(char *key, Bucket *l){
	if (l == NULL){
		fatalError(11); // TODO :change error code
	}

	BucketCell *p = l->head;

	if (p == NULL){
		fatalError(9); // TODO : change error code
	}

	while (p != NULL && strcmp(p->key, key) != 0){
		p = p->next;
	}

	if (p == NULL){
		fatalError(10); // TODO : error not found
	}
	
	return p->value;
}

void setValueBucket(char *key, uint64_t value, Bucket *l){
	if (l == NULL){
		fatalError(11); // TODO :change error code
	}

	BucketCell *p = l->head;

	if (p == NULL){
		fatalError(9); // TODO : change error code
	}

	while (p != NULL && strcmp(p->key, key) != 0){
		p = p->next;
	}

	if (p == NULL){
		fatalError(10); // TODO : error not found
	}
	p->value = value;
}

void emptyBucket(Bucket *L){
	BucketCell *el=L->head;
	BucketCell *next;

	while (el){		
		next=el->next;
		if (next->key){
			free(next->key);
		}

		free(el);
		el = next;
	}
	L->head = L->tail = NULL;
	L->length = 0;
}

void printBucket(Bucket *L){
	BucketCell *p = L->head;
	printf("Bucket : head : %p, tail : %p, length : %ld\n", L->head, L->tail, L->length);

	while (p != NULL){
		printf("%s : %ld", p->key, p->value);
		p = p->next;
		if (p != NULL){
			printf(", ");
		} else {
			printf("\n");
		}
	}
}

void freeBucket(Bucket *L){
	if (L == NULL){
		return;
	}

	BucketCell *p = L->head;
	BucketCell *toFree;

	while (p != NULL){
		toFree = p;
		if (toFree->key){
			free(toFree->key);
		}
		p = p->next;
		free(toFree);
	}
	L->head = NULL;
	L->tail = NULL;
	L->length = 0;
	free(L);
}