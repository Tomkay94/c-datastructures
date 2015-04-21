#include <stdio.h>
#include <stdlib.h>
#ifndef STACK_H
	#define STACK_H
	#include "stack.h"
#endif

struct Stack {
	int size;
	struct Node *top;
};

struct Node {
	int data;
	struct Node *next;
};

/* Creates an empty stack and returns a pointer to it. */
struct Stack* stack_create(void) {
	struct Stack *s = malloc(sizeof(struct Stack));
	s->top = malloc(sizeof(struct Node));
	s->size = 0;
	return s;
}

/* Creates a stack node and returns a pointer to it. */
struct Node* node_create(int d) {
	struct Node *n = malloc(sizeof(struct Node));
	n->next = NULL;
	n->data = d;
	return n;
}

/* Removes the top node from the stack. */
void stack_pop(struct Stack *s) {
	if (s->top != NULL) {
		struct Node *temp;
		temp = s->top;
		s->top = s->top->next;
		free(temp);
		temp = NULL;
		--(s->size);
	}
	return;
}

/* Displays the elements of the stack. */
void stack_show(struct Stack *s) {
	struct Node *curr = s->top;
	while(curr->next != NULL) {
   		printf("item=%i\n", curr->data);
		curr = curr->next;
	}
	printf("\n");
	return;
}

/* Pushes data to the top of the stack. */
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

/* Returns the value of the node at the top of the stack. */
int stack_peek(struct Stack *s) {
	return s->top->data;
}

/* Free the memory occupied by the stack nodes. */
void free_stack(struct Stack *s) {
    struct Node *temp;
    while (s->top != NULL) {
    	temp = s->top;
    	s->top = s->top->next;
    	free(temp);
    	//stack_pop(s);
    }
    free(s->top);
    free(s);
	return;
}

#ifdef NOT_TESTING
int main(void) {
	return 0;
}
#endif
