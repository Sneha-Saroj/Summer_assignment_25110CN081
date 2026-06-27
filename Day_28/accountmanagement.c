#include <stdio.h>

struct Account
{
    int accNo;
    char name[50];
    float balance;
};

int main()
{
    struct Account acc[100];
    int n = 0, choice, i, accNo, found;

    while (1)
    {
        printf("\n===== ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. View Accounts\n");
        printf("3. Search Account\n");
        printf("4. Update Account\n");
        printf("5. Delete Account\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Account Number: ");
            scanf("%d", &acc[n].accNo);

            printf("Enter Account Holder Name: ");
            scanf(" %[^\n]", acc[n].name);

            printf("Enter Initial Balance: ");
            scanf("%f", &acc[n].balance);

            n++;
            printf("Account Created Successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("No accounts found.\n");
            }
            else
            {
                printf("\n===== ACCOUNT LIST =====\n");
                for (i = 0; i < n; i++)
                {
                    printf("\nAccount No : %d", acc[i].accNo);
                    printf("\nName       : %s", acc[i].name);
                    printf("\nBalance    : %.2f\n", acc[i].balance);
                }
            }
            break;

        case 3:
            printf("Enter Account Number to Search: ");
            scanf("%d", &accNo);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (acc[i].accNo == accNo)
                {
                    printf("\nAccount Found!\n");
                    printf("Account No : %d\n", acc[i].accNo);
                    printf("Name       : %s\n", acc[i].name);
                    printf("Balance    : %.2f\n", acc[i].balance);

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Account not found.\n");
            break;

        case 4:
            printf("Enter Account Number to Update: ");
            scanf("%d", &accNo);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (acc[i].accNo == accNo)
                {
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", acc[i].name);

                    printf("Enter New Balance: ");
                    scanf("%f", &acc[i].balance);

                    printf("Account Updated Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Account not found.\n");
            break;

        case 5:
            printf("Enter Account Number to Delete: ");
            scanf("%d", &accNo);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (acc[i].accNo == accNo)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        acc[j] = acc[j + 1];
                    }
                    n--;

                    printf("Account Deleted Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Account not found.\n");
            break;

        case 6:
            printf("Exiting System...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}