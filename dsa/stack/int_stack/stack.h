typedef struct node {
    int data;
    struct  node *next;
}node;

typedef struct stack {
    node *top;
}stack;

void init_stack(stack *s);
void push(stack *s, int data);
int pop(stack *s);
int peek(stack *s, int pos);
int is_empty(stack s);
