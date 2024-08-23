#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

void init(DDL *l) {
    l->front = NULL;
    l->rear = NULL;
    return;
}

int isEmpty(DDL l) {
    if(l.front == NULL) {
        return 1;
    }
    return 0;
}

void insert_using_front(DDL *l, int data) {
    node *nn = (node*)malloc(sizeof(node));
    if(nn) {
        nn->next = NULL;
        nn->previous = NULL;
        nn->d = data;
    }
    else {
        return;
    }

    if(isEmpty(*l)) {
        l->front = nn;
        l->rear = nn;
        return;
    }
    else {
        node *p = l->front;
        while(p->next) {
            p = p->next;
        }
        p->next = nn;
        nn->previous = p;
        l->rear = nn;
    }
    return;
}
void display(DDL l) {
    if(isEmpty(l)) {
        printf("List is empty!\n");
    }
    node *p;
    p = l.front;
    printf("[");
    while(p) {
        printf("%d ", p->d);
        p = p->next;
    }
    printf("]\n");
    return;
}
int find_length(DDL l) {
    node *p = l.front;
    int len = 0;
    while(p) {
        len++;
        p = p->next;
    }
    return len;
}
void reverse_display(DDL l) {
    node *p = l.rear;
    if(isEmpty(l)) {
        printf("List is empty!\n");
    }
    printf("[");
    while(p) {
        printf("%d ", p->d);
        p = p->previous;
    }
    printf("]\n");
    return;
}

void insert_using_rear(DDL *l, int data) {
    node *nn = (node*)malloc(sizeof(node));
    if(nn) {
        nn->next = NULL;
        nn->previous = NULL;
        nn->d = data;
    }
    else {
        return;
    }

    if(isEmpty(*l)) {
        l->front = nn;
        l->rear = nn;
        return;
    }
    else {
        l->rear->next = nn;
        nn->previous = l->rear;
        l->rear = nn;
    }
    return;
}

int search(DDL l, int key) {
    node *p = l.front;
    while(p) {
        if(p->d == key) {
            return 1;
        }
        p = p->next;
    }
    return 0;
}
