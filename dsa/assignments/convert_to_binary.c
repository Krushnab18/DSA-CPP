#include <stdio.h>
#include "int_stack/stack.h"

int conver_to_binary(int num) {
    stack st;
    int bin = 0;
    init_stack(&st);
    while(num) {
        push(&st, num % 2);
        num /= 2;
    }
    while(!is_empty(st)) {
        bin = bin * 10 + pop(&st);
    }
    return bin;
}

int main() {
    int num, bin;
    printf("Enter number: \n");
    scanf("%d", &num);
    bin = conver_to_binary(num);
    printf("Number %d with base 2 is %d\n", num, bin);
    return 0;
}
