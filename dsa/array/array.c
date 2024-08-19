#include <stdio.h>
#include "array.h"
#include <stdlib.h>

void init(array *a, int size) {
	
	a->A = (int *)malloc(sizeof(int)*size);
	a->size = size;
   /* Modified to intialize array with randome element between 0 to 100 as instructed by lab faculty */ 
    for(int i = 0; i < size; i++) {
        a->A[i] = rand()%100;
    }

    a->len = size;
	return;
}

void append(array *a, int ele) { 
    int *newArray = (int *)realloc(a->A, sizeof(int) * (a->size + 1));
    a->A = newArray;         /* Updating the pointer to the newly allocated memory */
    a->A[a->len] = ele;      /* Append the new element */
    a->len++;                /* Incrementing the length */
    a->size++;               /* Incrementing the size since added a new element */

    return;
}

void display(array a) {
	
	for(int i = 0; i < a.len; i++) {
		printf("%d |", a.A[i]);
	}
	
	printf("\n");

	return;
}

void remove_at_index(array *a, int index) {
    
    if (index >= a->len || index < 0) {
        return;  /* Index is out of bounds */
    }
    
    int i = index;

    /* Shifting elements left to fill the gap */
    while (i < a->len - 1) {
        a->A[i] = a->A[i + 1];
        i++;
    }

    /*Decreasing the length of the array */
    a->len--;

    /* resizing the array */
    int *newArray = (int *)realloc(a->A, sizeof(int) * a->len);
    a->A = newArray;
    a->size--;  
    return;
}

void insert_at_index(array *a, int index, int ele) {

    if (index > a->len || index < 0) {
        return;
    }

    int *newArray = (int *)realloc(a->A, sizeof(int) * (a->size + 1));
    a->A = newArray;
    a->size++;

    int i = a->len - 1;

    while (i >= index) {
        a->A[i + 1] = a->A[i];
        i--;
    }

    a->A[index] = ele;
    a->len++;

    return;
}

int max(array a) {
	
	int maximum = a.A[0];
	
	for(int i = 1; i < a.len; i++) {
		if(maximum < a.A[i]) {
			maximum = a.A[i];
		}
	}

	return maximum;
}

int min(array a) {
	
	int minimum = a.A[0];
	
	for(int i = 1; i < a.len; i++) {
		if(minimum > a.A[i]) {
			minimum = a.A[i];
		}
	}

	return minimum;
}

void swap(int *a, int *b) {
	
	int temp = *a;
	*a = *b;
	*b = temp;
	
	return;
}

void reverse(array *a) {
	
	int i, j;
	i = 0;
	j = a->len - 1;
	
	while(i < j) {
		swap(&a->A[i], &a->A[j]);
		i++;
		j--;
	}

	return;
}


void merge(array *a, array *b) {
    /*Reallocating memory for 'a' to accommodate elements from both arrays*/
    int *newArray = (int *)realloc(a->A, sizeof(int) * (a->len + b->len));
    
    a->A = newArray;         
    a->size += b->size;      
    
    for (int i = 0; i < b->len; i++) {
        a->A[a->len] = b->A[i];
        a->len++;
    }
    
    return;
}


void display_menu() {
	
	printf("Please select apropriate choice: \n");
    printf("1 -> To initialize arrays\n");
	printf("2 -> To append element to the array\n");
	printf("3 -> Display contents of array\n");
	printf("4 -> Remove element at specified index\n");
	printf("5 -> Print maximum element of the array\n");
	printf("6 -> Print minimum element of the array\n");
	printf("7 -> Merge two arrays\n");
	printf("8 -> Insert element at given index\n");
    printf("9 -> Quit\n");
    printf("\n");
	return;
}


