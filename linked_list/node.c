#include <stdio.h>
#include <stdlib.h>
#ifndef NODE_H
	#define NODE_H
	#include "node.h"
#endif

struct Node {
	int data;
	struct Node* next;
};

/* Create and set default memebrs for a Node. */
/* Return a pointer to the created Node. */
struct Node* node_create(void) {
	struct Node *n = malloc(sizeof(struct Node));
	n->next = NULL;
	return n;
}

/* Return true if the linked list has a Node with 
   value data.*/
bool has_node(struct Node* head, int data) {
	struct Node* curr = head;
	while(curr != NULL) {
		if (curr->data == data) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

#ifdef NOT_TESTING
	int main() {
		return 0;
	}
#endif
