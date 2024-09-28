#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

void printmenu() {
    printf("Please select one of the option\n");
    printf("1. init\n");
    printf("2. push\n");
    printf("3. pop\n");
    printf("4. peek\n");
    printf("5. Exit\n");
    return;
}


int main() {
    int a = 1, size;
    char ch;
    stack s;
    printmenu();
    while(a) {
        scanf("%c", &ch);
        switch(ch) {
            case '1':
                scanf("%d", &size);
                getchar();
                init(&s, size);
                break; case '2':
                push(&s, rand()%100);
                break;
            case '3':
                printf("%d\n", pop(&s));
                break;
            case '4':
                printf("%d\n", peek(s));
                break;
            case '5':
                a = 0;
                break;
        }
    }
    return 0;
}
