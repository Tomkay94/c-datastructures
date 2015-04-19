#include <stdio.h>
#include <stdlib.h>
#ifndef LINKED_LIST_H
	#define LINKED_LIST_H
	#include "linkedList.h"
#endif

struct Node {
	int data;
	struct Node* next;
};

int main(int arc, char **argc) {
	// Create size for the nodes
	struct Node* head   = malloc(sizeof(struct Node));
	struct Node* middle = malloc(sizeof(struct Node));
	struct Node* tail   = malloc(sizeof(struct Node));

	// Assign their data
	head->data   = 15;
	middle->data = 20;
	tail->data   = 25;

	// Chain them together
	head->next   = middle;
	middle->next = tail;
	tail->next   = NULL;

	// Create pointer node for traversal
	struct Node* n = malloc(sizeof(struct Node));
	n = head;

	// Traverse the linked list
	while(n != NULL) {
		printf("data is: %i\n", n->data);
		n = n->next;
	}

	return 0;
}
