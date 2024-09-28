#include <stdlib.h>
#include "stack.h"

void init(stack *s, int size) {
    s->A = (int*)malloc(sizeof(int));
    s->top = -1;
    s->size = size;
}

int is_full(stack s) {
    if(s.top == s.size) return 1;
    return 0;
}

void push(stack *s, int data) {
    if(is_full(*s)) return;
    s->top++;
    s->A[s->top] = data;
    return;
}
int pop(stack *s) {
    return s->A[s->top--];
}

int peek(stack s) {
    return s.A[s.top];
}
