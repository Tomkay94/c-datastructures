#include "../test_framework/min_unit.h"
#include "node.c"

int tests_run = 0;

/* Test Cases */
char *test_set_node_members(void) {

	struct Node* n = node_create(10);

	MU_ASSERT("node_create sets data", n->data == 10);
	MU_ASSERT("node_create sets next", n->next == NULL);

	free(n);
	return 0;
}

char *test_append_data_links_refs(void) {

	struct Node *head = node_create(5);
	append_data(head, 10);
	append_data(head, 15);

	MU_ASSERT("head link data was set", head->data == 5);
	MU_ASSERT("head link was set",      head->next != NULL);

	MU_ASSERT("mid link data was set",  head->next->data == 10);
	MU_ASSERT("mid link was set",       head->next->next != NULL);

	MU_ASSERT("tail link data was set", head->next->next->data == 15);
	MU_ASSERT("tail link was set",      head->next->next->next == NULL);

	free(head->next->next);
	free(head->next);
	free(head);
	return 0;
}

char *test_contains_data_not_present(void) {
	struct Node *head = node_create(5);

	append_data(head, 10);
	append_data(head, 20);

	MU_ASSERT("list does not contain data", contains_data(head, 15) == false);

	free(head->next->next);
	free(head->next);
	free(head);
	return 0;
}

char *test_contains_data_present(void) {
	struct Node *head = node_create(5);

	MU_ASSERT("list does not contain data 10", contains_data(head, 10) == false);
	append_data(head, 10);
	MU_ASSERT("list contains data 10", contains_data(head, 10) == true);

	MU_ASSERT("list does not contain data 15", contains_data(head, 15) == false);
	append_data(head, 15);
	MU_ASSERT("list contains data 15", contains_data(head, 15) == true);

	free(head->next->next);
	free(head->next);
	free(head);
	return 0;
}

char *test_contains_data_one_node_true(void) {
	struct Node *head = node_create(5);
	MU_ASSERT("single node contains data", contains_data(head, 5) == true);
	free(head);
	return 0;
}

char *test_contains_data_one_node_false(void) {
	struct Node *head = node_create(5);
	MU_ASSERT("single node contains data", contains_data(head, 10) == false);
	free(head);
	return 0;
}

/* Test Suite */
char *test_suite(void) {
	MU_RUN_TEST(test_set_node_members);
	MU_RUN_TEST(test_append_data_links_refs);

	MU_RUN_TEST(test_contains_data_not_present);
	MU_RUN_TEST(test_contains_data_present);
	MU_RUN_TEST(test_contains_data_one_node_true);
	MU_RUN_TEST(test_contains_data_one_node_false);
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
