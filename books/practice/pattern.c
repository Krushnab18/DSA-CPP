#include <stdio.h>
int main(){
int n = 10;
for(int i = 1;i<n;i++){
    for(int j = 1; j<i;j++){
        printf("%d",j);
        }
        printf("\n");
}    
// int n = 4;
// for(int i = 1; i<=4;i++){
//     for(int j = 1;j<=4; j++){
//         printf("%d",j);
//     }
//     printf("\n");
// }
// int n = 10;
// for(int i = 1;i<n;i++){
//     for(int j = 1; j<n-i;j++){
//         printf("%d",j);
//         }
//         printf("\n");
// }
// int n;
// printf("Enter a number ");
// scanf("%d",&n);
// for(int i = 1; i<=n;i++){
//     for(int j = 1 ; j<(2*i);j++){
//         if(j%2!=0){ 
//             printf("%d",j);
//         }
//     }printf("\n");
// }

// int n ;
// printf("Enter a number");
// scanf("%d",&n);
// for(int i=1;i<=n;i++){
//     for(int j = 65; j<65+i;j++){
//         if(i%2!=0){
//     printf("%c",(char)j);}
//     else{
//         printf("%d",j-64);
//     }
//     }
//     printf("\n");
// }
// int n = 5 ;
// if(n%2==0){
//     printf("this can't print the pattern");

// }
// else{
//     for(int i=1 ; i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             if(j==(n/2 + 1)){
//                 for(int k = 1;k<=n;k++)
//             {
//                 printf("*");

//             }         
//             }
//             else
//             {
//                 printf("*");
                
//             }   
//         }
//         printf("\n");
//     }
// }

// int n;
// printf("Enter a number");
// scanf("%d",&n);

// if(n%2==0)
// {
//     printf("this cannot be work");
// }
// else
// {


// for(int i = 1; i<=n;i++)
// {
//     if(i==(n/2 + 1 ))
//     {
//         for(int j= 1; j<=n; j++)
//         {
//             printf("*");
//         }
//         printf("\n");

//     }
//     else
//     {
//         for(int k = 1;k<=n/2;k++)
//         {
//             printf(" ");
//         }
//         printf("*\n");
//     }
//     // printf(" "*(n/2));

// }



// }


// int i = 5, k;
// k = 6;

/* evaluate to 0 or 1 for all relational operators*/
// printf("%d\n%d\n%d\n", k++,k++,k++);
// if(5)
// printf("I am in if");

// int i = 0;
// for(; ;) {
// if(i > 10){
// break;}
// else{
//     printf("%d",i);
// continue;

// i = i +1;}
// }
    // int a[5]={1,23,3,253,36};
    // printf("\n%d",a[2]);
    // char text b[4] = "onkar";
    // printf("%s",b);
    // int c= 10;
    // char d = (char)4;
    // printf("%c",d);




return 0;
}