#include <stdio.h>


void merge(int a[], int b[], int c[]) {
    int i = 0, j = 0, k = 0;

    while (i < 5 && j < 5) {
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }

    while (i < 5) {
        c[k++] = a[i++];
    }

    while (j < 5) {
        c[k++] = b[j++];
    }

    return;
}

int main() {

    int a[] = {45, 50, 70, 85, 90};
    int b[] = {30, 40, 60, 75, 80};
    int c[10];

    merge(a, b, c);

    printf("Content of merged array are: \n");

    for(int i = 0; i < 10; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
