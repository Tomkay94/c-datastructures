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

char *
test_append_item_updates_size(void) {
	struct Dynamic_Array *da = dynamic_array_create(3, 2);

	append_item(da, 5);
	MU_ASSERT("append_item updates size to 1", da->size == 1);

	append_item(da, 15);
	MU_ASSERT("append_item updates size to 2", da->size == 2);

	append_item(da, 25);
	MU_ASSERT("append_item updates size to 3", da->size == 3);

	free_dynamic_array(da);
	return 0;
}

char *
test_append_item_adds_item(void) {
	struct Dynamic_Array *da = dynamic_array_create(3, 2);

	append_item(da, 5);
	MU_ASSERT("append_item appends 5", da->array[da->size - 1] == 5);

	append_item(da, 15);
	MU_ASSERT("append_item appends 15", da->array[da->size - 1] == 15);

	append_item(da, 25);
	MU_ASSERT("append_item appends 25", da->array[da->size - 1] == 25);

	free_dynamic_array(da);
	return 0;
}

char *
test_capacity_updates_by_resize_factor(void) {
	int factor   = 2;
	int capacity = 3;
	struct Dynamic_Array *da = dynamic_array_create(capacity, factor);

	append_item(da, 15);
	append_item(da, 25);
	append_item(da, 35);

	MU_ASSERT("array size updated to 3", da->size == 3);
	MU_ASSERT("capacity equals size",    da->capacity == da->size);
	MU_ASSERT("resize factor unaltered", da->resize_factor == factor);

	append_item(da, 45);
	MU_ASSERT("capacity updated by resize factor", da->capacity == factor * capacity);
	MU_ASSERT("array size updated to 4", da->size == 4);

	append_item(da, 55);
	MU_ASSERT("array size updated to 5", da->size == 5);

	append_item(da, 65);
	MU_ASSERT("array size updated to 6", da->size == 6);

	free_dynamic_array(da);
	return 0;
}

/*
 * Test Suite
 */
char *
test_suite(void) {
	MU_RUN_TEST(test_dynamic_array_create_sets_members);
	MU_RUN_TEST(test_append_item_updates_size);
	MU_RUN_TEST(test_append_item_adds_item);
	MU_RUN_TEST(test_capacity_updates_by_resize_factor);
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
