#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

int main() {
    DDL l;
    //init
    init(&l);
    printf("Length of doubley linkelist is: %d\n", find_length(l));
    //displayRL
    display(l);
    for(int i = 0; i < 4; i++) {
        insert_using_rear_end(&l, rand() % 100);
    }
    display(l);
    printf("Length of doubley linkelist is: %d\n", find_length(l));
    printf("Dipslay in reverse order: \n");
    //displayLR
    reverse_display(l);
    //Search
    printf("Enter key: \n");
    int key;
    scanf("%d", &key);
    if(search(l, key)) {
        printf("Key found in list\n");
    }
    else {
        printf("Key not found!\n");
    }
    return 0;
}
