/* Stack data type. */
struct Stack;

/* Stack method declarations */
struct Stack* stackCreate(int capacity);
struct Stack* stackPush(struct Stack* s, int data);
struct Stack* stackPop(struct Stack* s);
