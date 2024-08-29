#include <stdio.h>

int powe(int x, int n) {
    int ans = 1;
    int term = x;
    while(n > 0) {
        if(n % 2 == 1) {
            ans *= term;
        }
        term *= term;
        n /= 2;
    }
    return ans;
}

int main() {
    int n = 10;
    int x = 2;
    int result = powe(x, n);
    printf("%d\n", result);
    return 0;
}
