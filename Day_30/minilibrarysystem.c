#include <stdio.h>

struct Book
{
    int id;
    char title[50];
    char author[50];
    int issued;   // 0 = available, 1 = issued
};

int main()
{
    struct Book b[100];
    int n = 0, choice, i, id, found;

    while (1)
    {
        printf("\n===== MINI LIBRARY SYSTEM =====\n");
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
            scanf("%d", &b[n].id);

            printf("Enter Book Title: ");
            scanf(" %[^\n]", b[n].title);

            printf("Enter Author Name: ");
            scanf(" %[^\n]", b[n].author);

            b[n].issued = 0;

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
                printf("\n===== BOOK LIST =====\n");
                for (i = 0; i < n; i++)
                {
                    printf("\nID     : %d", b[i].id);
                    printf("\nTitle  : %s", b[i].title);
                    printf("\nAuthor : %s", b[i].author);

                    if (b[i].issued == 0)
                        printf("\nStatus : Available\n");
                    else
                        printf("\nStatus : Issued\n");
                }
            }
            break;

        case 3:
            printf("Enter Book ID to Search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (b[i].id == id)
                {
                    printf("\nBook Found!\n");
                    printf("ID     : %d\n", b[i].id);
                    printf("Title  : %s\n", b[i].title);
                    printf("Author : %s\n", b[i].author);

                    if (b[i].issued == 0)
                        printf("Status : Available\n");
                    else
                        printf("Status : Issued\n");

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
                if (b[i].id == id)
                {
                    if (b[i].issued == 0)
                    {
                        b[i].issued = 1;
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
                if (b[i].id == id)
                {
                    if (b[i].issued == 1)
                    {
                        b[i].issued = 0;
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
            printf("Exiting Library System...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}