#include<stdio.h>
int f(){
    printf("Executing function");
    return 0;
}

void reverse(void)
{
    char c;
    if ((c = getchar()) != '\n') reverse() ;
    putchar(c);
    return ;
}
int main()
{
    printf ("Enter Text ");
    printf ("\n");
    reverse();
    printf ("\n");
    return 0;
}
