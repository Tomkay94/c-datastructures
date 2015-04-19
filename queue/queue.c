#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue {
	int capacity;
	int size;
	int *front;
	int *back;
};

struct Queue* queue_create(int cap) {
	struct Queue *q = malloc(sizeof(struct Queue));
	q->capacity = cap;
	q->size = 0;
	q->front = NULL;
	q->back = NULL;
	return q;
}

void q_enqueue(struct Queue *queue, int data) {
	return;
}

void q_dequeue(struct Queue *queue) {
	return;
}

bool q_is_empty(struct Queue *queue) {
	return (queue->size == 0);
}

#ifdef NOT_TESTING
int main(void) {
	return 0;
}
#endif
