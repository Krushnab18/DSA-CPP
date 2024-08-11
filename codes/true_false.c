#include <stdio.h>
#include <math.h>
int main() {
	
	int n;
	printf("Enter n: \n");
	scanf("%d", &n);
	
	int s = pow(2, n);

	for(int i = 0; i < s; i++) {
		int k = i;
		for(int j = 0; j < n; j++) {
			if(k & 1) {
				printf("True ");
			}
			else {
				printf("False ");
			}
			k = k >> 1;
		}
		printf("\n");
	}
	return 0;
}

