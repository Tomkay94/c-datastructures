#include "../test_framework/min_unit.h"
#include "queue.c"

int tests_run = 0;

/* Test Cases */
char *
test_queue_create_sets_members(void) {
	struct Queue *q = queue_create();
	MU_ASSERT("queue_create sets queue front ref", q->front == NULL);
	MU_ASSERT("queue_create sets queue back ref",  q->back == NULL);
	MU_ASSERT("queue_create sets size to 0",       q->size == 0);

	free_queue(q);
	return 0;
}

char *
test_enqueue_on_empty(void) {
	struct Queue *q = queue_create();
	enqueue(q, 5);
	MU_ASSERT("enqueue appends node to empty queue", q->front->data == 5);

	free_queue(q);
	return 0;
}

char *
test_dequeue_on_empty(void) {
	struct Queue *q = queue_create();

	MU_ASSERT("queue empty before dequeue", q->size == 0);
	dequeue(q);
	MU_ASSERT("queue empty after dequeue",  q->size == 0);

	free_queue(q);
	return 0;
}

char *
test_enqueue_updates_size(void) {
	struct Queue *q = queue_create();

	enqueue(q, 5);
	MU_ASSERT("enqueue updates size to 1", q->size == 1);

	enqueue(q, 15);
	MU_ASSERT("enqueue updates size to 2", q->size == 2);

	enqueue(q, 25);
	MU_ASSERT("enqueue updates size to 3", q->size == 3);

	free_queue(q);
	return 0;
}

char *
test_dequeue_updates_size(void) {
    struct Queue *q = queue_create();

	enqueue(q, 5);
	enqueue(q, 15);
	enqueue(q, 20);
    MU_ASSERT("queue size is 3", q->size == 3);

    dequeue(q);
    MU_ASSERT("dequeue updates size to 2", q->size == 2);

    dequeue(q);
    MU_ASSERT("dequeue updates size to 1", q->size == 1);

    dequeue(q);
    MU_ASSERT("dequeue updates size to 0", q->size == 0);

    free_queue(q);
    return 0;
}

char *
test_enqueue_updates_back_ref(void) {
	return 0;
}

char *
test_dequeue_updates_front_ref(void) {
	return 0;
}

/* Test Suite */
char *
test_suite(void) {
	MU_RUN_TEST(test_queue_create_sets_members);
	MU_RUN_TEST(test_enqueue_on_empty);
	MU_RUN_TEST(test_dequeue_on_empty);
	MU_RUN_TEST(test_enqueue_updates_size);
	MU_RUN_TEST(test_dequeue_updates_size);
	return 0;
}

/* Test Runner */
int
main(int argc, char **argv) {
	char *result = test_suite();
	printf("number of tests run: %d\n", tests_run);
	if (result) printf("FAIL: %s\n", result);
	return 0 != result;
}
