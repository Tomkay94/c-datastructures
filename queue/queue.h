#include <stdbool.h>

struct Queue;

void enqueue(struct Queue *q, int data);
int dequeue(struct Queue *q);
bool is_empty(struct Queue *q);
