#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
	int size;
	struct Node *top;
};

struct Node {
	int data;
	struct Node *next;
};

struct Stack* stack_create(void) {
	struct Stack *s = malloc(sizeof(struct Stack));
	s->top = malloc(sizeof(struct Node));
	s->size = 0;
	return s;
}

struct Node* node_create(int d) {
	struct Node *n = malloc(sizeof(struct Node));
	n->next = NULL;
	n->data = d;
	return n;
}

void stack_pop(struct Stack *s) {
	if (s->top != NULL) {
		s->top = s->top->next;
		--(s->size);
	}
	return;
}

void stack_show(struct Stack *s) {
	struct Node *curr = s->top;
	while(curr->next != NULL) {
   		printf("item=%i\n", curr->data);
		curr = curr->next;
	}
	printf("\n");
	return;
}

void stack_push(struct Stack *s, int data) {
	struct Node *head = malloc(sizeof(struct Node));
	head->data = data;
	head->next = NULL;

	/* Prepend the head to the top of the stack. */
	if (s->top != NULL) {
		head->next = s->top;
	}

	s->top = head;
	++(s->size);
	return;
}

#ifdef NOT_TESTING
int main(void) {
	return 0;
}
#endif
