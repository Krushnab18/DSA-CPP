
#include <stdio.h>
#include <string.h>
#include "char_stack/stack_char.h"
#include "int_stack/stack_int.h"
int is_digit(char ch) {
    if(ch >= '0' && ch <= '9') return 1;
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

int is_parenthesis(char ch) {
    if(ch == ')' || ch == '(') return 1;
    return 0;
}
int is_valid(char infix[]) {
    int n = strlen(infix);
    int operator = 0;
    if(n == 0) return 0;
    if(is_operator(infix[0]) || is_operator(infix[n -1])) return 0;
    if(!is_correct_parenthesis(infix)) return 0;
    for (int i = 1; i < n; i++) {
        if(is_operator(infix[i])) operator = 1;
        if(is_parenthesis(infix[i - 1]) && is_parenthesis(infix[i])) return 0;            
        if(is_operator(infix[i - 1]) && is_operator(infix[i])) return 0;            
    }
    if(!operator) return 0;
    return 1;
}


int precedance(char ch) {
    switch(ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 0; // Special case for parentheses
    }
    return -1;
}

void convert_to_postfix(char *infix, char *postfix) {
    if(!is_valid(infix)) return;
    int result_index = 0, i = 0;
    stack operators;
    init_stack(&operators);

    while(infix[i] != '\0') {
        if(is_digit(infix[i])) {
            while(is_digit(infix[i])) {
                postfix[result_index++] = infix[i++];
            }
            postfix[result_index++] = ' ';  
        }

        if(infix[i] == '(') {
            push(&operators, infix[i]);
            i++;
        }

        else if(infix[i] == ')') {
            while(!is_empty(operators) && peek(operators) != '(') {
                postfix[result_index++] = pop(&operators);
                postfix[result_index++] = ' ';  
            }
            pop(&operators);
            i++;
        }

        else if(is_operator(infix[i])) {
            while(!is_empty(operators) && precedance(peek(operators)) >= precedance(infix[i])) {
                postfix[result_index++] = pop(&operators);
                postfix[result_index++] = ' ';
            }
            push(&operators, infix[i]);
            i++;
        }
    }

    while(!is_empty(operators)) {
        postfix[result_index++] = pop(&operators);
        postfix[result_index++] = ' '; 
    }
    postfix[result_index] = '\0'; 
}

double compute(double n1, double n2, char operator) {
    double result = 0;
    switch (operator) {
        case '+':
            result = n1 + n2;
            break;

        case '*':
            result = n1 * n2;
            break;

        case '/':
            result = n1 / n2;
            break;

        case '-':
            result = n1 - n2;
            break;
    }
    return result;
}
double evaluate_postfix(char* postfix) {
    int i = 0;
    double result, n1, n2;
    stack_int st;
    init_stack_int(&st);

    while (postfix[i] != '\0') {
        if (is_digit(postfix[i])) {
            int number = 0;
            while (is_digit(postfix[i])) {
                number = number * 10 + (postfix[i] - '0');
                i++;
            }
            push_int(&st, number);
        } 
        else if (is_operator(postfix[i])) {
            n2 = pop_int(&st);
            n1 = pop_int(&st);
            result = compute(n1, n2, postfix[i]);
            push_int(&st, result);
            i++;
        } 
        else {
            i++;
        }
    }
    return pop_int(&st);
}
int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: \n");
    scanf("%[^\n]", infix);
    convert_to_postfix(infix, postfix);
    printf("Postfix: %s\n", postfix);
    printf("%f\n", evaluate_postfix(postfix));
    return 0;
}
