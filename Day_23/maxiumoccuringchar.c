#include <stdio.h>

int main()
{
    char str[100];
    int freq[256] = {0};
    int i;
    char maxChar;
    int max = 0;

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

    // find maximum occurring character
    for(i = 0; str[i] != '\0'; i++)
    {
        if(freq[(int)str[i]] > max)
        {
            max = freq[(int)str[i]];
            maxChar = str[i];
        }
    }

    printf("Maximum occurring character = %c\n", maxChar);
    printf("Frequency = %d\n", max);

    return 0;
}