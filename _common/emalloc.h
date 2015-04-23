#include <stdlib.h>

void*
emalloc(size_t amount) {
	void *v = malloc(amount);
	if (!v) {
		fprintf(stderr, "malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return v;
}
