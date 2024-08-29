#include <stdio.h>
#include "stack.h"
#include <limits.h>
#include <string.h>
int main() {
    stack s;
    init_stack(&s);
    char ch[100];
    printf("Enter string: \n");
    scanf("%s", ch);
    int len = strlen(ch);
    for(int i = 0; i < len; i++) {
        push(&s, ch[i]);
    }
    printf("%c \n", stack_top(s));
    return 0;
}
