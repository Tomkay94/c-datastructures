#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct Queue {
	int size;
	struct Node *front;
	struct Node *back;
};

struct Node {
	int data;
	struct Node *next;
};

struct Queue* queue_create() {
	struct Queue *q = malloc(sizeof(struct Queue));
	q->size = 0;
	q->front = malloc(sizeof(struct Node));
	q->back = malloc(sizeof(struct Node));
	return q;
}

struct Node* node_create(int d) {
	struct Node *n = malloc(sizeof(struct Node));
	n->data = d;
	n->next = NULL;
	return n;
}

void q_enqueue(struct Queue *q, int data) {
	struct Node *head = node_create(data);

	if (q->size == 0) {
		q->front = head;
	}

	else {
		q->back->next = head;
	}

	q->back = head;
	++(q->size);
	return;
}

void q_dequeue(struct Queue *q) {

	if (q->size > 0) {
		q->front = q->front->next;
		--(q->size);
	}
	return;
}

void q_show(struct Queue *q) {
	if (q->size > 0) {
		struct Node *curr = q->front;
    	while(curr != NULL) {
	    	printf("%i ", curr->data);
        	curr = curr->next;
    	}
    	printf("\n");
	}
	return;
}

bool q_is_empty(struct Queue *q) {
	return (q->size == 0);
}

#ifdef NOT_TESTING
int main(void) {
	return 0;
}
#endif
