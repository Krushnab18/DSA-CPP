#include<stdio.h>
#include<stdlib.h>
int main() {
    int c, n;
    printf("Ten random numbers in [50,100]\n");
    for (c = 1; c <= 10; c++) {
        n = rand() % 51 + 50;  /*rand() % 51 returns numbers from 0 to 50 adding 50 makes it to 50 to 100 */
        printf("%d\n", n);
    }
    return 0;
}
