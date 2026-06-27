#include <stdio.h>

int main()
{
    int choice;
    float balance = 1000.0;   // initial balance
    float amount;

    while(1)
    {
        printf("\n===== ATM MENU =====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Your current balance is: %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if(amount > 0)
                {
                    balance += amount;
                    printf("Money deposited successfully!\n");
                }
                else
                {
                    printf("Invalid amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if(amount > 0 && amount <= balance)
                {
                    balance -= amount;
                    printf("Please collect your cash.\n");
                }
                else
                {
                    printf("Insufficient balance or invalid amount!\n");
                }
                break;

            case 4:
                printf("Thank you for using ATM!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
