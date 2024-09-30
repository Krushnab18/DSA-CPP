#include <stdio.h>
#include "int_stack/stack.h"

int is_matching_pair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '[' && closing == ']') ||
           (opening == '{' && closing == '}');
}

int check_parenthesis(char *str) {
    stack st;
    init_stack(&st);
    int i = 0;
    while(str[i] != '\0') {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            push(&st, str[i]);
        }
        else {
            if(is_empty(st)) return 0;

            if(is_matching_pair(peek(st), str[i])){
                pop(&st);
            }
            else {
                return 0;
            }
        }
        i++;
    }
    return is_empty(st);
}

int main() {
    char str[100];
    printf("Enter expresssion\n");
    scanf("%[^\n]", str);
    if(check_parenthesis(str)) {
        printf("True\n");
    }
    else {
        printf("False\n");
    }
    return 0;
}

