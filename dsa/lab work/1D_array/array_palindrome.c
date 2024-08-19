#include <stdio.h>

int check_palindrome(int arr[], int n) {

    int i, j;
    i = 0;
    j = n - 1;

    while(i < j) {
        if(arr[i] != arr[j]) {
            return  0;
        }
        i++;
        j--;
    }

    return 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void reverse_array(int arr[], int n) {

    int i, j;
    i = 0;
    j = n - 1;
    
    while(i < j) {
        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }

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

    printf("Enter array size: \n");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: \n");

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    if(check_palindrome(arr, n)){
        printf("Given array is Palindrome\n");
    }
    else {
        printf("Given array is not Palindrome\n");
    }
    reverse_array(arr, n);
    printArray(arr, n);
    return 0;
}
