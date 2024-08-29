#include<stdio.h>
#include "stack.h"
#include<limits.h>

int main() {
    stack s1, s2;
    init(&s1,100);
    init(&s2, 10);
    int item;
    while(scanf("%d", &item)!= -1)
        push(&s1, item);
    printf("Stack 1\n");
    while((item = pop(&s1))!= INT_MIN)
        printf("%d\n", item);
    return 0;
}

