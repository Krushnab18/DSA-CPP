#include <stdio.h>

int fact(int n) {
	if(n == 1 || n == 0) {
		return 1;
	}
	return n * fact(n - 1);
}

int main() {
	int n;
	scanf("%d", &n);
//	printf("%d\n", fact(n));
	int arr[n];
	
	for(int i = 0; i < n ; i++) {
		scanf("%d", &arr[i]);
	}
	
	int s = fact(n);

	for(int i = 0; i < s; i++) {
	//	for(int

	return 0;
}
