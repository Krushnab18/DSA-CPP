#include <stdio.h>
#include <stdlib.h>
#include "l1.h"

int main() {
    DDL l;
    init(&l);
   
    for(int i = 0; i < 3; i++) {
        insert_beg(&l, i);
    }
    
    displayLR(l);

    for(int i = 0; i < 3; i++) {
        insert_end(&l,i + 10);
    }

    displayLR(l);

    displayRL(l);
   int pos;
   scanf("%d", &pos);

    insert_pos(&l, pos,45);

    displayLR(l);

    return 0;
}
