#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
	int size;
	int capacity;
	int *stk;
};

struct Stack* stack_create(int capacity) {
	struct Stack *s = malloc(sizeof(struct Stack));
	s->size = 0;
	s->capacity = capacity;
	s->stk = malloc(sizeof(int) * capacity);
	return s;
}

void stack_pop(struct Stack *s) {
	if (s->size > 0) {
		s->stk[s->size - 1] = 0;
		--(s->size);
	}
	return;
}

void stack_show(struct Stack *s) {
        int i = 0;
	for(; i < s->capacity; ++i) {
	        printf("s[%i]=%i\n", i, s->stk[i]);
        }
	printf("\n");
	return;
}

void stack_push(struct Stack *s, int data) {
	if (s->size < s->capacity) {
		s->stk[s->size] = data;
		++(s->size);
	}
	return;
}

#ifdef NOT_TESTING
int main(void) {
	return 0;
}
#endif
