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

int is_palindrome(DDL l) {
    if(isEmpty(l)) {
        return -1;
    }
    else {
        node *p = l.front, *q = l.rear;
        while(p->next != q->previous) {
            if(p->d != q->d) {
                return 0;
            }
            p = p->next;
            q = q->previous;
        }

    }
    return 1;
}


void remove_beg(DDL *l) {

    if(isEmpty(*l)) {
        return;
    }
    else if(l->front->next == NULL) {
        free(l->front);
        l->front = NULL;
        l->rear = NULL;
        return;
    }
    node *p = l->front;
    l->front = l->front->next;
    l->front->previous = NULL;
    free(p);
    return;
}

void remove_end(DDL *l) {
    if(isEmpty(*l)) {
        return;
    }
    if(l->rear == l->front) {
        node *p = l->rear;
        l->rear = NULL;
        l->front = NULL;
        free(p);
        return;
    }
    else {
        node *p = l->rear;
        l->rear = l->rear->previous;
        l->rear->next = NULL;
        free(p);
    }
    return;
}

void remove_pos(DDL *l, int pos) {
    int i = 0;
    if(isEmpty(*l)) {
        return;
    }
    node *p = l->front;

    if(pos == 0) {
        remove_beg(l);
        return;
    }
    
    while(i < pos && p) {
        p = p->next;
        i++;
    }
    if(p == NULL) {
        return;
    }
    if(p == l->rear) {
        remove_end(l);
        return;
    }
    p->previous->next = p->next;
    p->next->previous = p->previous;
    free(p);
}
void remove_duplicates(DDL *l) {
}
