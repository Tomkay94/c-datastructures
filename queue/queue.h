#include <stdbool.h>

struct Queue {
	int size;
	struct Node *front;
	struct Node *back;
};

struct Node {
	int data;
	struct Node *next;
};

void
enqueue(struct Queue *q, int data);

void
dequeue(struct Queue *q);

bool
is_empty(struct Queue *q);

void
free_queue(struct Queue *q);
