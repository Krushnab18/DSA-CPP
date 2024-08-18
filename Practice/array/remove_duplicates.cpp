#include <iostream>
#include <vector>

using namespace std;

int remove_duplicates(int arr[], int n) {
    int count = n;
    for(int i = 0; i < n; i++) {
        if(arr[i] == arr[i+1]) {
            count--;
            int j = i + 1;
            while(j < n - 1) {
                arr[j] = arr[j + 1];
                j++;
            }
            i--;
        }
    }
    
    return count;
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

    int na = remove_duplicates(arr, n);
    
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n No of unique elements: "<<na<<endl;
    cout<<endl;
    return 0;
}
