#include <stdio.h>
#include <stdlib.h>
#include "poly.h"

/* Initialize polynomial with given size */
void init_poly(poly *p, int size) {
    p->P = (term *)malloc(sizeof(term) * size);
    if (p->P == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    p->size = size;
    p->len = 0;
}

/* Function to Append a term to the polynomial */
void append(poly *p, int coef, int exp) {
    /* Checking if there's space to append */
    if (p->len < p->size) {
        p->P[p->len].coef = coef;
        p->P[p->len].exp = exp;
        p->len++;
    } else {
        /* Reallocating memory if needed */
        p->size *= 2;
        p->P = (term *)realloc(p->P, sizeof(term) * p->size);
        if (p->P == NULL) {
            printf("Memory reallocation failed\n");
            exit(1);
        }
        p->P[p->len].coef = coef;
        p->P[p->len].exp = exp;
        p->len++;
    }
}

/* Display polynomial in proper format */
void display(poly p) {
    if (p.len == 0) {
        printf("Polynomial is empty\n");
        return;
    }

    for (int i = 0; i < p.len - 1; i++) {
        printf("(%d)x^%d + ", p.P[i].coef, p.P[i].exp);
    }
    printf("(%d)x^%d\n", p.P[p.len - 1].coef, p.P[p.len - 1].exp);
}

/* Sort polynomial terms according to exponent in descending order */
void sort_according_to_exp(poly *p) {
    /* Using insertion sort */
    int i = 1, n = p->len;

    while (i < n) {
        int exp = p->P[i].exp;
        int coef = p->P[i].coef;
        int j = i - 1;

        /* Shifting terms to make space for the current term */
        while (j >= 0 && exp > p->P[j].exp) {
            p->P[j + 1].exp = p->P[j].exp;
            p->P[j + 1].coef = p->P[j].coef;
            j--;
        }

        p->P[j + 1].exp = exp;
        p->P[j + 1].coef = coef;
        i++;
    }
}

/* Converting polynomial to standard form with all exponents from max_exp to 0 */
poly convert_to_standard_form(poly *p, int max_exp) {
    poly standard_form;
    int size = max_exp + 1;
    init_poly(&standard_form, size);

    for (int exp = max_exp; exp >= 0; exp--) {
        int found = 0;
        for (int i = 0; i < p->len; i++) {
            if (p->P[i].exp == exp) {
                append(&standard_form, p->P[i].coef, exp);
                found = 1;
                break;
            }
        }
        if (!found) {
            append(&standard_form, 0, exp);
        }
    }
    return standard_form;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

/* Function to Add two polynomials and store the result in the third polynomial */
void add_poly(poly *p, poly *q, poly *result) {
    sort_according_to_exp(p);
    sort_according_to_exp(q);

    int max_exp = max(p->P[0].exp, q->P[0].exp);
    poly standard_form_p = convert_to_standard_form(p, max_exp);
    poly standard_form_q = convert_to_standard_form(q, max_exp);

    init_poly(result, max_exp + 1);

    for (int i = 0; i <= max_exp; i++) {
        int coef_sum = standard_form_p.P[i].coef + standard_form_q.P[i].coef;
        append(result, coef_sum, standard_form_q.P[i].exp);
    }

    free(standard_form_p.P);
    free(standard_form_q.P);
}

/* Function to Subtract second polynomial from the first and store the result in the third polynomial */
void sub_poly(poly *p, poly *q, poly *result) {
    sort_according_to_exp(p);
    sort_according_to_exp(q);

    int max_exp = max(p->P[0].exp, q->P[0].exp);
    poly standard_form_p = convert_to_standard_form(p, max_exp);
    poly standard_form_q = convert_to_standard_form(q, max_exp);

    init_poly(result, max_exp + 1);

    for (int i = 0; i <= max_exp; i++) {
        int coef_diff = standard_form_p.P[i].coef - standard_form_q.P[i].coef;
        append(result, coef_diff, standard_form_q.P[i].exp);
    }

    free(standard_form_p.P);
    free(standard_form_q.P);
}
