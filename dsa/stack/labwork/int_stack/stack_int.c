#include <stdlib.h>
#include "stack_int.h"
#include <limits.h>

void init_stack_int(stack_int *s) {
    s->top = NULL;
    return;
}

int is_empty_int(stack_int s) {
    if(s.top == NULL) {
        return 1;
    }
    return 0;
}

void push_int(stack_int *s, double data) {
    node_int *nn = (node_int*)malloc(sizeof(node_int));
    
    if(nn) {
        nn->data = data;
        nn->next = NULL;
    }
    else {
        return;
    }

    nn->next = s->top;
    s->top = nn;

    return;
}

double pop_int(stack_int *s) {
    node_int *p = s->top;
    double data;
    if(is_empty_int(*s)) return INT_MIN;
    s->top = s->top->next;
    data = p->data;
    free(p);
    return data;
}

int peek_int(stack_int *s, int pos) {
    int i = 1;
    node_int *p = s->top;
    while(i != pos && p->next) {
        p = p->next;
        i++;
    }
    if(i == pos) {
        return p->data;
    }
    else {
        return INT_MIN;
    }
}
