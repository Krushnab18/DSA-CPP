#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int main() {
    int arr[SIZE], ans[SIZE], j;

    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 1000;
    }
    
    j = 0;

    for(int i = 0; i < SIZE; i++) {
        if(arr[i] % 8 == 0 || arr[i] % 15 == 0) {
            ans[j++] = arr[i];
        }
    }
    
    printf("Contents of original array: \n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Contents of array having numbers divisible by 8 and 15 \n");
    for(int i = 0; i < j; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
