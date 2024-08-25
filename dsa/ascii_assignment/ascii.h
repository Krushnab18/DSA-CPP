typedef struct node {
    int data;
    struct node *next, *previous;
} node;

typedef struct ASCII {
    node *front, *rear;
} ASCII;

void init_ASCII(ASCII *l);
void ASCII_of(ASCII *l, char ch);
void display_list(ASCII l);
void destroy_list(ASCII *l);
