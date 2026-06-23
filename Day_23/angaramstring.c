#include <stdio.h>

int main()
{
    char str1[100], str2[100];
    int freq[256] = {0};
    int i;

    printf("Enter first string: ");
    fgets(str1, sizeof(str1), stdin);

    printf("Enter second string: ");
    fgets(str2, sizeof(str2), stdin);

    // remove newline from str1
    for(i = 0; str1[i] != '\0'; i++)
        if(str1[i] == '\n') str1[i] = '\0';

    // remove newline from str2
    for(i = 0; str2[i] != '\0'; i++)
        if(str2[i] == '\n') str2[i] = '\0';

    // count frequency of first string
    for(i = 0; str1[i] != '\0'; i++)
        freq[(int)str1[i]]++;

    // subtract frequency using second string
    for(i = 0; str2[i] != '\0'; i++)
        freq[(int)str2[i]]--;

    // check if all frequencies are zero
    for(i = 0; i < 256; i++)
    {
        if(freq[i] != 0)
        {
            printf("Not Anagram\n");
            return 0;
        }
    }

    printf("Anagram\n");

    return 0;
}