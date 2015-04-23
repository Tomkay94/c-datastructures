#include "../_test_framework/min_unit.h"
#include "dynamic_array.c"

int tests_run = 0;

/*
 * Test Cases
 */
char *
test_dynamic_array_create_sets_members(void) {
	struct Dynamic_Array *da = dynamic_array_create(5, 2);
	MU_ASSERT("create allocates memory",        da != NULL);
	MU_ASSERT("create sets size to 0",          da->size == 0);
	MU_ASSERT("create sets capacity to 5",      da->capacity == 5);
	MU_ASSERT("create sets resize factor to 2", da->resize_factor == 2);
	MU_ASSERT("create allocates array memory",  da->array != NULL);
	free_dynamic_array(da);
	return 0;
}

/*
 * Test Suite
 */
char *
test_suite(void) {
	MU_RUN_TEST(test_dynamic_array_create_sets_members);
	return 0;
}

/*
 * Test Runner
 */
int
main(int argc, char **argv) {
	char *result = test_suite();
	printf("number of tests run: %d\n", tests_run);
	if (result) printf("FAIL: %s\n", result);
	return 0;
}
