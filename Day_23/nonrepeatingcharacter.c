#include <stdio.h>

int main()
{
    char str[100];
    int freq[256] = {0};
    int i;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // remove newline if present
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }

    // count frequency of each character
    for(i = 0; str[i] != '\0'; i++)
    {
        freq[(int)str[i]]++;
    }

    printf("Non-repeating characters: ");

    for(i = 0; str[i] != '\0'; i++)
    {
        if(freq[(int)str[i]] == 1)
        {
            printf("%c ", str[i]);
        }
    }

    return 0;
}