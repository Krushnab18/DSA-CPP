#include <stdio.h>
#include "array.h"
#include <stdlib.h>

enum {INIT, APPEND, DISPLAY, REMOVE, MAX, MIN, MERGE, INSERT, QUIT};

int main() {
	
	array a;
	array b;
    int choice, index, num, size;
    display_menu();

    while(scanf("%d", &choice)) {
        display_menu();
        switch(choice) {
            case INIT:
                printf("Enter size of array a: \n");
                scanf("%d", &size);
                init(&a, size);
                printf("Enter size of array b: \n");
                scanf("%d", &size);
                init(&b, size);
                break;
            case APPEND:
                append(&a, rand());
                break;
            case DISPLAY:
                printf("Array elements are: \n");
                display(a);
                break;
            case REMOVE:
                printf("Enter the index to remove element: \n");
                scanf("%d", &index);
                remove_at_index(&a, index);
                break;
            case MAX:
                printf("%d is the maximum element in the array a: \n", max(a));
                break;
            case MIN:
                printf("%d is the minimum element in the array a: \n", min(a));
                break;
            case MERGE:
                printf("Array after merge of a and b: \n");
                merge(&a, &b);
                break;
            case INSERT:
                printf("Enter element value and index to insert in array(element index): \n");
                scanf("%d%d", &num, &index);
                insert_at_index(&a, index, num);
                printf("Array after insert operation: \n");
                display(a);
                break;
            case QUIT:
                return 0;
            default:
                printf("Enter valid choice: \n");
                break;
        
        }
        
    }
	init(&a, 7);
	init(&b, 3);

	append(&a, 1);
	append(&a, 2);
	append(&a, 3);
	append(&a, 4);
	append(&a, 5);

	append(&b, 21);
	append(&b, 22);
	append(&b, 32);
	append(&b, 42);
	append(&b, 52);

    printf("Contents of array B: \n");
	display(b);
    printf("Contents of array A: "\n")
	display(a);
	printf("After reverse: \n") of array a and array b;
	reverse(&a);
	display(a);
	
	printf("array after inserting 23 at index 2\n");
	insert_at_index(&a, 2, 23);
	display(a);
	
	printf("array after removing element from index 2\n");
	remove_at_index(&a, 2);
	display(a);

	printf("Max in array a is : %d\n", max(a));
	printf("Max in array b is : %d\n", max(b));
	printf("Min in array a is : %d\n", min(a));
	printf("Min in array b is : %d\n", min(b));
    
	printf("Array after merge of array a and array b:\n");
	merge(&a, &b);
	display(a);

	return 0;
}

