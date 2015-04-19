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

int main() {
	return 0;
}
