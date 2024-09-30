#include <stdio.h>
#include "stack.h"
#include <limits.h>

void print(stack s) {
    if(is_empty(s)) return;
    node *p = s.top;
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return;
}

int main() {
    stack s;
    init_stack(&s);
    
    for(int i = 0; i < 7; i++) {
        if(i % 2) {
            push(&s, i + 1);
        }
        if((i % 5 == 2) && !is_empty(s)) {
            push(&s, pop(&s) + 1);
        }
        if((i % 4 == 0) && !is_empty(s)) {
           pop(&s); 
        }
        print(s);
    }
    while(!is_empty(s)) {
        printf("%d", pop(&s));
    }
    
    return 0;
}
