#include <stdio.h>
#include "list.h"

int main(){
    node *l;
    list s;
    init(l);
    printf("%p\n", l);
    init(&s);
    append(&l, 3);
    append(&l, 4);
    append(&l, 5);
    append(&s, 3);
    append(&s, 4);
    append(&s, 5);
    display(l);
    display(s);
   /* printf("%d\n", find_length(l));
    printf("Enter key to find: \n");
    int key;
    scanf("%d", &key);
    printf("%d\n", search(l, key));
    printf("Enter element to remove: \n");
    scanf("%d", &key);
    remove_element(&l, key);
    display(l);
    printf("%d\n",pop(&l));
    display(l);*/
    printf("merged list\n");
    list m = mergeTwoLists(&l, &s);
    display(m);
    return 0;
}
