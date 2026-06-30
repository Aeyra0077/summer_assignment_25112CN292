#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int id;
    char name[50];
    float gpa;
};

void addStudent(struct Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nSystem full!\n");
        return;
    }
    printf("\nEnter ID: ");
    scanf("%d", &arr[*count].id);
    getchar();
    printf("Enter Name: ");
    fgets(arr[*count].name, sizeof(arr[*count].name), stdin);
    arr[*count].name[strcspn(arr[*count].name, "\n")] = '\0';
    printf("Enter GPA: ");
    scanf("%f", &arr[*count].gpa);
    (*count)++;
    printf("Record added.\n");
}

void displayStudents(struct Student arr[], int count) {
    if (count == 0) {
        printf("\nNo records found.\n");
        return;
    }
    printf("\nID\tName\t\tGPA\n");
    printf("-----------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-15s\t%.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
    }
}

void searchStudent(struct Student arr[], int count) {
    if (count == 0) {
        printf("\nNo records to search.\n");
        return;
    }
    int searchId;
    int found = 0;
    printf("\nEnter ID to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < count; i++) {
        if (arr[i].id == searchId) {
            printf("\nFound: ID: %d, Name: %s, GPA: %.2f\n", arr[i].id, arr[i].name, arr[i].gpa);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Record not found.\n");
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n--- Student Record System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
