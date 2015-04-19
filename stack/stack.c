#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
	int size;
	int capacity;
	int* stk;
};

struct Stack* stack_create(int capacity) {
	struct Stack *k = malloc(sizeof(struct Stack));
	k->size = 0;
	k->capacity = capacity;
	k->stk = malloc(sizeof(int[capacity]));
	return k;
}

struct Stack* stack_pop(struct Stack* s) {
	if (s->size > 0) {
		s->stk[s->size - 1] = 0;
		--(s->size);
	}
	return s;
}

void stack_show(struct Stack *s) {
        int i = 0;
	for(; i < s->capacity; ++i) {
	        printf("s[%i]=%i\n", i, s->stk[i]);
        }
	printf("\n");
}

struct Stack* stack_push(struct Stack* s, int data) {
	if (s->size < s->capacity) {
		s->stk[s->size] = data;
		++(s->size);
	}
	return s;
}

int main() {
	return 0;
}
