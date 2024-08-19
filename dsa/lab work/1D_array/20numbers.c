#include <stdio.h>

#define SIZE 20

int count_negative_no(int arr[]){
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        if(arr[i] < 0) {
            count++;
        }
    }
    return count;
}

int count_positive_no(int arr[]){
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        if(arr[i] > 0) {
            count++;
        }
    }
    return count;
}

int count_odd_no(int arr[]){
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        if((arr[i] % 2) != 0) {
            count++;
        }
    }
    return count;
}

int count_even_no(int arr[]){
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        if((arr[i] % 2) == 0) {
            count++;
        }
    }
    return count;
}

int count_zeros(int arr[]){
    int count = 0;
    for(int i = 0; i < SIZE; i++){
        if(arr[i] == 0) {
            count++;
        }
    }
    return count;
}
int main() {

    printf("Enter 20 numbers with spaces: \n");
    int arr[SIZE];
    
    for(int i = 0; i < SIZE; i++){
        scanf("%d", &arr[i]);
    }
    
    printf("No of positive numbers: %d\n", count_positive_no(arr));
    printf("No of negative numbers: %d\n", count_negative_no(arr));
    printf("No of odd numbers: %d\n", count_odd_no(arr));
    printf("No of even numbers: %d\n", count_even_no(arr));
    printf("No of 0's: %d\n", count_zeros(arr));

    return 0;
}
