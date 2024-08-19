#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initial allocation
    int initial_size = 5;
    int *arr = (int *)malloc(initial_size * sizeof(int));
    
    // Check for successful allocation
    if (arr == NULL) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Store some values
    for (int i = 0; i < initial_size; i++) {
        arr[i] = i + 1;
    }

    // Resize the array
    int new_size = 10;
    int *new_arr = (int *)realloc(arr, new_size * sizeof(int));

    // Check for successful reallocation
    if (new_arr == NULL) {
        perror("Failed to reallocate memory");
        free(arr);  // Free the original block
        return 1;
    }

    // Use the resized array
    for (int i = initial_size; i < new_size; i++) {
        new_arr[i] = i + 1;
    }

    // Print all values
    for (int i = 0; i < new_size; i++) {
        printf("%d ", new_arr[i]);
    }
    printf("\n");

    // Free the memory
    free(new_arr);

    return 0;
}

