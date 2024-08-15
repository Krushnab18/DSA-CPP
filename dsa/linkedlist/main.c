#include <stdio.h>
#include "list.h"

int main(){
    list l;
    init(&l);
    append(&l, 3);
    append(&l, 4);
    append(&l, 5);
    display(l);
    printf("%d\n", find_length(l));
    printf("Enter key to find: \n");
    int key;
    scanf("%d", &key);
    printf("%d\n", search(l, key));
    printf("Enter element to remove: \n");
    scanf("%d", &key);
    remove_element(&l, key);
    display(l);
    printf("%d\n",pop(&l));
    display(l);
    return 0;
}
