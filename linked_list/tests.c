#include "../test_framework/min_unit.h"
#include <stdio.h>

int tests_run = 0;

/* Test Cases */
char *test_something_success(void) {
	MU_ASSERT("success test something", 1 == 1);
	return 0;
}

char *test_something_fail(void) {
	MU_ASSERT("fail test something", 1 == 2);
	return 0;
}

/* Test Suite */
char *test_suite(void) {
	MU_RUN_TEST(test_something_success);
	MU_RUN_TEST(test_something_fail);
    return 0;
}

/* Test Runner */
int main(int ac, char **av) {
	char *result = test_suite();
    printf("number of tests run: %d\n", tests_run);
    if (result) printf("FAIL: %s\n", result);
    return 0 != result;
}
