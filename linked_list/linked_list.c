#include <stdio.h>
#include <stdlib.h>
#ifndef LINKED_LIST_H
	#define LINKED_LIST_H
	#include "linked_list.h"
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
