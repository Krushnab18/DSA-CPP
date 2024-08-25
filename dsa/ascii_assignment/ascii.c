#include <stdlib.h>
#include <stdio.h>
#include "ascii.h"

void init_ASCII(ASCII *l) {
    
    l->front = NULL;
    l->rear = NULL;

    return;
}

int isListEmpty(ASCII l) {
    
    if(l.front) {
        return 0;
    }

    return 1;
}

void insert_at_beg(ASCII *l, int data) {
    node *nn;    
    nn = (node *)malloc(sizeof(node));
    
    if(!nn) {
        return;
    }
    else {
        nn->data = data;
        nn->previous = NULL;
        nn->next = NULL;
    }

    if(isListEmpty(*l)) {
        l->front = nn;
        l->rear = nn;
    }
    else {
        l->front->previous = nn;
        nn->next = l->front;
        l->front = nn;
    }

    return;
}

void ASCII_of(ASCII *l, char ch) {
    
    int ascii_value = ch;
    
    while(ascii_value) {
        int digit = ascii_value % 10;
        insert_at_beg(l, digit);
        ascii_value /= 10;
    }

    return;
}
void display_list(ASCII l) {
    
    if(isListEmpty(l)) {
        printf("List is empty!\n");
        return;
    }
    
    node *p = l.front;
    printf("[");
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("]\n");

    return;
}
void destroy_list(ASCII *l) {
    node *p;
    
    while(l->front) {
        p = l->front;
        l->front = l->front->next;
        free(p);
    }

    return;
}
