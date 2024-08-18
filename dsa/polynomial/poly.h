typedef struct term{      
    int coef; //Coefficient
    int exp; //exponent
}term;

typedef struct poly {
    term *P;
    int size;
    int len;
}poly;

void init_poly(poly *p, int size);
void append(poly *p, int coef, int exp);
void display(poly p);
void add_poly(poly *p, poly *q, poly *result);
void sub_poly(poly *p, poly *q, poly *result);
int max(int a, int b);
void sort_according_to_exp(poly *p);
