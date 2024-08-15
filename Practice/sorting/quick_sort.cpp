#include<iostream>
#include<vector>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int findPivot(int arr[], int low, int high) {
    int i = low;
    int j = high;
    while(i < j) {
        while(arr[i] <= arr[low] && i < high) {
            i++;
        }
        while(arr[j] > arr[high] && i > low) {
            j--;
        }
        if(i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(arr[j], arr[low]);
    return j;
}

void quick_sort(int arr[], int low, int high) {
    if(low < high) {
        int pivot_index = findPivot(arr, low, high);
        quick_sort(arr, low, pivot_index - 1);
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
