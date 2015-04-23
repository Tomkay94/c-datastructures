#include "../test_framework/min_unit.h"
#include "dynamic_array.c"

int tests_run = 0;

/* Test Cases */
char *
test_dynamic_array_create_sets_members(void) {
	return 0;
}

/* Test Suite */
char *
test_suite(void) {
	return 0;
}

/* Test Runner */
int
main(int argc, char **argv) {
	char *result = test_suite();
	printf("number of tests run: %d\n", tests_run);
	if (result) printf("FAIL: %s\n", result);
	return 0;
}
