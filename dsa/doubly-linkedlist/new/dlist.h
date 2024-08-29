typedef struct node{
    int d;
    struct node *previous, *next;
}node;

typedef struct DLL{
    node *rear, *front;
}DLL;

void init_DLL(DLL *l);
void insert_beg(DLL *l, int data);
void insert_end(DLL *l, int data);
void insert_pos(DLL *l, int pos, int data);
void displayLR(DLL l);
void displayRL(DLL l);
int is_palindrome(DLL l);
void remove_beg(DLL *l);
void remove_end(DLL *l);
void remove_pos(DLL *l, int pos);
void sort(DLL *l);
void remove_duplicates(DLL *l);
