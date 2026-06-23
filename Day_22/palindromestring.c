#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int i, len, flag = 1;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    if(str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
        len--;
    }

    for(i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len - 1 - i])
        {
            flag = 0;
            break;
        }
    }

    if(flag)
        printf("String is Palindrome");
    else
        printf("String is Not Palindrome");

    return 0;
}