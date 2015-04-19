#include <stdbool.h>
#include "../linked_list/linked_list.c"

struct Queue;

void enqueue(struct Queue *q, int data);
int dequeue(struct Queue *q);
bool is_empty(struct Queue *q);
