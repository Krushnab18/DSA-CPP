#include <stdio.h>
#include <stdlib.h>

typedef struct two_stacks{
    int *A;
    int size1, size2;
    int top1, top2;
}two_stacks;

void init_two_stacks(two_stacks *st, int size1, int size2) {
    st->A = (int*)malloc(sizeof(int)*(size1 + size2));
    st->size1 = size1;
    st->size2 = size2;
    st->top1 = -1;
    st->top2 = -1;
    return;
}

int isFull1(two_stacks st) {
    if(st.top1 >= st.size1 - 1) return 1;
    return 0;
}

int isFull2(two_stacks st) {
    if(st.top2 >= st.size2 - 1) return 1;
    return 0;
}

int isEmpty1(two_stacks st){
    if(st.top1 == -1) return 1;
    return 0;
}

int isEmpty2(two_stacks st){
    if(st.top2 == -1) return 1;
    return 0;
}
void push1(two_stacks *st, int data) {
    if(isFull1(*st)) {
        printf("Stack 1 is full\n");
        return;
    }
    st->top1++;
    st->A[st->top1] = data;
    return;
}

void push2(two_stacks *st, int data) {
    if(isFull2(*st)) {
        printf("Stack 2 is full\n");
        return;
    }
    st->top2++;
    st->A[st->size1 + st->top2] = data;
    return;
}

void pop1(two_stacks *st) {
    if(isEmpty1(*st)){
        printf("Stack 1 is empty\n");
        return;
    }
    st->top1--;
    return;
}

void pop2(two_stacks *st) {
    if(isEmpty2(*st)){
        printf("Stack 2 is empty\n");
        return;
    }
    st->top2--;
    return;
}

void print1(two_stacks st) {
    for(int i = 0; i <= st.top1; i++) {
        printf("%d ", st.A[i]);
    }
    printf("\n");
    return;
}

void print2(two_stacks st) {
    for(int i = st.size1; i <= (st.size1 + st.top2); i++) {
        printf("%d ", st.A[i]);
    }
    printf("\n");
    return;
}
int main() {
    two_stacks st;
    printf("Enter size of stack1 and stack 2\n");
    int size1, size2;
    scanf("%d%d", &size1, &size2);
    init_two_stacks(&st, size1, size2);
    push1(&st, 32);
    push2(&st, 33);
    push1(&st, 36);
    pop1(&st);
    push1(&st, 56);
    push2(&st, 45);
    pop2(&st);
    push2(&st, 76);
    print1(st);
    print2(st);
    return 0;
}
