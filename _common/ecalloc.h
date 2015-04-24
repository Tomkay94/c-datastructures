#include <stdlib.h>

void *
ecalloc(size_t num_copy, size_t amount) {
	void *v = calloc(num_copy, amount);
	if (!v) {
		fprintf(stderr, "calloc failed\n");
		exit(EXIT_FAILURE);
	}
	return v;
}
