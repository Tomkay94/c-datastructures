#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int size;
	int capacity;
	int* stk;
};

struct Stack* makeStack(int capacity) {
	struct Stack *k = malloc(sizeof(struct Stack));
	k->size = 0;
	k->capacity = capacity;
	k->stk = malloc(sizeof(int[capacity])); // size of array with capacity# ints
	return k;
}

struct Stack* pop(struct Stack* s) {
	if (s->size > 0) {
		s->stk[s->size - 1] = 0;
		--(s->size);
	}
	return s;
}

void show(struct Stack *s) {
        int i = 0;
	for(; i < s->capacity; ++i) {
	        printf("s[%i]=%i\n", i, s->stk[i]);
        }
	printf("\n");
}

struct Stack* push(struct Stack* s, int data) {
	if (s->size < s->capacity) {
		s->stk[s->size] = data;
		++(s->size);
	}
	return s;
}

int main(int argc, char ** argv) {
	struct Stack* s = malloc(sizeof(struct Stack));
	s = makeStack(5);
 	printf("stk size=%i\n", s->size);
	printf("stk capacity=%i\n", s->capacity);
	printf("stk=\n");

	show(s);
	s = push(s, 5);
	show(s);
	s = push(s, 10);
	show(s);
	s = push(s, 15);
	show(s);
	s = pop(s);
	show(s);
	s = push(s, 25);
	show(s);
	s = pop(s);
	show(s);
	s = pop(s);
	show(s);

	free(s);
	return 0;
}
