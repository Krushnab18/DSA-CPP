#include <stdio.h>
#include "char_stack/stack.h"

void reverse_string(char *str) {
    stack st;
    init_stack(&st);
    int i = 0;
    while(str[i] != '\0') {
        push(&st, str[i]);
        i++;
    }
    i = 0;
    while(!is_empty(st)) {
        str[i++] = pop(&st);
    }
    return;
}

int main() {
    char str[100];
    printf("Enter string\n");
    scanf("%[^\n]", str);
    reverse_string(str);
    printf("%s\n", str);
    return 0;
}
