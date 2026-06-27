#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    char course[30];
};

struct Employee
{
    int id;
    char name[50];
    char dept[30];
};

struct Book
{
    int id;
    char title[50];
    char author[50];
};

int main()
{
    struct Student s[50];
    struct Employee e[50];
    struct Book b[50];

    int sch = 0, emp = 0, bk = 0;
    int choice, i, id, found;

    while (1)
    {
        printf("\n========== MINI PROJECT SYSTEM ==========\n");
        printf("1. Add Student\n");
        printf("2. Add Employee\n");
        printf("3. Add Book\n");
        printf("4. Display All Records\n");
        printf("5. Search Student\n");
        printf("6. Search Employee\n");
        printf("7. Search Book\n");
        printf("8. Delete Student\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Roll No: ");
            scanf("%d", &s[sch].roll);

            printf("Enter Name: ");
            scanf(" %[^\n]", s[sch].name);

            printf("Enter Course: ");
            scanf(" %[^\n]", s[sch].course);

            sch++;
            printf("Student Added!\n");
            break;

        case 2:
            printf("\nEnter Employee ID: ");
            scanf("%d", &e[emp].id);

            printf("Enter Name: ");
            scanf(" %[^\n]", e[emp].name);

            printf("Enter Department: ");
            scanf(" %[^\n]", e[emp].dept);

            emp++;
            printf("Employee Added!\n");
            break;

        case 3:
            printf("\nEnter Book ID: ");
            scanf("%d", &b[bk].id);

            printf("Enter Title: ");
            scanf(" %[^\n]", b[bk].title);

            printf("Enter Author: ");
            scanf(" %[^\n]", b[bk].author);

            bk++;
            printf("Book Added!\n");
            break;

        case 4:
            printf("\n===== STUDENTS =====\n");
            for (i = 0; i < sch; i++)
                printf("%d %s %s\n", s[i].roll, s[i].name, s[i].course);

            printf("\n===== EMPLOYEES =====\n");
            for (i = 0; i < emp; i++)
                printf("%d %s %s\n", e[i].id, e[i].name, e[i].dept);

            printf("\n===== BOOKS =====\n");
            for (i = 0; i < bk; i++)
                printf("%d %s %s\n", b[i].id, b[i].title, b[i].author);

            break;

        case 5:
            printf("Enter Roll No to search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < sch; i++)
            {
                if (s[i].roll == id)
                {
                    printf("Found: %s (%s)\n", s[i].name, s[i].course);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Student not found!\n");
            break;

        case 6:
            printf("Enter Employee ID to search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < emp; i++)
            {
                if (e[i].id == id)
                {
                    printf("Found: %s (%s)\n", e[i].name, e[i].dept);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Employee not found!\n");
            break;

        case 7:
            printf("Enter Book ID to search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < bk; i++)
            {
                if (b[i].id == id)
                {
                    printf("Found: %s by %s\n", b[i].title, b[i].author);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Book not found!\n");
            break;

        case 8:
            printf("Enter Roll No to delete student: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < sch; i++)
            {
                if (s[i].roll == id)
                {
                    for (int j = i; j < sch - 1; j++)
                        s[j] = s[j + 1];

                    sch--;
                    printf("Student deleted!\n");
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Student not found!\n");
            break;

        case 9:
            printf("Exiting Project...\n");
            return 0;

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}