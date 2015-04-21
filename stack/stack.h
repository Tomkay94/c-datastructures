/* Stack data type. */
struct Stack;
struct Node;

/* Stack prototypes */
struct Stack* stack_create();
struct Node* node_create(int data);

void stack_pop(struct Stack *s);
void stack_push(struct Stack *s, int data);
void stack_show(struct Stack *s);
int stack_peek(struct Stack *s);
