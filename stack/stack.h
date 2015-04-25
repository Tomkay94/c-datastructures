#include <stdbool.h>

/*
 * Stack data type.
 */
struct Stack {
	int size;
	struct Node *top;
};

struct Node {
	int data;
	struct Node *next;
};

/*
 * Stack prototypes.
 */
struct Stack*
stack_create();

struct Node*
node_create(int data);

void
stack_pop(struct Stack *s);

void
stack_push(struct Stack *s, int data);

void
stack_show(struct Stack *s);

int
stack_peek(struct Stack *s);

bool
stack_is_empty(struct Stack *s);

void
free_stack(struct Stack *s);
