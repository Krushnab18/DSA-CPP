#include <stdlib.h>
#include "queue.h"

void qinit(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

int qempty(queue *q) {
    return (q->head == NULL);
}

void enq(queue *q, data d) {
    node *nn = (node *)malloc(sizeof(node));
    if (!nn) {
        return;
    }

    nn->d = d;
    
    if (qempty(q)) {
        nn->next = nn; 
        q->head = nn;
        q->tail = nn;
    } else {
        nn->next = q->head;
        q->tail->next = nn;
        q->tail = nn;
    }
}

data deq(queue *q) {
    if (qempty(q)) {
        exit(1);
    }

    node *temp = q->head;
    data d = temp->d;

    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    } else {
        q->tail->next = q->head->next;
        q->head = q->head->next;
    }

    free(temp);
    return d;
}

int qfull(queue *q) {
    return 0;
}
