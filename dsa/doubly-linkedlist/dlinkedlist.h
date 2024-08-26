typedef struct node{
    int d;
    struct node *next, *previous;
}node;

typedef struct DDL{
    struct node *front, *rear;
}DDL;

void init(DDL *l);
void insert_using_front_end(DDL *l, int data);
void display(DDL l)
int find_length(DDL l);
void reverse_display(DDL l);
void insert_using_rear_end(DDL *l, int data);
int search(DDL l, int key);
