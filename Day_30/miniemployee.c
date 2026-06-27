#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    char department[30];
    float salary;
};

int main()
{
    struct Employee e[100];
    int n = 0, choice, i, id, found;

    while (1)
    {
        printf("\n===== MINI EMPLOYEE MANAGEMENT SYSTEM =====\n");
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
            scanf("%d", &e[n].id);

            printf("Enter Name: ");
            scanf(" %[^\n]", e[n].name);

            printf("Enter Department: ");
            scanf(" %[^\n]", e[n].department);

            printf("Enter Salary: ");
            scanf("%f", &e[n].salary);

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
                printf("\n===== EMPLOYEE LIST =====\n");
                for (i = 0; i < n; i++)
                {
                    printf("\nID         : %d", e[i].id);
                    printf("\nName       : %s", e[i].name);
                    printf("\nDepartment : %s", e[i].department);
                    printf("\nSalary     : %.2f\n", e[i].salary);
                }
            }
            break;

        case 3:
            printf("Enter Employee ID to Search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (e[i].id == id)
                {
                    printf("\nEmployee Found!\n");
                    printf("ID         : %d\n", e[i].id);
                    printf("Name       : %s\n", e[i].name);
                    printf("Department : %s\n", e[i].department);
                    printf("Salary     : %.2f\n", e[i].salary);

                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 4:
            printf("Enter Employee ID to Update: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (e[i].id == id)
                {
                    printf("Enter New Name: ");
                    scanf(" %[^\n]", e[i].name);

                    printf("Enter New Department: ");
                    scanf(" %[^\n]", e[i].department);

                    printf("Enter New Salary: ");
                    scanf("%f", &e[i].salary);

                    printf("Employee Updated Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 5:
            printf("Enter Employee ID to Delete: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (e[i].id == id)
                {
                    for (int j = i; j < n - 1; j++)
                    {
                        e[j] = e[j + 1];
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
            printf("Exiting System...\n");
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}