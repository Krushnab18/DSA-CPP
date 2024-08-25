#include <stdio.h>
#include "ascii.h"
int main() {
    
    ASCII l;
    init_ASCII(&l);
    char ch;
    
    printf("Enter character: ");
    ch = getchar();
    ASCII_of(&l, ch);
    printf("List after value function ASCII_of: \n");
    display_list(l);
    destroy_list(&l);
    printf("List after destroy function\n");
    display_list(l);
    
    return 0;
}
