#include <iostream>
using namespace std;

void moveAllzeros(int arr[], int n) {
	for(int i = 0; i < n; i++) {
		if(arr[i] == 0) {
			int j;
			for(j = i; j < n - 1; j++) {
				arr[j]= arr[j + 1];
			}
			arr[j] = 0;
		}
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	
	for(int i = 0; i < n; i++) {
		cin>>arr[i];
	}
	
	moveAllzeros(arr, n);
	
	for(int i = 0; i < n; i++) {
		cout<<arr[i]<<" ";
	}
	
	return 0;

}
