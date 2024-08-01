#include <stdio.h>
#include<math.h>

int main(){
    // now i am looking for the loop 
    // printf("this is my code ");
    // // first we will see the for loop 
    // for(int i=1;i<=10;i++){
    //     printf("\t %d",i);
    // }
    // Print all even numbers from 1 to 100
    
    
    // for(int i = 2;i<100;i=i+2){
    //     printf("\t%d",i);
    // }
        
    // for(int i = 1;i<100;i=i+2){
    //     printf("\t%d",i);
    // }
    
    //Print the table of 19
//    int a ,b ;
//    printf("Enter a number to print its table = ");
//   scanf("%d",&a);

//    for(int i = 1;i<=10;i++){
//         b = a*i;
//         printf("%d x %d = %d\n",a,i,b);
//    } 
    
    
    //Print the AP - 1,3,5,7,9.. upto ‘n’ terms
    // int n ;
    // printf("Enter the terms you want in your AP = ");
    // scanf("%d",&n);
    // printf("now this  is your AP up to the %d = ",n);
    // for(int i=1;i<=n;i=i+2){
    //        printf("%d\t",i);
    // }
    
    // Print the GP - 1,2,4,8,16.. upto ‘n’ terms
    // int n ;
    // printf("Enter the terms you want in your AP = ");
    // scanf("%d",&n);
    // printf("now this  is your GP up to the %d = ",n);
    // for(int i=1;i<=n;i=i*2){
    //        printf("%d\t",i);
    // }
    // Print the GP - 3,12,48.. upto ‘n’ terms

    // int n ;
    //     printf("Enter the terms you want in your GP = ");
    //     scanf("%d",&n);
    //     printf("now this  is your GP up to the %d = ",n);
    //     for(int i=3;i<=n;i=i*4){
    //         printf("%d\t",i);
    //         }

    // Print the AP - 100,97,94.. upto all terms which are positive
        // int n ;
    // printf("Enter the terms you want in your AP = ");
    // scanf("%d",&n);
    // printf("now this  is your AP up to the %d = ",n);
    // for(int i=100;i>=0;i=i-3){
    //        printf("%d\t",i);  
    //        }
    
    //  Print the GP - 100,50,25.. upto ‘n’ terms

        // int n ;
    // printf("Enter the terms you want in your AP = ");
    // scanf("%d",&n);
    // printf("now this  is your GP = ");
    // for(int i=100;i>0;i=i/2){
    //        printf("%d\t",i);
    // }
    //PRINT prime numbers 
    // int n ,a;
    // printf("Enter any number to check for prime");
    // scanf("%d",&n);

    // a = 0;
    // if(n==1){
    //     printf("number is niether prime nor compodite");
    // }else{
    // for(int i = 2;i<n-1;i++){
    //     if(n%i==0){
    //         a = 1;

    //     }break;

    // }
    // if(a==0){
    // printf("This number is prime");
    // }
    // else {
    //     printf("This is not a prime number");
    // }}
    
    // int i;
    // while(i<10)
    // {
    //     printf("\n%d",i);
    //     i++;
    // }
    // int x = 4,y,z;
    // y =--x;//predecriment
    // z=x--;// post decriment
    // printf("%d%d%d",x,y,z);


// int a = 10, sum = 0;
// if(a ==0){
//     sum = 1;

// }else{
// while(a>0){
//     sum = sum +  1;
//     a = a/10;
// }}
// printf("Number digits are %d",sum);


// int a = 123456, sum = 0 ,b;
// while(a>0){
//     b = a%10;
//     if(b%2==0){
//         sum = sum + b;
//         }
//     a = a/10;
// }
// printf("Sum of digits are %d",sum);
// int a,b = 0 ,c;
// printf("Enter a number to reverse = ");
// scanf("%d",&a);
// while(a>0){
//     c = a%10;
//     b = b*10 + c;
//     a = a/10;
// }
// printf("your reverse number is = %d",b);

// int a,c , b = 1;
// printf("Enter a number to get its factoril = ");
// scanf("%d",&c);
// a = c;
// while(a>1){
//     b = b*a;
//     a = a - 1;

// }
// printf("Factorial of %d is %d",c,b);

// int a, b, c ,n;
// printf("Enter the numbers you want in your fabonnachi series");
// scanf("%d",&n);
// a = 0;
// b = 1;
// printf("%d  %d",a , b);

// for(int i = 1 ;i<=n;i++){
//     c = a + b;
//     a = b;
//     b = c;
//     printf("\t%d",c);
// }
// int a ,b, result;
// printf("Enter two number = ");
// scanf("%d",&a);
// scanf("\n%d",&b);
// result = pow(a,b);
// printf("%d",result);
int n ;
printf("Enter a number = ");
scanf("%d",&n);
for(int i = 1;i<=n;i++){
    for(int j=1;j<=i;j++){
        for(int k=1;k>=n-i;k--)
        {
            printf(" ");
        }
        printf("*");
    }
    printf("\n");
}












































    
    return 0;

}