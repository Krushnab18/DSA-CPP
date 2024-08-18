#include <iostream>
#include <vector>

using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int left = low;
    int right = mid + 1;
    vector<int> temp;
    //cout<<"Hi these is merge: "<<endl; 
    
    while(left <= mid && right <= high) {
        
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
        
    }   

    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    for(int  i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    return;
}

void merge_sort(int arr[], int low, int high) {
   // cout<<"These is merge sort"<<endl;
    if(low >= high) return;
    int mid = (high + low) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
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

    merge_sort(arr, 0, n - 1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
