#include "../test_framework/min_unit.h"
#include "queue.c"
#include <stdlib.h>

int tests_run = 0;

char *test_queue_create_sets_members(void) {
	
}

char *test_suite(void) {
	MU_RUN_TEST(test_queue_create_sets_members);
}

int main(int argc, char **argv) {
	char *result = test_suite();
	printf("number of tests run: %d\n", tests_run);
	if (result) printf("FAIL: %s\n", result)
	return 0 != result;
}
