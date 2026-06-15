#include <stdio.h>
int main()
{
int n,i,flag=1;

printf("enter the number ");
scanf("%d", &n);

if(n<=1)
flag=0;

for(i=2;i<=n/2;i++)
{
if(n%i==0){
 flag=0;
 break;   
}    
}
if(flag)
printf("prime number");
else
printf("not prime ");
return 0;
}