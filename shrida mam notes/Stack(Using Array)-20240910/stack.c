#include "stack.h"
#include<limits.h>
#include<stdlib.h>

void init(stack *s, int len){
    s->a = (int*)malloc(sizeof(int)*len);
    s->size = len;
    s->top = -1;
}
int isFull(stack s) {
    if(s.top == s.size-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack s) {
    if(s.top == -1)
        return 1;
    else
        return 0;
}
void push(stack *s, int d){
    if(isFull(*s))
        return ;
    else {
        s->top++;
        s->a[s->top] = d;
        return;
    }
}
int pop(stack *s) {
    if(s->top == -1) {
        return INT_MIN;
    }
    int num = s->a[s->top];
    s->top--;
    return num;
}
