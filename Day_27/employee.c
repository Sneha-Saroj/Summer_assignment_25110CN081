#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float salary;
};

int main()
{
    struct Employee emp[100];
    int n = 0, choice, id, i, found;

    while (1)
    {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Employee ID: ");
            scanf("%d", &emp[n].id);

            printf("Enter Employee Name: ");
            scanf(" %[^\n]", emp[n].name);

            printf("Enter Employee Salary: ");
            scanf("%f", &emp[n].salary);

            n++;
            printf("Employee Added Successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("No employee records found.\n");
            }
            else
            {
                printf("\nEmployee Records:\n");
                printf("----------------------------------------\n");
                for (i = 0; i < n; i++)
                {
                    printf("ID     : %d\n", emp[i].id);
                    printf("Name   : %s\n", emp[i].name);
                    printf("Salary : %.2f\n", emp[i].salary);
                    printf("----------------------------------------\n");
                }
            }
            break;

        case 3:
            printf("Enter Employee ID to search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (emp[i].id == id)
                {
                    printf("\nEmployee Found!\n");
                    printf("ID     : %d\n", emp[i].id);
                    printf("Name   : %s\n", emp[i].name);
                    printf("Salary : %.2f\n", emp[i].salary);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 4:
            printf("Enter Employee ID to update: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (emp[i].id == id)
                {
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", emp[i].name);

                    printf("Enter New Salary: ");
                    scanf("%f", &emp[i].salary);

                    printf("Employee Updated Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 5:
            printf("Enter Employee ID to delete: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (emp[i].id == id)
                {
                    int j;
                    for (j = i; j < n - 1; j++)
                    {
                        emp[j] = emp[j + 1];
                    }
                    n--;
                    printf("Employee Deleted Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 6:
            printf("Exiting Program...\n");
            return 0;

        default:
            printf("Invalid Choice! Please try again.\n");
        }
    }

    return 0;
}