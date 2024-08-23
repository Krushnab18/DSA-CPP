#include <stdio.h>
#include <stdlib.h>
#include "dlinkedlist.h"

int main() {
   //do something
    DDL l;
    init(&l);
    printf("Length of doubley linkelist is: %d\n", find_length(l));
    display(l);
    for(int i = 0; i < 4; i++) {
        insert_using_rear(&l, rand() % 100);
    }
    display(l);
    printf("Length of doubley linkelist is: %d\n", find_length(l));
    printf("Dipslay in reverse order: \n");
    reverse_display(l);
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
