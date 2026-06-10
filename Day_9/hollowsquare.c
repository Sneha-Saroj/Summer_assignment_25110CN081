#include <stdio.h>

// function to find maximum
int findMax(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    int x, y, max;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    max = findMax(x, y);

    printf("Maximum number is: %d\n", max);

    return 0;
}