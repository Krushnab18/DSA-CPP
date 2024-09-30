#include <stdio.h>
#include "char_stack/stack.h"

int check_parenthesis(char *str) {
    stack square, circular, curly;
    init(square);
    init(circular);
    init(curly);
    int i = 0;
    while(str[i] != '\0') {
        switch (str[i]) {
            case '(':
                push(&circular, str[i]);
                break;
            case ')':
                if(is_empty(cirlular)) return 0;
                pop(&circular);
                break;
            case '{':
                push(&curly, str[i]);
                break;
            case '}':
                if(is_empty(curly)) return 0;
                pop(&curly);
                break;
            case '[':
                push(&square, str[i]);
                break;
            case ']':
                if(is_empty(square)) return 0;
                pop(&square);
                break;
        }
    }
    if(is_empty(circular) && is_empty(square) && is_empty(curly)) return 1;
    return 0;
}

int main() {
    int str[100];
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

