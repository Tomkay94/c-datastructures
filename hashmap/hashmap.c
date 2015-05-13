#include <stdio.h>
#include <stdlib.h>

#include "../_common/ecalloc.h"
#include "../_common/emalloc.h"

#ifndef HASHMAP_H
	#define HASHMAP_H
	#include "hashmap.h"
#endif

struct HashMap *hashmap_create(int capacity) {
	struct HashMap *hm = emalloc(sizeof(struct HashMap));

	hm->map      = ecalloc(capacity, sizeof(struct HashNode));
	hm->capacity = capacity;
	hm->size     = 0;
	return hm;
}

#ifdef NOT_TESTING
int main(void) {
	return 0;
}
#endif
