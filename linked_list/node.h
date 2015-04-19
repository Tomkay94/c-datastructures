#include <stdbool.h>

/* Node datatype */
struct Node;

/* Node methods */
struct Node* node_create(void);
bool hasNode(struct Node* head, int data);
