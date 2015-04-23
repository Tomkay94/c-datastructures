#include <stdio.h>
#include "../_common/emalloc.h"
#include "../_common/erealloc.h"
#ifndef DYNAMIC_ARRAY_H
	#define DYNAMIC_ARRAY_H
	#include "dynamic_array.h"
#endif

/*
 * Create a dynamic array with capacity that expands by factor.
 * Return a pointer to the dynamic array.
 */
struct Dynamic_Array*
dynamic_array_create(int capacity, int factor) {
	struct Dynamic_Array *da = emalloc(sizeof(struct Dynamic_Array));
	da->capacity      = capacity;
	da->resize_factor = factor;
	da->size          = 0;
	da->array         = emalloc(sizeof(sizeof(int) * capacity));
	return da;
}

/*
 * Add the item to the end of the array.
 * Resize if the array has reached capacity.
 */
void
append_item(struct Dynamic_Array *da, int item) {

	/* A resize is necessary. */
	if (da->size == da->capacity) {
		/* Factor the new capacity. */
		da->capacity = da->capacity * da->resize_factor;
		da->array = erealloc(da->array, da->capacity);
	}

	da->array[da->size] = item;
	++(da->size);
	return;
}

/*
 * Display the dynamic array.
 */
void
show_array(struct Dynamic_Array *da) {
	int i;
	for (i = 0; i < da->size; ++i) {
		printf("index=%d, item=%d\n", i, da->array[i]);
	}
	printf("\n");
	return;
}

/*
 * Free the memory occupied by the dynamic array.
 */
void
free_dynamic_array(struct Dynamic_Array *da) {
	free(da->array);
	free(da);
	return;
}

#ifdef NOT_TESTING
int
main(int argc, char **argv) {
	return 0;
}
#endif
