#include <stdio.h>
#include "list.h"
#include <stdlib.h>
#include <limits.h>

void init(list *head) {
  *head = NULL;
  return;
}
void append(list *head, int data) {

  node *newnode, *p;
  newnode = (node*)malloc(sizeof(node));

  if(newnode) {
    newnode->value = data;
    newnode->next = NULL;
  }
  else return;

  if(*head == NULL) {
    *head = newnode;
    return;
  }

  p = *head;

  while(p->next) {
    p = p->next;
  }

  p->next = newnode;

  return;
}

void display(list l) {

  node *p = l;
  printf("[");

  while(p) {
    printf("%d ", p->value);
    p = p->next;
  }

  printf("]\n");

  return;
}

int find_length(list head) {

  node *p;
  p = head;
  int len = 0;

  while(p) {
    len++;
    p = p->next;
  }

  return len;
}

int search(list head, int key) {

  node *p;
  p = head;

  while(p) {
    if(p->value == key) {
      return 1;
    }
    p = p->next;
  }

  return 0;
}

void remove_element(list *head, int element) {

  node *p, *q;
  p = *head;

  while(p && p->value != element) {
    q = p;
    p = p->next;
  }

  if(p == *head) {
    *head = p->next;
    free(p);
    return;
  }

  if(p) {
    q->next = p->next;
    free(p);
  }

  return;
}

int isListEmpty(list *head) {

  if (*head == NULL) {
    return 1;
  }

  return 0;
}

int pop(list *head) {

  if(isListEmpty(head)) {
    return INT_MIN;
  }

  int ele = (*head)->value;
  *head = (*head)->next; 
  return ele;
}

node* mergeTwoLists(list *list1, list *list2) {
  node *p, *q, *newlist;
  p = *list1;
  q = *list2;
  newlist = NULL;
  while(p && q) {
    if((p->value <= q->value) && p && q) {
      append(&newlist, p->value);
      p = p->next;
    }
    else if((p->value >= q->value) && p && q) {
      append(&newlist, q->value);
      q = q->next;
    }
  }
  while(p) {
    append(&newlist, p->value);
    p = p->next;
  }
  while(q) {
    append(&newlist, q->value);
    q = q->next;
  }
  return newlist;
}

void insert_at_beg(list *head, int data) {
  node *nn = (node*)malloc(sizeof(node));
  if(nn) {
    nn->value = data;
    nn->next = NULL;
  }
  nn->next = *head;
  *head = nn;
  return;
}

void remove_at_pos(list *head, int pos) {
  int n = find_length(*head);
  if(pos > n || pos < 0) return;
  node *p = *head;
  if(pos == 0) {
    *head = (*head)->next;
    free(p);
    return;
  }
  for(int i = 0; i < pos - 1; i++) {
    p = p->next;
  }
  node *q = p->next;
  p->next = q->next;
  free(q);
  return;
}
