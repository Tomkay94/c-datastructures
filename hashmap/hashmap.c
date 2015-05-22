#include <stdio.h>
#include <stdlib.h>

#include "../_common/ecalloc.h"
#include "../_common/emalloc.h"

#ifndef HASHMAP_H
	#define HASHMAP_H
	#include "hashmap.h"
#endif

struct HashMap *
hashmap_create(unsigned int capacity) {
	struct HashMap *hm = emalloc(sizeof(struct HashMap));

	hm->map      = ecalloc(capacity, sizeof(struct HashNode));
	hm->capacity = capacity;
	hm->size     = 0;
	return hm;
}

void
free_hashmap(struct HashMap *hm) {
	free(hm->map);
	free(hm);
	return;
}

unsigned int *
next_prime(unsigned int *num_ptr);

bool
is_prime(unsigned int *num_ptr) {
	if (*num_ptr > 1) {
		unsigned int i = 2;
		for (; i < *num_ptr; ++i) {
			if (*num_ptr % i == 0) {
				return false;
			}
		}
		return true;
	}
	return false;
}

#ifdef NOT_TESTING
int main(void) {
	return 0;
}
#endif
