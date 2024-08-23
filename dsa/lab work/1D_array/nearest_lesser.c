#include <stdio.h>
#include <limits.h>

int nearest_lesser(int arr[], int n, int key) {
    int nearest = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(arr[i] < key && arr[i] > nearest) {
            nearest = arr[i];
        }
    }
    return nearest;
}

int nearest_greater(int arr[], int n, int key) {
    int nearest = INT_MAX;
    for(int i = 0; i < n; i++) {
        if(arr[i] > key && arr[i] < nearest) {
            nearest = arr[i];
        }
    }
    return nearest;
}
int main() {
    int n, key;
    printf("Enter size of an array: \n");
    scanf("%d", &n);
    int arr[n];

    printf("Enter contents of an array: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter number to which nearest lesser and greater number are required: \n");
    scanf("%d", &key);
    printf("Nearest lesser number is: %d \n", nearest_lesser(arr, n, key));
    printf("Nearest greater number is: %d \n", nearest_greater(arr, n, key));
    
    return 0;
}
