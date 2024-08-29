#include <stdio.h>
#include <stdlib.h>
#include "l1.h"

int main() {
    DDL l;
    init(&l);

    printf("Enter 3 elements to insert at begin: \n");
    for(int i = 0; i < 3; i++) {
        insert_beg(&l, i);
    }

    displayLR(l);
    printf("Enter 3 elements to insert at end: \n");
    for(int i = 0; i < 3; i++) {
        insert_end(&l,i + 10);
    }
    for(int i = 0; i < 2; i++) {
        remove_beg(&l);
    }
    displayLR(l);

    displayRL(l);
    int pos, data;
    printf("Enter element and pos to insert in the list: \n");
    scanf("%d", &pos);
    scanf("%d", &data);
    insert_pos(&l, pos, data);
    displayLR(l);

    
    return 0;
}
