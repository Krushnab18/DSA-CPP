typedef struct node_int {
    double data;
    struct  node_int *next;
}node_int;

typedef struct stack_int{
    node_int *top;
}stack_int;

void init_stack_int(stack_int *s);
void push_int(stack_int *s, double data);
double pop_int(stack_int *s);
