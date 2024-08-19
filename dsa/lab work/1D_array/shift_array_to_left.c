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

    int count = 0;
    while(count < n) {

        int last_element = arr[SIZE - 1], i;
        
        for(i = SIZE - 1; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        
        arr[0] = last_element;
        count++;

    }
    
    return;
}
int main() {

    int arr[SIZE];
    printf("Enter array elements(10): \n");
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &arr[i]);
    }
    
    int n;
    printf("Enter n to shift array to left or right by n locations: \n");
    scanf("%d", &n);
    leftshift(arr, n);
    printf("Array before left shift: \n");
    printArray(arr);
    printf("Array after left shift: \n");
    printArray(arr);
    printf("Array before right shift: \n");
    printArray(arr);
    printf("Array after right shift: \n");
    rightshift(arr, n);
    printArray(arr);
    return 0;
}
