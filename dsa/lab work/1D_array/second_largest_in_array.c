#include <stdio.h>
#include <limits.h>

int second_largest(int arr[], int n) {
    
    int max1 = INT_MIN, max2 = INT_MIN;

   for(int i = 0; i < n; i++) {
        if(arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if(arr[i] > max2 && arr[i] < max1) {
            max2 = arr[i];
        }
    }
    return max2;

}

int main() {
    
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    
    printf("Enter array elements: \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Second largest number in the array is: %d\n", second_largest(arr, n));

    return 0;
}
