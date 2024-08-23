#include <stdio.h>

typedef struct date{
    
    int day;
    int month;
    int year;

}date;

/* A leap year is divisible by 4 but if divisible by 100, it should also be divisible by 400. */
int is_leapyear(int year) {

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return 1;
            } else {
                return 0; 
            }
        } 
        else {
            return 1;
        }
    }

    return 0;
}

int validate_date(date d) {

    switch(d.month) {
        case 01:
            if(d.day <= 31) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 02:
            if(is_leapyear(d.year)) {
                if(d.day <= 29) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            else {
                if(d.day <= 28) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            break;
        case 03:
            if(d.day <= 31) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 04:
            if(d.day <= 30) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 05:
            if(d.day <= 31) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 06:
            if(d.day <= 30) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 07:
            if(d.day <= 31) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 8:
            if(d.day <= 31) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 9:
            if(d.day <= 30) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 10:
            if(d.day <= 31) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 11:
            if(d.day <= 30) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        case 12:
            if(d.day <= 31) {
                return 1;
            }
            else {
                return 0;
            }
            break;
        default:
            return 0;
    }

    return 0;
}

int main() {
    
    date d1;
    printf("Enter date (dd mm yyyy): ");
    scanf("%d%d%d", &d1.day, &d1.month, &d1.year);
    
    if(validate_date(d1)) {
        printf("Date is valid!\n");
    }
    else {
        printf("Date is invalid!\n");
    }

    return 0;
}
