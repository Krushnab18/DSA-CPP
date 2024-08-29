#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack ADT
typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack *stack) {
    if (isEmpty(stack)) return -1; // Error code
    return stack->array[stack->top--];
}

int peek(Stack *stack) {
    if (isEmpty(stack)) return -1; // Error code
    return stack->array[stack->top];
}

void destroyStack(Stack *stack) {
    free(stack->array);
    free(stack);
}

// Utility functions
int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

void infixToPostfix(char *infix, char *postfix) {
    Stack *stack = createStack(strlen(infix));
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        if (isdigit(infix[i])) {
            while (isdigit(infix[i])) {
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // Space to separate numbers
        } else if (isOperator(infix[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[j++] = pop(stack);
                postfix[j++] = ' ';
            }
            push(stack, infix[i]);
            i++;
        } else {
            i++; // Skip invalid characters
        }
    }

    while (!isEmpty(stack)) {
        postfix[j++] = pop(stack);
        postfix[j++] = ' ';
    }
    postfix[j - 1] = '\0'; // Remove the trailing space
    destroyStack(stack);
}

int evaluatePostfix(char *postfix) {
    Stack *stack = createStack(strlen(postfix));
    int i = 0, operand1, operand2, result;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int value = 0;
            while (isdigit(postfix[i])) {
                value = value * 10 + (postfix[i] - '0');
                i++;
            }
            push(stack, value);
        } else if (isOperator(postfix[i])) {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (postfix[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
            }
            push(stack, result);
            i++;
        } else {
            i++;
        }
    }
    result = pop(stack);
    destroyStack(stack);
    return result;
}

int isValid(char *exp) {
    int n = strlen(exp);
    for (int i = 1; i < n; i++) {
        if (isOperator(exp[i - 1]) && isOperator(exp[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    if (!isValid(infix)) {
        printf("Invalid infix expression\n");
        return 1;
    }

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}
