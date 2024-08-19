#include <stdio.h>

int nearest_lesser(int arr[], int n, int key) {

}

int main() {
    int n, lesser, greater;
    printf("Enter size of array: \n");
    scanf("%d", &n);
    printf("Enter array elements: \n");

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter key to find nearest lesser number: \n");
    
    lesser = nearest_lesser(arr, n);
    greater = nearest_greater(arr, n);

    return 0;
}
