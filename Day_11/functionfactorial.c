#include <stdio.h>

// function to find factorial
long long factorial(int n)
{
    int i;
    long long fact = 1;

    for(i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if(num < 0)
    {
        printf("Factorial is not defined for negative numbers\n");
    }
    else
    {
        printf("Factorial of %d is %lld\n", num, factorial(num));
    }

    return 0;
}