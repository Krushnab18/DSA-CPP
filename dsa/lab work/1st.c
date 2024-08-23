#include <stdio.h>

int main() {
    char inchar = 'A';
    switch (inchar)
    {
        case 'A' :
            printf ("choice A \n") ;
        case 'B' :
            printf ("choice B \n") ;
        case 'C' :
            printf ("choice C \n") ;
        case 'D' :
            printf ("choice D \n") ;
        case 'E' :
            printf ("choice E \n") ;
        default:
            printf ("No Choice") ;
    }

    return 0;
}
