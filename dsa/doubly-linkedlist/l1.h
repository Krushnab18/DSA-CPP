typedef struct node{
    int d;
    struct node *next, *previous;
}node;

typedef struct DDL{
    struct node *front, *rear;
}DDL;

void init(DDL *l);
void insert_beg(DDL *l, int data);
void insert_end(DDL *l, int data);
void displayLR(DDL l);
void insert_pos(DDL *l, int pos, int data);
void displayRL(DDL l);
int is_palindrome(DDL l);
void remove_beg(DDL *l);
void remove_end(DDL *l);
void remove_pos(DDL *l);
