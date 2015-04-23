#include <stdio.h>
#include "../_common/emalloc.h"
#ifndef QUEUE_H
	#define QUEUE_H
	#include "queue.h"
#endif

/*
 * Creates a Queue, and returns a pointer to it.
 */
struct Queue*
queue_create() {
	struct Queue *q = emalloc(sizeof(struct Queue));
	q->size  = 0;
	q->front = NULL;
	q->back  = NULL;
	return q;
}

/*
 * Creates a Node for the Queue, and returns a pointer to it.
 */
struct Node*
node_create(int d) {
	struct Node *n = emalloc(sizeof(struct Node));
	n->data = d;
	n->next = NULL;
	return n;
}

/*
 * Adds an element to the back of the queue.
 */
void
enqueue(struct Queue *q, int data) {
	struct Node *head = node_create(data);

	/* First enqueue on empty. */
	if (q->front == NULL && q->back == NULL) {
		q->front = head;
		q->back  = head;
	}

	else {
		q->back->next = head;
		q->back       = head;
	}

	++(q->size);
	return;
}

/*
 * Remove the node from the front of the queue.
 */
void
dequeue(struct Queue *q) {

	/* Dequeue from an empty queue. */
	if (q->size == 0) {
		return;
	}

	/* Dequeue the only node. */
	else if (q->size == 1) {
    	free(q->front);
    	q->front = NULL;
    	q->back  = NULL;
    }

	/* Regular case. */
	else if (q->size > 1) {
		struct Node *temp;
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}

	--(q->size);
	return;
}

/*
 * Display the elements in the queue.
 */
void
q_show(struct Queue *q) {
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

/*
 * Free the nodes in the queue.
 */
void
free_queue(struct Queue *q) {
	struct Node *temp;

	while(q->front != NULL) {
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
	free(q);
	return;
}

/*
 * Return true if the queue is empty.
 */
bool
q_is_empty(struct Queue *q) {
	return (q->size == 0);
}

#ifdef NOT_TESTING
int
main(void) {
	return 0;
}
#endif
