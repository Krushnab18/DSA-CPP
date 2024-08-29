#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_stack/stack.h"

int is_operator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '\0') {
        return 1;
    }
    return 0;
}

int prec(char ch) {
    switch(ch) {
        case '+':
            return 1;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 2;
        case '\0':
            return 0;
    }
    return 0;
}

void infix_to_postfix(char *infix, char *postfix, int len) {
    stack s;
    init_stack(&s);
    int i, j;
    i = 0;
    j = 0;
    while(infix[i] != '\0') {
        if(!is_operator(infix[i])) {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else {
            if(prec(infix[i]) > prec(stack_top(s))) {
                push(&s, infix[i]);
                i++;
            }
            else {
                postfix[j] = pop(&s);
                j++;
            }
        }
    }
    while(!is_empty(s)) {
        postfix[j++] = pop(&s); 
    }
    postfix[j] = '\0';
    return;
}
int isValid(char *exp) {
    int n = strlen(exp);
    for(int i = 1; i < n; i++) {
        if((prec(exp[i - 1]) > 0) && (prec(exp[i]) > 0)) {
            return 0;
        }
    }
    return 1;
}
int main() {
    char infix[100], *postfix;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    int len = strlen(infix);
    printf("%d\n", isValid(infix));
    postfix = (char *)malloc((sizeof(char)) * len);
    if(!postfix)  return;
    infix_to_postfix(infix, postfix, len);
    printf("%s\n", postfix);
    return 0;
}
