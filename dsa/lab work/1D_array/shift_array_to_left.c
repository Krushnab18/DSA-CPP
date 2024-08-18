#include <stdio.h>
#define SIZE 10

void leftshift(int arr[], int n) {
    
    int temp[SIZE];

    for(int i = 0; i < SIZE; i++) {
        
        int j; 
        if(i + n >= SIZE) {
            j = (i + n) % SIZE;
            temp[j] = arr[i];
        }
        else{
            temp[i + n] = arr[i];
        }
    }

    for(int i = 0; i < SIZE; i++) {

        arr[i] = temp[i];

    }
    
    return;
}

void printArray(int arr[]) {
    
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return;
}

void rightshift(int arr[], int n) {

    for(int i = 0; i < n; i++) {
        int j;
        if(i - n < 0) {
            //j = i 
        }
    }
    
    return;
}
int main() {

    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    int n;
    printf("Enter n to shift array to left by n locations: \n");
    scanf("%d", &n);
    leftshift(arr, n);
    printf("Array after left shift: \n");
    printArray(arr);
    rightshift(arr, n);
    return 0;
}
