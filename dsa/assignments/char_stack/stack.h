typedef struct node {
    char data;
    struct  node *next;
}node;

typedef struct stack {
    node *top;
}stack;

void init_stack(stack *s);
void push(stack *s, char data);
char pop(stack *s);
char peek(stack *s, int pos);
char stack_top(stack s);
int is_empty(stack s);
