#include <stdlib.h>
#include "cll.h"

void init(CLL *l) {
    l->front = NULL;
    l->rear = NULL;
}

int is_empty(CLL l) {
    if(l.front == NULL) return 1;
    return 0;
}

void insert_beg(CLL *l, int data) {
    
}
void insert_end(CLL *l, int data);
void display(CLL l);
void insert_pos(CLL *l, int pos);
void remove_beg(CLL *l);
void remove_end(CLL *l);
void remove_pos(CLL *l, int pos);
