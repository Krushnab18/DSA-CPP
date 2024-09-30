#include <stdlib.h>
#include "stack.h"
#include <limits.h>

void init_stack(stack *s) {
    s->top = NULL;
    return;
}

int is_empty(stack s) {
    if(s.top == NULL) {
        return 1;
    }
    return 0;
}

void push(stack *s, int data) {
    node *nn = (node*)malloc(sizeof(node));
    
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

int pop(stack *s) {
    node *p = s->top;
    int data;
    if(is_empty(*s)) return INT_MIN;
    s->top = s->top->next;
    data = p->data;
    free(p);
    return data;
}


int peek(stack s) {
    return s.top->data;
}
