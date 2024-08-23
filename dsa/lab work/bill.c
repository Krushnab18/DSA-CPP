#include <stdio.h>

float calculate_bill(float units) {

    float bill = 0.0;
    if (units <= 50) {
        bill = units * 0.50;
    }
    else if (units <= 150) {
        bill = 50 * 0.50 + (units - 50) * 0.75;
    }
    else if (units <= 250) {
        bill = 50 * 0.50 + 100 * 0.75 + (units - 150) * 1.20;
    }
    else {
        bill = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (units - 250) * 1.50;
    }

    bill += bill * 0.20;

    return bill;
}

int main() {
    float units, total;

    printf("Enter units: ");
    scanf("%f", &units);

    total = calculate_bill(units);
    printf("total bill: Rs. %.2f\n", total);

    return 0;
}
