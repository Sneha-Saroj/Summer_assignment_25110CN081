#include <stdio.h>
int main()
{
int num,original,reverse=0,digit;

printf("enter a number");
scanf("%d",&num);

original=num;

while(num>0)
{
 digit = num%10;
 reverse=reverse*10+digit;
 num=num/10;   
}
if(original==reverse)
printf("pallindrome number");
else
printf("not pallindrome");

return 0;
}