#include "../_test_framework/min_unit.h"
#include "hashmap.c"

int tests_run = 0;

/*
 * Test Cases
 */
char *
test_hash_map_create_sets_members(void) {
	struct HashMap *hm = hashmap_create(3);

	MU_ASSERT("hm is not null after create",  hm != NULL);
	MU_ASSERT("hm capacity set after create", hm->capacity == 3);
	MU_ASSERT("hm size set after create",     hm->size == 0);
	MU_ASSERT("hm map set after create",      sizeof(*(hm->map)) == sizeof(struct HashNode));
	MU_ASSERT("hm map is array of pointers",  sizeof(hm->map) == sizeof(struct HashNode *));

	free_hashmap(hm);
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
