#include <stdbool.h>

/* Node datatype */
struct Node;

/* Node methods */
struct Node* node_create(int data);
bool contains_data(struct Node *head, int data);
void remove_data(struct Node *head, int data);
void append_data(struct Node *head, int data);
