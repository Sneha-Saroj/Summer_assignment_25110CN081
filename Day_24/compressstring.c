#include <stdio.h>

int main()
{
    char str[100];
    int i, count;

    printf("Enter a string: ");
    scanf("%s", str);

    i = 0;

    while (str[i] != '\0')
    {
        count = 1;

        while (str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        printf("%c%d", str[i], count);
        i++;
    }

    return 0;
}