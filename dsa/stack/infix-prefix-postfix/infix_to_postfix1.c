#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "char_stack/stack.h"

// Function to check if a character is an operator
int is_operator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')');
}

// Function to return the precedence of operators
int prec(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
            return 0;  // '(' has the lowest precedence when encountered in stack
    }
    return 0;  // Default return for non-operators
}

// Function to convert an infix expression to postfix
void infix_to_postfix(char *infix, char *postfix, int len) {
    stack s;
    init_stack(&s);
    int i = 0, j = 0;

    while(infix[i] != '\0') {
        // If character is operand, add it to postfix
        if(!is_operator(infix[i])) {
            postfix[j++] = infix[i++];
        }
        // Handle left parenthesis '('
        else if(infix[i] == '(') {
            push(&s, infix[i++]);
        }
        // Handle right parenthesis ')'
        else if(infix[i] == ')') {
            while(!is_empty(s) && stack_top(s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);  // Discard '(' from the stack
            i++;
        }
        // If character is an operator
        else {
            while(!is_empty(s) && prec(stack_top(s)) >= prec(infix[i])) {
                postfix[j++] = pop(&s);
            }
            push(&s, infix[i++]);
        }
    }

    // Pop remaining operators from the stack
    while(!is_empty(s)) {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';  // Null terminate the postfix expression
}

int isValid(char *str) {
    int n = strlen(str);


}
int main() {
    char infix[100], *postfix;
    printf("Enter infix expression: ");
    scanf("%s", infix);

    int len = strlen(infix);
    postfix = (char *)malloc(sizeof(char) * (len + 1));  // Allocate memory for postfix expression
    if (!postfix) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Convert infix to postfix
    infix_to_postfix(infix, postfix, len);

    // Output the postfix expression
    printf("Postfix expression: %s\n", postfix);

    free(postfix);  // Free allocated memory
    return 0;
}
