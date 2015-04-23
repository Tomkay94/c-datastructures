#include <stdbool.h>

/*
 * Queue data type.
 */
struct Queue {
	int size;
	struct Node *front;
	struct Node *back;
};

struct Node {
	int data;
	struct Node *next;
};

/*
 * Queue prototypes.
 */
void
enqueue(struct Queue *q, int data);

void
dequeue(struct Queue *q);

bool
is_empty(struct Queue *q);

void
free_queue(struct Queue *q);
