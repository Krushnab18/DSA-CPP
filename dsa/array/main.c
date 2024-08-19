#include <stdio.h>
#include "array.h"
#include <stdlib.h>

enum {INIT, APPEND, DISPLAY, REMOVE, MAX, MIN, MERGE, INSERT, QUIT};

int main() {
	
	array a, b;
    char ch;
    int choice, index, num, size;
    while(1) {
        display_menu();
        scanf("%d", &choice);
        switch(choice - 1) {
            case INIT:
                printf("Enter size of array a: \n");
                scanf("%d", &size);
                init(&a, size);
                printf("Enter size of array b: \n");
                scanf("%d", &size);
                init(&b, size);
                break;
            case APPEND:
                printf("Enter array name (a or b): \n");
                getchar();
                ch = getchar();
                switch (ch) {
                    case 'a':
                        append(&a, rand() % 100);
                        break;
                    case 'b':
                        append(&b, rand() % 100);
                        break;
                    default:
                        printf("Enter valid array: \n");
                } 
                break;
            case DISPLAY:
                printf("Array a elements are: \n");
                display(a);
                printf("Array b elements are: \n");
                display(b);
                break;
            case REMOVE:
                printf("Enter array name (a or b): \n");
                getchar();
                ch = getchar();
                switch (ch) {
                    case 'a':
                        printf("Enter the index to remove element: \n");
                        scanf("%d", &index);
                        remove_at_index(&a, index);
                        break;
                    case 'b':
                        printf("Enter the index to remove element: \n");
                        scanf("%d", &index);
                        remove_at_index(&b, index);
                        break;
                    default:
                        printf("Enter valid array: \n");
                } 
                break;
            case MAX:
                printf("%d is the maximum element in the array a: \n", max(a));
                printf("%d is the maximum element in the array b: \n", max(b));
                break;
            case MIN:
                printf("%d is the minimum element in the array a: \n", min(a));
                printf("%d is the minimum element in the array b: \n", min(b));
                break;
            case MERGE:
                merge(&a, &b);
                break;
            case INSERT:
                printf("Enter array name (a or b): \n");
                getchar();
                ch = getchar();
                switch (ch) {
                    case 'a':
                        printf("Enter element value and index to insert in array(element index): \n");
                        scanf("%d%d", &num, &index);
                        insert_at_index(&a, index, num);
                        printf("Array after insert operation: \n");
                        display(a);
                        break;
                    case 'b':
                        printf("Enter element value and index to insert in array(element index): \n");
                        scanf("%d%d", &num, &index);
                        insert_at_index(&b, index, num);
                        printf("Array after insert operation: \n");
                        display(b);
                        break;
                    default:
                        printf("Enter valid array: \n");
                } 
                break;
            case QUIT:
                return 0;
            default:
                printf("Enter valid choice: \n");
                break;
        
        }
        
    }

	return 0;
}

