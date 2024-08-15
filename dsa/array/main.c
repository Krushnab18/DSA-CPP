#include <stdio.h>
#include "array.h"

int main() {
	
	array a;
	array b;
	
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
	display(a);
	printf("After reverse: \n");
	reverse(&a);
	display(a);
	
	printf("array after inserting 23 at index 2\n");
	insert_at_index(&a, 2, 23);
	display(a);
	
	printf("array after removing element from index 2\n");
	remove_at_index(&a, 2);
	display(a);

	printf("Max is : %d\n", max(a));
	
	printf("Min is : %d\n", min(a));
	
	printf("Array after merge:\n");
	merge(&a, &b);
	display(a);

	return 0;
}

