#include <iostream>

using namespace std;

void print_all_subarrays(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = i; k < j; k++) {
                cout<<arr[k]<<" ";
            } 
            cout<<endl;
        }
    }
}

int main () {
    int n;
    cout<<"Enter array size: ";
    cin >> n;
    int arr[n];
    
    cout<<"Enter array elements: ";

    for(int i = 0; i < n; i++) {

        cin >> arr[i];

    }

    print_all_subarrays(arr, n);
   
    return 0;
}
