#include <stdio.h>
#define SIZE 10

int square_sum(int arr[]) {
    int sum = 0;

    for(int i = 0; i < SIZE; i++) {
        sum += arr[i] * arr[i];
    }

    return sum;
}

void diplay_reverse_array(int arr[]) {
    for(int i = SIZE - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return;
}

void diplay_array_triangular(int arr[]) {
    for(int i = 0; i < SIZE; i++) {
        
        for(int j = 0;  j < i + 1; j++) {
            printf("%d ", arr[j]);
        }

        printf("\n");

    }

    return;
}

int main() {
    int arr[SIZE];
    printf("Enter array elements: \n");
    //loop get array elements;
    for(int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }
    
    int sum = square_sum(arr);
    printf("%d is the sum of square of element of given array\n", square_sum(arr));

    printf("Reverse array is: \n");

    diplay_reverse_array(arr);

    printf("Array in Triangular form: \n");

    diplay_array_triangular(arr);

    return 0;
}
