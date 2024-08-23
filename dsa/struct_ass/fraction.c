#include <stdio.h>

typedef struct fraction {

    int numerator;
    int denominator;

}fraction;

int compare_fraction(fraction f1, fraction f2) {

    double d1, d2;
    d1 = f1.numerator / f1.denominator;
    d2 = f2.numerator / f2.denominator;

    if(d1 == d2) {
        return 0;
    }
    else if(d1 < d2) {
        return -1;
    }
    
    return 1;
}

int main() {

    fraction f1, f2;

    printf("Enter numerator and denominator of fraction 1: ");
    scanf("%d%d", &f1.numerator, &f1.denominator);
    printf("Enter numerator and denominator of fraction 2: ");
    scanf("%d%d", &f2.numerator, &f2.denominator);
    printf("Function returns: %d\n", compare_fraction(f1, f2));

    return 0;
}
