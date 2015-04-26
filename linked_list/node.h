#include <stdbool.h>

/*
 * Node data type.
 */
struct Node {
	int data;
	struct Node* next;
};

/*
 * Node prototypes.
 */
struct Node*
node_create(int data);

bool
contains_data(struct Node *head, int data);

bool
remove_data(struct Node *head, int data);

void
append_data(struct Node *head, int data);

void
free_nodes(struct Node *head);
