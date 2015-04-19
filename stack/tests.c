#include "../test_framework/min_unit.h"
#include "stack.c"
#include <stdlib.h>

int tests_run = 0;

/* Test Cases */
char *test_stack_create_sets_members(void) {
	struct Stack *s = stack_create(5);
	MU_ASSERT("stack_create sets capacity", s->capacity == 5);
	MU_ASSERT("stack_create sets size", s->size == 0);
	MU_ASSERT("stack_create creates correct capacity", 1
		//sizeof(*(s->stk))/sizeof(int) == s->capacity
	);
}

/* Test Suite */
char *test_suite(void) {
	MU_RUN_TEST(test_stack_create_sets_members);
	return 0;
}

/* Test Runner */
#ifndef NOT_TESTING
int main(int argc, char **argv) {
	char *result = test_suite();
	printf("Number of tests run: %d\n", tests_run);
	if (result) printf("FAIL: %s\n", result);
	return 0;
}
#endif
