#include<iostream>
#include<vector>

using namespace std;

//function to swap
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

//finding pivot index and moving pivot element to its correct place and also patitioning of the array
int partion(int arr[], int low, int high) {
    int i = low;
    int pivot = arr[low];
    int j = high;
    while(i < j) {
        //move i forward until element is not greater than pivot element
        while(arr[i] <= pivot && i < high) {
            i++;
        }
        //move j backword until element is not lower than pivot element
        while(arr[j] > pivot && i > low) {
            j--;
        }
        //if i did not crossed j swap
        if(i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    //swap pivot element to its correct position
    swap(arr[j], arr[low]);
    return j;
}

//time complexity of best case is nlog(n) and for worst case is n^2

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int pivot_index = partion(arr, low, high);
        //recursive call to quick sort left partioned array
        quick_sort(arr, low, pivot_index - 1);
        //recursive call to quick sort right partioned array
        quick_sort(arr, pivot_index + 1, high);
    }
    return;
}

int main() {
    int n;
    cout<<"Enter array size: "<<endl;
    cin>>n;
    int arr[n];

    cout<<"Enter array elements: "<<endl;

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    quick_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
