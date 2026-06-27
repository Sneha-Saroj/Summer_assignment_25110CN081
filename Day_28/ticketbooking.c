#include <stdio.h>
#include <string.h>

struct Ticket
{
    int ticketNo;
    char name[50];
    char source[30];
    char destination[30];
    int status;   // 1 = Booked, 0 = Cancelled
};

int main()
{
    struct Ticket t[100];
    int n = 0, choice, i, ticketNo, found;

    while (1)
    {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. Book Ticket\n");
        printf("2. View Tickets\n");
        printf("3. Cancel Ticket\n");
        printf("4. Search Ticket\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Ticket Number: ");
            scanf("%d", &t[n].ticketNo);

            printf("Enter Passenger Name: ");
            scanf(" %[^\n]", t[n].name);

            printf("Enter Source: ");
            scanf(" %[^\n]", t[n].source);

            printf("Enter Destination: ");
            scanf(" %[^\n]", t[n].destination);

            t[n].status = 1;

            n++;
            printf("Ticket Booked Successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("No tickets booked yet.\n");
            }
            else
            {
                printf("\n===== BOOKED TICKETS =====\n");
                for (i = 0; i < n; i++)
                {
                    printf("\nTicket No   : %d", t[i].ticketNo);
                    printf("\nName        : %s", t[i].name);
                    printf("\nSource      : %s", t[i].source);
                    printf("\nDestination : %s", t[i].destination);

                    if (t[i].status == 1)
                        printf("\nStatus      : BOOKED\n");
                    else
                        printf("\nStatus      : CANCELLED\n");

                    printf("--------------------------\n");
                }
            }
            break;

        case 3:
            printf("Enter Ticket Number to Cancel: ");
            scanf("%d", &ticketNo);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (t[i].ticketNo == ticketNo)
                {
                    if (t[i].status == 1)
                    {
                        t[i].status = 0;
                        printf("Ticket Cancelled Successfully!\n");
                    }
                    else
                    {
                        printf("Ticket is already cancelled.\n");
                    }

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Ticket not found.\n");

            break;

        case 4:
            printf("Enter Ticket Number to Search: ");
            scanf("%d", &ticketNo);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (t[i].ticketNo == ticketNo)
                {
                    printf("\nTicket Found!\n");
                    printf("Ticket No   : %d\n", t[i].ticketNo);
                    printf("Name        : %s\n", t[i].name);
                    printf("Source      : %s\n", t[i].source);
                    printf("Destination : %s\n", t[i].destination);

                    if (t[i].status == 1)
                        printf("Status      : BOOKED\n");
                    else
                        printf("Status      : CANCELLED\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Ticket not found.\n");

            break;

        case 5:
            printf("Exiting Ticket Booking System...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}