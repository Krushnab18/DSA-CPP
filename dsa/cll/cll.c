#include <stdio.h>
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
    node *nn = (node*)malloc(sizeof(node));
    if(nn) {
        nn->value = data;
        nn->next = NULL;
        nn->previous = NULL;
    }
    if(is_empty(*l)) {
        l->front = nn;
        l->rear = nn;
        nn->next = nn;
        nn->previous = nn;
        return;
    }
    nn->next = l->front;
    nn->previous = l->rear;
    l->front->previous = nn;
    l->rear->next = nn;
    l->front = nn;
    return;
}
void insert_end(CLL *l, int data) {
    node *nn = (node*)malloc(sizeof(node));
    if(nn) {
        nn->value = data;
        nn->next = NULL;
        nn->previous = NULL;
    }
    if(is_empty(*l)) {
        l->front = nn;
        l->rear = nn;
        nn->next = nn;
        nn->previous = nn;
        return;
    }
    nn->next = l->front;
    nn->previous = l->rear;
    l->front->previous = nn;
    l->rear->next = nn;
    l->rear = nn;
    return;
}
void display(CLL l) {
    node *p = l.front;
    printf("[");
    while(p->next != l.front) {
        printf("%d ", p->value);
        p = p->next;
    }
    printf("%d]\n", p->value);
    return;
}
int len(CLL l) {
    int length = 0;
    node *p = l.front;
    while(p != l.rear) {
        length++;
        p = p->next;
    }
    length++;
    return length;
}
//Assuming pos = 0 for front node
void insert_pos(CLL *l, int data, int pos) {
    int n = len(*l);
    node *p = l->front;
    if(pos > n || pos < 0) return;
    node *nn = (node*)malloc(sizeof(node));

    if(nn) {
        nn->next = NULL;
        nn->previous = NULL;
        nn->value = data;
    }

    if(pos == 0) {
        l->rear->next = nn;
        nn->previous = l->rear;
        nn->next = l->front;
        l->front->previous = nn;
        l->front = nn;
        return;
    }
    
    if(pos == n) {
        l->rear->next = nn;
        nn->previous = l->rear;
        nn->next = l->front;
        l->front->previous = nn;
        l->rear = nn;
        return;
    }

    for(int i = 0; i < pos - 1; i++) {
       p = p->next; 
    }
    
    nn->previous = p;
    nn->next = p->next;
    p->next = nn;
    nn->next->previous = nn;
    return;
}
void remove_beg(CLL *l) {
    if(is_empty(*l)) return;
    if(l->front->next == l->front) return;  
    node *p = l->front;
    l->rear->next = l->front->next;
    l->front->next->previous = l->rear;
    l->front = l->front->next;
    free(p);
    return;
}
void remove_end(CLL *l) {
    if(is_empty(*l)) return;
    if(l->front->next == l->front) return;  
    node *p = l->rear;
    p->previous->next = l->front;
    l->rear = p->previous;
    l->front->previous = l->rear;
    free(p);
    return;
}
void remove_pos(CLL *l, int pos) {
    int n = len(*l);
    node *p = l->front;
    if(pos > n || pos < 0) return;

    if(pos == 0) {
        remove_beg(l);
        return;
    }
    
    if(pos == n) {
        remove_end(l);
        return;
    }

    for(int i = 0; i < pos - 1; i++) {
       p = p->next; 
    }
    node *q = p->next;
    p->next = q->next;
    q->next->previous = p;
    free(q);
    return;
}
