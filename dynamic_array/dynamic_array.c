#include <stdio.h>
#include "../common/emalloc.h"
#ifndef DYNAMIC_ARRAY_H
	#define DYNAMIC_ARRAY_H
	#include "dynamic_array.h"
#endif

/*
 * Create a dynamic array with capacity that expands by factor.
 * Return a pointer to the dynamic array.
 */
struct Dynamic_Array* dynamic_array_create(int capacity, int factor) {
	struct Dynamic_Array *da = emalloc(sizeof(struct Dynamic_Array));
	da->capacity       = capacity;
	da-> resize_factor = factor;
	da->size           = 0;
	da->array          = emalloc(sizeof(sizeof(int) * capacity));
	return da;
}

#ifdef NOT_TESTING
int
main(int argc, char **argv) {
	return 0;
}
#endif
