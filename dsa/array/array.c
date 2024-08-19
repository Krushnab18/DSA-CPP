#include <stdio.h>
#include "array.h"
#include <stdlib.h>

void init(array *a, int size) {
	
	a->A = (int *)malloc(sizeof(int)*size);
	a->size = size;
	a->len = size;
    
    for(int i = 0; i < size; i++) {
        a->A[i] = rand()%100;
    }

	return;
}

void append(array *a, int ele) {
    
    if(a->len > a->size - 1) {
        return;
    }

	a->A[a->len] = ele;
	a->len++;
	
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
	
	if(index > a->len || index < 0) {
		return;
	}
	
	int i = index;

	while(i < a->len - 1) {
		a->A[i] = a->A[i + 1];
		i++;
	}
    free(&(a->A[a->len - 1]));
	a->len--;

	return;
}

void insert_at_index(array *a, int index, int ele) {
	
	if(index > a->size || index < 0) {
		return;
	}

	int i = a->size - 1;

	while(i > index) {
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

	a->size += b->size;
	
	for(int i = 0; i < b->len; i++) {
		append(a, b->A[i]);
	}
	
	return;
}

void display_menu() {
	
	printf("Please select apropriate choice: \n");
    printf("0 -> To initialize arrays\n");
	printf("1 -> To append element to the array\n");
	printf("2 -> Display contents of array\n");
	printf("3 -> Remove element at specified index\n");
	printf("4 -> Print maximum element of the array\n");
	printf("5 -> Print minimum element of the array\n");
	printf("6 -> Merge two arrays\n");
	printf("7 -> Insert element at given index\n");
    printf("8 -> Quit\n");
    printf("\n");
	return;
}


