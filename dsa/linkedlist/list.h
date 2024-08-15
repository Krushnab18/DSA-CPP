typedef struct  node {
    int value;
    struct node *next;
}node;

typedef node* list;

void init(list *head);
void append(list *head, int data);
void display(list head);
int find_length(list head);
int search(list head, int key);
void remove_element(list *head, int element);
int pop(list *head);
