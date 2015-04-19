#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct Stack {
	int size;
	int capacity;
	int* stk;
};

struct Stack* stackCreate(int capacity) {
	struct Stack *k = malloc(sizeof(struct Stack));
	k->size = 0;
	k->capacity = capacity;
	k->stk = malloc(sizeof(int[capacity])); // size of array with capacity# ints
	return k;
}

struct Stack* stackPop(struct Stack* s) {
	if (s->size > 0) {
		s->stk[s->size - 1] = 0;
		--(s->size);
	}
	return s;
}

void stackShow(struct Stack *s) {
        int i = 0;
	for(; i < s->capacity; ++i) {
	        printf("s[%i]=%i\n", i, s->stk[i]);
        }
	printf("\n");
}

struct Stack* stackPush(struct Stack* s, int data) {
	if (s->size < s->capacity) {
		s->stk[s->size] = data;
		++(s->size);
	}
	return s;
}

int main(int argc, char ** argv) {
	struct Stack* s = malloc(sizeof(struct Stack));
	s = stackCreate(5);
 	printf("stk size=%i\n", s->size);
	printf("stk capacity=%i\n", s->capacity);
	printf("stk=\n");

	stackShow(s);

	s = stackPush(s, 5);
	stackShow(s);

	s = stackPush(s, 10);
	stackShow(s);

	s = stackPush(s, 15);
	stackShow(s);

	s = stackPop(s);
	stackShow(s);

	s = stackPush(s, 25);
	stackShow(s);

	s = stackPop(s);
	stackShow(s);

	s = stackPop(s);
	stackShow(s);

	free(s);

	return 0;
}
