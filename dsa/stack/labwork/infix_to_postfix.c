#include <stdio.h>
#include <string.h>
#include "char_stack/stack.h"

int is_digit(char ch) {
    if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9') {
        return 1;
    }
    return 0;
}
int is_braces(char ch) {
    if(ch == '(' || ch == ')') return 1;
    return 0;
}
int is_correct_parenthesis(char infix[]) {
    stack st;
    init_stack(&st);
    for (int i = 0; i < strlen(infix); i++) {
        if(infix[i] == '(') {
            push(&st, infix[i]);
        }
        else if(infix[i] == ')') {
            if(is_empty(st)) return 0;
            pop(&st);
        }
    }
    if(is_empty(st)) return 1;
    return 0;
}

int is_operator(char ch) {
    if(ch == '/' || ch == '+' || ch == '-' || ch == '*' || ch == '^') return 1;
    return 0;
}

int is_valid(char infix[]) {
    int n = strlen(infix);
    if(n == 0) return 0;
    if(is_operator(infix[0]) || is_operator(infix[n -1])) return 0;
    if(!is_correct_parenthesis(infix)) return 0;
    for (int i = 1; i < n; i++) {
        if(is_operator(infix[i - 1]) && is_operator(infix[i])) return 0;            
    } 
    return 1;
}

int main() {
    char infix[100];
    printf("Enter infix expression: \n");
    scanf("%[^\n]", infix);

    if(is_valid(infix)) {
        printf("Expression is valid\n");
    }
    else {
        printf("Expression is invalid\n");
    }

    return 0;
}
