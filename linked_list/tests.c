#include "../test_framework/min_unit.h"
#include "node.c"

int tests_run = 0;

/* Test Cases */
char *test_set_node_members(void) {
	struct Node* n = malloc(sizeof(struct Node));
	n->data = 10;
	n->next = NULL;
	MU_ASSERT("node data was set", n->data == 10);
	MU_ASSERT("node next was set", n->next == NULL);

	free(n);
	return 0;
}

char *test_chain_nodes(void) {
	struct Node* head = malloc(sizeof(struct Node));
	struct Node* mid  = malloc(sizeof(struct Node));
	struct Node* tail = malloc(sizeof(struct Node));

	head->data = 5;
	mid->data  = 10;
	tail->data = 15;

	head->next = mid;
	mid->next  = tail;
	tail->next = NULL;

	MU_ASSERT("head link was set to middle", head->next == mid);
	MU_ASSERT("head next data is mid data", head->next->data == 10);

	MU_ASSERT("mid link was set to tail", mid->next == tail);
	MU_ASSERT("mid next data is tail data", mid->next->data == 15);

	MU_ASSERT("tail link was set to NULL", tail->next == NULL);

	free(head);
	free(mid);
	free(tail);
	return 0;
}

/* Test Suite */
char *test_suite(void) {
	MU_RUN_TEST(test_set_node_members);
	MU_RUN_TEST(test_chain_nodes);
    return 0;
}

/* Test Runner */
#ifndef NOT_TESTING
int main(int ac, char **av) {
	char *result = test_suite();
    printf("number of tests run: %d\n", tests_run);
    if (result) printf("FAIL: %s\n", result);
    return 0 != result;
}
#endif
