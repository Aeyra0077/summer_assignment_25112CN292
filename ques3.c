#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100

struct Employee {
    int id;
    char name[50];
    char designation[50];
    float salary;
};

struct Employee employees[MAX_EMPLOYEES];
int employee_count = 0;

void addEmployee() {
    if (employee_count >= MAX_EMPLOYEES) {
        printf("\nSystem full. Cannot add more employees.\n");
        return;
    }

    struct Employee emp;
    printf("\nEnter Employee ID: ");
    scanf("%d", &emp.id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == emp.id) {
            printf("Error: Employee ID already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    getchar();
    fgets(emp.name, sizeof(emp.name), stdin);
    emp.name[strcspn(emp.name, "\n")] = 0;

    printf("Enter Designation: ");
    fgets(emp.designation, sizeof(emp.designation), stdin);
    emp.designation[strcspn(emp.designation, "\n")] = 0;

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    employees[employee_count] = emp;
    employee_count++;
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    if (employee_count == 0) {
        printf("\nNo employee records found.\n");
        return;
    }

    printf("\n%-10s %-20s %-20s %-10s\n", "ID", "Name", "Designation", "Salary");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < employee_count; i++) {
        printf("%-10d %-20s %-20s %-10.2f\n", employees[i].id, employees[i].name, employees[i].designation, employees[i].salary);
    }
}

void searchEmployee() {
    if (employee_count == 0) {
        printf("\nNo records available to search.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("\nEmployee Found:\n");
            printf("ID: %d\n", employees[i].id);
            printf("Name: %s\n", employees[i].name);
            printf("Designation: %s\n", employees[i].designation);
            printf("Salary: %.2f\n", employees[i].salary);
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void updateEmployee() {
    if (employee_count == 0) {
        printf("\nNo records available to update.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            printf("\nCurrent Details:\nName: %s, Designation: %s, Salary: %.2f\n", employees[i].name, employees[i].designation, employees[i].salary);
            
            printf("\nEnter New Name: ");
            getchar();
            fgets(employees[i].name, sizeof(employees[i].name), stdin);
            employees[i].name[strcspn(employees[i].name, "\n")] = 0;

            printf("Enter New Designation: ");
            fgets(employees[i].designation, sizeof(employees[i].designation), stdin);
            employees[i].designation[strcspn(employees[i].designation, "\n")] = 0;

            printf("Enter New Salary: ");
            scanf("%f", &employees[i].salary);

            printf("Employee details updated successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

void deleteEmployee() {
    if (employee_count == 0) {
        printf("\nNo records available to delete.\n");
        return;
    }

    int id;
    printf("\nEnter Employee ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < employee_count; i++) {
        if (employees[i].id == id) {
            for (int j = i; j < employee_count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            employee_count--;
            printf("Employee record deleted successfully!\n");
            return;
        }
    }
    printf("Employee with ID %d not found.\n", id);
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Employee Management System ===\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateEmployee();
                break;
            case 5:
                deleteEmployee();
                break;
            case 6:
                printf("\nExiting program.\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}
