typedef struct node{
  int value;
  struct node *next, *previous;
}node;

typedef struct CLL{
  node *front, *rear;
}CLL;

void init(CLL *l);
void insert_beg(CLL *l, int data);
void insert_end(CLL *l, int data);
void display(CLL l);
void insert_pos(CLL *l, int data, int pos);
void remove_beg(CLL *l);
void remove_end(CLL *l);
void remove_pos(CLL *l, int pos);
int is_empty(CLL l);
