#include <stdio.h>
#include "../_common/emalloc.h"
#ifndef NODE_H
	#define NODE_H
	#include "node.h"
#endif

/*
 * Create and set default memebrs for a Node.
 * Return a pointer to the created Node.
 */
struct Node*
node_create(int data) {
	struct Node *n = emalloc(sizeof(struct Node));
	n->data = data;
	n->next = NULL;
	return n;
}

/*
 * Create a node with data and append it to head.
 */
void
append_data(struct Node *head, int data) {
	while(head->next != NULL) {
		head = head->next;
	}
	head->next = node_create(data);
	return;
}

/*
 * Return true if the linked list has a Node with data.
 */
bool
contains_data(struct Node* head, int data) {
	struct Node* curr = head;
	while(curr != NULL) {
		if (curr->data == data) {
			return true;
		}
		curr = curr->next;
	}
	return false;
}

/*
 * Free the memory occupied by the linked list.
 */
void
free_nodes(struct Node *head) {
	struct Node *temp;

	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
	free(head);
	return;
}

#ifdef NOT_TESTING
int
main() {
	return 0;
}
#endif
