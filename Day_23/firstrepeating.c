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

    // count frequency
    for(i = 0; str[i] != '\0'; i++)
    {
        freq[(int)str[i]]++;
    }

    // find first repeating character
    for(i = 0; str[i] != '\0'; i++)
    {
        if(freq[(int)str[i]] > 1)
        {
            printf("First repeating character = %c\n", str[i]);
            return 0;
        }
    }

    printf("No repeating character found\n");

    return 0;
}