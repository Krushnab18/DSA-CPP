#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

void init_poly(poly *p, int size) {
    
    p->P = (term *)malloc(sizeof(term) * size);
    p->size = size;
    p->len = 0;
    
    return;

}

void append(poly *p, int coef, int exp) {
    
    if(p->len < p->size) {
        int i = p->len;
        p->P[i].coef = coef;
        p->P[i].exp = exp;
        p->len++;
    }

    return;

}

void display(poly p) {
    int i;
    printf("\n");
    for(i = 0; i < p.len - 1; i++) {
        printf("(%d)x^%d + ", p.P[i].coef, p.P[i].exp);
    }
    
    printf("(%d)x^%d\n\n", p.P[i].coef, p.P[i].exp);
    return;
}

void sort_according_to_exp(poly *p) {
    //Using insertion sort
    int i = 1, n = p->len;

    while(i < n) {

        int ele, j, coef;
        ele = p->P[i].exp;
        j = i - 1;
        coef = p->P[i].coef;

        while(j >= 0 && ele > p->P[j].exp) {
            p->P[j + 1].exp = p->P[j].exp;
            p->P[j + 1].coef = p->P[j].coef;
            j = j - 1;
        }

        p->P[j + 1].exp = ele;
        p->P[j + 1].coef = coef;
        i++;

    }

    return;
}
//These function fails if user inputs same exponent term multiple times
poly convert_to_standard_form(poly *p, int max_exp) {

    int i = 0;
    poly standard_form;
    int size = max_exp + 1;
    init_poly(&standard_form, size);
    while(max_exp >= 0) {
        
        if(p->P[i].exp == max_exp && i < p->len) {
            append(&standard_form, p->P[i].coef, max_exp);
            i++;
        }
        else {
            append(&standard_form, 0, max_exp);
        }
       
        max_exp--;
    }
    return standard_form;

}

int max(int a, int b) {

    if(a > b) {
        return a;
    }
    
    return b;
}

void add_poly(poly *p, poly *q, poly *result) {
    
    sort_according_to_exp(p);
    sort_according_to_exp(q);
    int max_exp = max(p->P[0].exp, q->P[0].exp);
    poly standard_form_q, standard_form_p;
    init_poly(&standard_form_p, max_exp + 1);
    standard_form_p = convert_to_standard_form(p, max_exp);
    standard_form_q = convert_to_standard_form(q, max_exp);
   
    for(int i = 0; i <= max_exp; i++) {
        append(result, standard_form_p.P[i].coef + standard_form_q.P[i].coef, standard_form_q.P[i].exp);
    }
    return;

}

void sub_poly(poly *p, poly *q, poly *result) {
    
    sort_according_to_exp(p);
    sort_according_to_exp(q);
    int max_exp = max(p->P[0].exp, q->P[0].exp);
    poly standard_form_q, standard_form_p;
    init_poly(&standard_form_p, max_exp + 1);
    standard_form_p = convert_to_standard_form(p, max_exp);
    standard_form_q = convert_to_standard_form(q, max_exp);
   
    for(int i = 0; i <= max_exp; i++) {
        append(result, standard_form_p.P[i].coef - standard_form_q.P[i].coef, standard_form_q.P[i].exp);
    }
    return;

}


