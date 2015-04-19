/* Stack data type. */
struct Stack;

/* Stack method declarations */
struct Stack* stack_create(int capacity);
void stack_pop(struct Stack *s);
void stack_push(struct Stack *s, int data);
void stack_show(struct Stack *s);
void stack_peek(struct Stack *s);
