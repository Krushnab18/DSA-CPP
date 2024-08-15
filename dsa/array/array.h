typedef struct array {
	int *A;
	int len;
	int size;
}array;

void init(array *a, int size);
void append(array *a, int ele);
void display(array a);
void remove_at_index(array *a, int index);
void insert_at_index(array *a, int index, int ele);
int max(array a);
int min(array a);
void reverse(array *a);
void merge(array *a, array *b);
void swap(int *a, int *b);
void display_menu();
