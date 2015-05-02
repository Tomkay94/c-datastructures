#include "../_test_framework/min_unit.h"
#include "hashmap.c"

int tests_run = 0;

/*
 * Test Cases
 */
char *
test_hash_map_create_sets_members(void) {
	return 0;
}

/*
 * Test Suite
 */
char *
test_suite(void) {
	MU_RUN_TEST(test_hash_map_create_sets_members);
	return 0;
}

/*
 * Test Runner
 */
#ifndef NOT_TESTING
int
main(void) {
	char *result = test_suite();
	printf("number of tests run: %d\n", tests_run);
	if (result) printf("FAIL: %s", result);
	return 0 != result;
}
#endif
