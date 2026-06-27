#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float basic, hra, da, pf, netSalary;
};

int main()
{
    struct Employee emp[100];
    int n = 0, choice, id, i, found;

    while (1)
    {
        printf("\n===== Salary Management System =====\n");
        printf("1. Add Employee Salary\n");
        printf("2. Display Salary Records\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Employee ID: ");
            scanf("%d", &emp[n].id);

            printf("Enter Employee Name: ");
            scanf(" %[^\n]", emp[n].name);

            printf("Enter Basic Salary: ");
            scanf("%f", &emp[n].basic);

            printf("Enter HRA: ");
            scanf("%f", &emp[n].hra);

            printf("Enter DA: ");
            scanf("%f", &emp[n].da);

            printf("Enter PF: ");
            scanf("%f", &emp[n].pf);

            emp[n].netSalary = emp[n].basic + emp[n].hra + emp[n].da - emp[n].pf;

            n++;
            printf("Salary Record Added Successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("No salary records available.\n");
            }
            else
            {
                printf("\n===== Salary Records =====\n");
                for (i = 0; i < n; i++)
                {
                    printf("\nEmployee ID   : %d", emp[i].id);
                    printf("\nName          : %s", emp[i].name);
                    printf("\nBasic Salary  : %.2f", emp[i].basic);
                    printf("\nHRA           : %.2f", emp[i].hra);
                    printf("\nDA            : %.2f", emp[i].da);
                    printf("\nPF            : %.2f", emp[i].pf);
                    printf("\nNet Salary    : %.2f\n", emp[i].netSalary);
                }
            }
            break;

        case 3:
            printf("Enter Employee ID to Search: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (emp[i].id == id)
                {
                    printf("\nEmployee Found!\n");
                    printf("ID            : %d\n", emp[i].id);
                    printf("Name          : %s\n", emp[i].name);
                    printf("Net Salary    : %.2f\n", emp[i].netSalary);
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 4:
            printf("Enter Employee ID to Update Salary: ");
            scanf("%d", &id);

            found = 0;
            for (i = 0; i < n; i++)
            {
                if (emp[i].id == id)
                {
                    printf("Enter New Basic Salary: ");
                    scanf("%f", &emp[i].basic);

                    printf("Enter New HRA: ");
                    scanf("%f", &emp[i].hra);

                    printf("Enter New DA: ");
                    scanf("%f", &emp[i].da);

                    printf("Enter New PF: ");
                    scanf("%f", &emp[i].pf);

                    emp[i].netSalary = emp[i].basic + emp[i].hra + emp[i].da - emp[i].pf;

                    printf("Salary Updated Successfully!\n");
                    found = 1;
                    break;
                }
            }

            if (!found)
                printf("Employee not found.\n");
            break;

        case 5:
            printf("Thank you! Exiting...\n");
            return 0;

        default:
            printf("Invalid Choice! Please try again.\n");
        }
    }

    return 0;
}