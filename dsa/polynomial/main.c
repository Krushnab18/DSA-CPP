#include <stdio.h>
#include "poly.h"

int main() {

    poly p, q, addition, subtraction;
    int size1, size2, coef, exp, max_exp;

    printf("Enter size of Polynomial 1: \n");
    scanf("%d", &size1);
    printf("Enter size of Polynomial 2: \n");
    scanf("%d", &size2);
    init_poly(&p, size1);
    init_poly(&q, size2);
    
    printf("Enter coef and exp of polynomial 1: (x^2+x^1+1 --> 1 2 1 1 1 0): \n");

    for(int i = 0; i < size1; i++) { 
        scanf("%d%d", &coef, &exp);
        append(&p, coef, exp);
    }
    
    printf("Enter coef and exp of polynomial 1: (x^2+x^1+1 --> 1 2 1 1 1 0): \n");

    for(int i = 0; i < size2; i++) { 
        scanf("%d%d", &coef, &exp);
        append(&q, coef, exp);
    }

    max_exp = max(p.P[0].exp, q.P[0].exp);
    init_poly(&addition, max_exp+1);
    init_poly(&subtraction, max_exp+1);
    display(p);
    display(q);
    add_poly(&p, &q, &addition);
    printf("Addition of the two polynomial is: \n");
    display(addition);
    sub_poly(&p, &q, &subtraction);
    printf("Subtraction of the two polynomial is: \n");
    display(subtraction);

   /* sort_according_to_exp(&p);
    display(p);
    display(q);*/
    return 0;
    
}
