#include <stdio.h>
#include <string.h>

int main()
{
    char str1[100], str2[100], temp[100];
    int choice, i, len, flag;

    printf("Enter first string: ");
    scanf(" %[^\n]", str1);

    printf("Enter second string: ");
    scanf(" %[^\n]", str2);

    while (1)
    {
        printf("\n===== STRING OPERATIONS MENU =====\n");
        printf("1. String Length\n");
        printf("2. Copy String\n");
        printf("3. Compare Strings\n");
        printf("4. Concatenate Strings\n");
        printf("5. Reverse String\n");
        printf("6. Check Palindrome\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Length of String 1 = %lu\n", strlen(str1));
            printf("Length of String 2 = %lu\n", strlen(str2));
            break;

        case 2:
            strcpy(temp, str1);
            printf("Copied String = %s\n", temp);
            break;

        case 3:
            if (strcmp(str1, str2) == 0)
                printf("Strings are equal\n");
            else
                printf("Strings are not equal\n");
            break;

        case 4:
            strcat(str1, str2);
            printf("Concatenated String = %s\n", str1);
            break;

        case 5:
            printf("Reverse of String 1: ");
            len = strlen(str1);
            for (i = len - 1; i >= 0; i--)
            {
                printf("%c", str1[i]);
            }
            printf("\n");
            break;

        case 6:
            len = strlen(str1);
            flag = 1;

            for (i = 0; i < len / 2; i++)
            {
                if (str1[i] != str1[len - i - 1])
                {
                    flag = 0;
                    break;
                }
            }

            if (flag)
                printf("String 1 is Palindrome\n");
            else
                printf("String 1 is NOT Palindrome\n");
            break;

        case 7:
            printf("Exiting Program...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}