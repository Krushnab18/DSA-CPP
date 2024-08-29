#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>
/*
void init(DLL *l) {
    l->front = NULL;
    l->rear = NULL;
}
void insert_beg(DLL *l, int data) {

}
void insert_end(DLL *l, int data);
void insert_pos(DLL *l, int pos);
void displayLR(DLL l);
void displayRL(DLL l);
int isPalindrome(DLL l);
void removeBeg(DLL *l);
void removeEnd(DLL *l);
void remove_pos(DLL *l, int pos); */
int main() {
    
    DLL l;
    init_DLL(&l);
/*
    insert_beg(&l, 1);  //    to add an element in the end of the  DLL.

    insert_beg(&l, 2);  //    to add an element in the end of the  DLL.

    insert_beg(&l, 3);  //    to add an element in the end of the  DLL.

    displayLR(l);  //   to display all the elements of the list starting from right element to left.

    insert_end(&l, 4);  //    to add an element in the beginning of the  DLL.

    insert_end(&l, 5);  //    to add an element in the beginning of the  DLL.
    
    displayLR(l); //   to display all the elements of the list starting from right element to left.
    
    insert_pos(&l, 1, 67);  //    to add an element at the position specified by user of the  DLL.

    displayLR(l); //   to display all the elements of the list starting from right element to left.
    
    remove_beg(&l); // deletes the first node of the DLL

    displayLR(l); //   to display all the elements of the list starting from right element to left.
    
    remove_end(&l); // deletes the last node of the DLL

    displayLR(l);  //   to display all the elements of the list starting from right element to left.

    remove_pos(&l, 1); //    to delete an element at the position specified by user of the  DLL.

    sort(&l);   // sort the DLL

    displayRL(l);  //   to display all the elements of the list starting from right element to left.

    displayLR(l);  //   to display all the elements of the list starting from left element to right.
    //to do's sort and insert_in_sorted_list

    printf("%d\n",is_palindrome(l));*/
    int arr[10] = {1, 2, 0, 0, 2, 1};
    for(int i = 0; i < 6; i++) {
        insert_beg(&l, arr[i]);
    }
    displayLR(l);

   // sort(&l);
    printf("%d\n", is_palindrome(l));
    displayLR(l);
    
    remove_duplicates(&l);

    displayLR(l);

    return 0;
}
