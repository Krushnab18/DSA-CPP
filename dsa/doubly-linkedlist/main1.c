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
    for(int i = 0; i < 2; i++) {
        remove_beg(&l);
    }
    displayLR(l);

    displayRL(l);
   int pos;
   for(int i = 0; i < 6; i++) {
       scanf("%d", &pos);
       insert_end(&l, pos);
    }


    return 0;
}
