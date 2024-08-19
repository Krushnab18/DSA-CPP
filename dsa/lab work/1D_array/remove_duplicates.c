#include <stdio.h>

void left_shift(int arr[], int n, int i) {
    for(int j = i; j < n - 1; j++) {
        arr[j] = arr[j + 1];
    }
    return;
}

void remove_duplicates(int arr[], int *n) {
    int len = *n;
    for(int i = 0; i < len; i++) {
        int ele = arr[i];
        for(int j = i + 1; j < len; j++) {
            if(arr[j] == ele) {
                left_shift(arr, len, i);
                len--;
                j--;
            }
        }

    }
    *n = len;
    return;
}

void printArray(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
    return;
}

int main() {
    int n;
    printf("Enter size of array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: \n");

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    
    remove_duplicates(arr, &n);
    printf("Array after removing duplicates\n");
    printArray(arr, n);
    return 0;
}
    
