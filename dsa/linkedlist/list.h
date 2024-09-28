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
void remove_at_pos(list *head, int pos);
void insert_at_beg(list *head, int data);
list mergeTwoLists(list *list1, list *list2);
