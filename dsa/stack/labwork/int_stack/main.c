#include <stdio.h>
#include "stack.h"
#include <limits.h>

int main() {
    stack s;
    init_stack(&s);
    for(int i = 0; i < 10; i++) {
        push(&s, (i));
    }
    int data = pop(&s);
    while(data != INT_MIN) {
        printf("%d ", data);
        data = pop(&s);
    }
    printf("\n"); 
    for(int i = 0; i < 10; i++) {
        push(&s, (i));
    }

    printf("%d\n", peek(&s, 5));
    
    return 0;
}
