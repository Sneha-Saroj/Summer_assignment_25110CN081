#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int available;   // 1 = Available, 0 = Issued
};

int main()
{
    struct Book book[100];
    int n = 0, choice, id, i, found;

    while (1)
    {
        printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Book ID: ");
            scanf("%d", &book[n].id);

            printf("Enter Book Title: ");
            scanf(" %[^\n]", book[n].title);

            printf("Enter Author Name: ");
            scanf(" %[^\n]", book[n].author);

            book[n].available = 1;

            n++;
            printf("Book Added Successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("No books available.\n");
            }
            else
            {
                printf("\n========== BOOK LIST ==========\n");
                for (i = 0; i < n; i++)
                {
                    printf("\nBook ID   : %d", book[i].id);
                    printf("\nTitle     : %s", book[i].title);
                    printf("\nAuthor    : %s", book[i].author);

                    if (book[i].available)
                        printf("\nStatus    : Available\n");
                    else
                        printf("\nStatus    : Issued\n");

                    printf("------------------------------\n");
                }
            }
            break;

        case 3:
            printf("Enter Book ID to Search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (book[i].id == id)
                {
                    printf("\nBook Found!\n");
                    printf("Book ID : %d\n", book[i].id);
                    printf("Title   : %s\n", book[i].title);
                    printf("Author  : %s\n", book[i].author);

                    if (book[i].available)
                        printf("Status  : Available\n");
                    else
                        printf("Status  : Issued\n");

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");

            break;

        case 4:
            printf("Enter Book ID to Issue: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (book[i].id == id)
                {
                    if (book[i].available)
                    {
                        book[i].available = 0;
                        printf("Book Issued Successfully!\n");
                    }
                    else
                    {
                        printf("Book is already issued.\n");
                    }
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");

            break;

        case 5:
            printf("Enter Book ID to Return: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (book[i].id == id)
                {
                    if (!book[i].available)
                    {
                        book[i].available = 1;
                        printf("Book Returned Successfully!\n");
                    }
                    else
                    {
                        printf("Book is already available.\n");
                    }
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Book not found.\n");

            break;

        case 6:
            printf("Exiting Library Management System...\n");
            return 0;

        default:
            printf("Invalid Choice! Please try again.\n");
        }
    }

    return 0;
}