#include <stdbool.h>

struct Queue;

void enqueue(struct Queue *q, int data);
void dequeue(struct Queue *q);
bool is_empty(struct Queue *q);
void free_queue(struct Queue *q);
