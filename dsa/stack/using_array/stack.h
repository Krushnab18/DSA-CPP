typedef struct stack {
    int top;
    int size;
    int *A;
}stack;

void init(stack *s, int size);
void push(stack *s, int data);
int pop(stack *s);
int peek(stack s);
