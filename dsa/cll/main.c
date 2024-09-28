#include <stdio.h>
#include <stdlib.h>
#include "cll.h"

int main() {
    CLL l;
    //call init() // call init for  list
    init(&l);
    // call insert_beg( )  // call multiple times 
    insert_beg(&l, rand()%100);
    insert_beg(&l, rand()%100);
    insert_beg(&l, rand()%100);
    insert_beg(&l, rand()%100);
    insert_beg(&l, rand()%100);
    display(l);

    // insert_end( )  //   // call multiple times  
    insert_end(&l, 34);
    insert_end(&l, rand()%100);
    insert_end(&l, rand()%100);
    insert_end(&l, rand()%100);
    // call display()
    display(l);
    // call insert_pos( ) 
    insert_pos(&l, 22, 0);
    display(l);
    insert_pos(&l, 22, 9);
    display(l);
    // call remove_beg()
    remove_beg(&l);
    display(l);
    // call remove_end() 
    remove_end(&l);
    display(l);
    // call remove_pos()
    remove_pos(&l, 3);
    display(l);
    return 0;
}
