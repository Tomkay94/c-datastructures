#include <stdlib.h>

void *
erealloc(void *ptr, size_t amount) {
	void *v = realloc(ptr, amount);
	if (!v) {
		fprintf(stderr, "realloc failed\n");
		exit(EXIT_FAILURE);
	}
	return v;
}
