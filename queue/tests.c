#include "../_test_framework/min_unit.h"
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
	struct Queue *q = queue_create();

	enqueue(q, 5);
	MU_ASSERT("queue back ref updates to node containing 5", q->back->data == 5);
	MU_ASSERT("queue front ref set to 1st enqueue data", 	 q->front->data == 5);

	enqueue(q, 10);
	MU_ASSERT("queue back ref updates to node containing 10", q->back->data == 10);
	MU_ASSERT("queue front ref unchanged after 2nd enqueue",  q->front->data == 5);

	enqueue(q, 15);
	MU_ASSERT("queue back ref updates to node containing 15", q->back->data == 15);
	MU_ASSERT("queue front ref unchanged after 3rd enqueue",  q->front->data == 5);

	free_queue(q);
	return 0;
}

char *
test_dequeue_updates_front_ref(void) {
	struct Queue *q = queue_create();

	enqueue(q, 5);
	enqueue(q, 10);
	enqueue(q, 15);
	MU_ASSERT("queue back ref set to most recent data", q->back->data == 15);
	MU_ASSERT("queue front ref set to oldest data",     q->front->data == 5);

	dequeue(q);
	MU_ASSERT("dequeue 1st does not update queue back ref", q->back->data == 15);
	MU_ASSERT("dequeue 1st sets front ref to 10", 	        q->front->data == 10);

	dequeue(q);
	MU_ASSERT("dequeue 2nd does not update queue back ref ", q->back->data == 15);
	MU_ASSERT("dequeue 2nd sets front ref to 15",            q->front->data == 15);
	MU_ASSERT("dequeue 2nd sets front ref to back ref",      q->front == q->back);

	dequeue(q);
	MU_ASSERT("queue back ref set to NULL",  q->back == NULL);
	MU_ASSERT("queue front ref set to NULL", q->front == NULL);

	free_queue(q);
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

	MU_RUN_TEST(test_enqueue_updates_back_ref);
	MU_RUN_TEST(test_dequeue_updates_front_ref);
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
