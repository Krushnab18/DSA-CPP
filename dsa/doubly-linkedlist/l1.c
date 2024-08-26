#include <stdio.h>
#include <stdlib.h>
#include "l1.h"

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

void insert_end(DDL *l, int data) {
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
void insert_beg(DDL *l, int data) {
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
        l->front->previous = nn;
        nn->next = l->front;
        l->front = nn;
    }
    return;
}

void displayLR(DDL l) {
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

//Assuming position start from 0
void insert_pos(DDL *l, int pos, int data) {
    int length, count;
    node *p, *nn;
    length = find_length(*l);
    count = 0;
    if(pos >= length || pos < 0) {
        return;
    }
    else if(pos == 0) {
        insert_beg(l, data);
        return;
    }
    else if(pos == length - 1) {
        insert_end(l, data);
        return;
    }

    else {
        nn = (node*)malloc(sizeof(node));

        if(nn) {
            nn->d = data;
            nn->previous = NULL;
            nn->next = NULL;
        }
        else {
            return;
        }

        if(pos > length) {
            return ;
        }
        else {
            p = l->front;
            while(count != pos) {
                p = p->next;
                count++;
            }

            p->previous->next = nn;
            nn->next = p;
            nn->previous = p->previous;
            p->previous = nn;

        }
    }
    return;
}


void displayRL(DDL l) {
    if(isEmpty(l)) {
        printf("List is empty!\n");
    }
    node *p;
    p = l.rear;
    printf("[");
    while(p) {
        printf("%d ", p->d);
        p = p->previous;
    }
    printf("]\n");
    return;
}
int is_palindrome(DDL l);
void remove_beg(DDL *l);
void remove_end(DDL *l);
void remove_pos(DDL *l);
