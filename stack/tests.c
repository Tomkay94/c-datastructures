#include "../test_framework/min_unit.h"
#include "stack.c"

int tests_run = 0;

/* Test Cases */
char *test_stack_create_sets_members(void) {
	struct Stack *s = stack_create();
	MU_ASSERT("stack_create sets size",     s->size == 0);
	MU_ASSERT("stack_create sets top next", s->top->next == NULL);

	free_stack(s);
	return 0;
}

char *test_node_create_sets_members(void) {
	struct Node *n = node_create(5);
	MU_ASSERT("node_create sets data",      n->data == 5);
	MU_ASSERT("node_create sets next null", n->next == NULL);

	free(n);
	return 0;
}

char *test_stack_push_updates_size(void) {
	struct Stack *s = stack_create();

	stack_push(s, 5);
	MU_ASSERT("stack_push updates size to 1", s->size == 1);

 	stack_push(s, 15);
    MU_ASSERT("stack_push updates size to 2", s->size == 2);

    stack_push(s, 20);
    MU_ASSERT("stack_push updates size to 3", s->size == 3);

	free_stack(s);
	return 0;
}

char *test_stack_push_updates_top_ref(void) {
	struct Stack *s = stack_create();

	stack_push(s, 5);
    MU_ASSERT("stack_push updates top ref 1", s->top->data == 5);

	stack_push(s, 10);
    MU_ASSERT("stack_push updates top ref 2", s->top->data == 10);

	stack_push(s, 15);
    MU_ASSERT("stack_push updates top ref 3", s->top->data == 15);

	//free_stack(s);
	return 0;
}

char *test_stack_peek_equals_top_ref(void) {
    struct Stack *s = stack_create();

    stack_push(s, 5);
    MU_ASSERT("stack_push updates top ref 1", s->top->data == 5);
    MU_ASSERT("stack_peek updates with top ref 1", s->top->data == stack_peek(s));

    stack_push(s, 10);
    MU_ASSERT("stack_push updates top ref 2", s->top->data == 10);
    MU_ASSERT("stack_peek updates with top ref 2", s->top->data == stack_peek(s));

    stack_push(s, 15);
    MU_ASSERT("stack_push updates top ref 3", s->top->data == 15);
    MU_ASSERT("stack_peek updates with top ref 3", s->top->data == stack_peek(s));

    free_stack(s);
	return 0;
}


/* Test Suite */
char *test_suite(void) {
	MU_RUN_TEST(test_stack_create_sets_members);
	MU_RUN_TEST(test_node_create_sets_members);

	MU_RUN_TEST(test_stack_push_updates_size);
	MU_RUN_TEST(test_stack_push_updates_top_ref);

	MU_RUN_TEST(test_stack_peek_equals_top_ref);
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
