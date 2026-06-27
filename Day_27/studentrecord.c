#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    float marks;
};

void addStudent() {
    struct Student s;
    FILE *fp;

    fp = fopen("students.dat", "ab");

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("Student added successfully!\n");
}

void displayStudents() {
    struct Student s;
    FILE *fp;

    fp = fopen("students.dat", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");

    while (fread(&s, sizeof(s), 1, fp)) {
        printf("Roll No: %d\n", s.roll);
        printf("Name   : %s\n", s.name);
        printf("Marks  : %.2f\n", s.marks);
        printf("----------------------\n");
    }

    fclose(fp);
}

void searchStudent() {
    struct Student s;
    FILE *fp;
    int roll, found = 0;

    fp = fopen("students.dat", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("Record Found:\n");
            printf("Roll No: %d\n", s.roll);
            printf("Name   : %s\n", s.name);
            printf("Marks  : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }

    fclose(fp);
}

void deleteStudent() {
    struct Student s;
    FILE *fp, *temp;
    int roll, found = 0;

    fp = fopen("students.dat", "rb");
    temp = fopen("temp.dat", "wb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll != roll) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}