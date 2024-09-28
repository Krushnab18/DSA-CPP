#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    list s;
    init(&s);
    append(&s, 3);
    append(&s, 4);
    append(&s, 5);
    append(&s, 3);
    append(&s, 4);
    append(&s, 5);
    display(s);
    insert_at_beg(&s, rand()%100);
    insert_at_beg(&s, rand()%100);
    insert_at_beg(&s, rand()%100);
    insert_at_beg(&s, rand()%100);
    display(s);
    remove_at_pos(&s, 0);
    display(s);
    remove_at_pos(&s, 8);
    display(s);
    return 0;
}
