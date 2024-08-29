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

void push(stack *s, char data) {
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
char pop(stack *s) {
    node *p = s->top;
    char data;
    if(is_empty(*s)) return '\0';
    s->top = s->top->next;
    data = p->data;
    free(p);
    return data;
}
char peek(stack *s, int pos) {
    int i = 1;
    node *p = s->top;
    while(i != pos && p->next) {
        p = p->next;
        i++;
    }
    if(i == pos) {
        return p->data;
    }
    else {
        return '\0';
    }
}

char stack_top(stack s) {
    if(is_empty(s)) return '\0';
    return s.top->data;
}
