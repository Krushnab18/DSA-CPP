#include <stdio.h>

void display_array(int arr[], int len) {

    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return;
}

void insertion_sort(int arr[], int len) {

    for(int i = 1; i < len; i++) {
        int j = i - 1;
        int key = arr[i];
        while(j >= 0 && key > arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return;
}

int main() {
    int n;
    printf("Enter size of array: \n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements separated by spaces: \n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    insertion_sort(arr, n);
    display_array(arr, n);
    return 0;

}
