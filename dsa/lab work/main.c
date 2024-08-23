#include <stdio.h>

int main() {
    float num1, num2, num3, sum;

    printf("Enter three floating point numbers:\n");
    
    scanf("%f %f %f", &num1, &num2, &num3);
    
    sum = num1 + num2 + num3;
    
    printf("The sum is: %.2f\n", sum);
    
    return 0;
}
