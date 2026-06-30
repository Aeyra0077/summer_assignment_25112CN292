#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

int ids[MAX_STUDENTS];
char names[MAX_STUDENTS][NAME_LENGTH];
float grades[MAX_STUDENTS];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("\nDatabase is full!\n");
        return;
    }
    
    printf("\nEnter Student ID: ");
    scanf("%d", &ids[student_count]);
    getchar();
    
    printf("Enter Student Name: ");
    fgets(names[student_count], NAME_LENGTH, stdin);
    names[student_count][strcspn(names[student_count], "\n")] = '\0';
    
    printf("Enter Student Grade: ");
    scanf("%f", &grades[student_count]);
    
    student_count++;
    printf("\nStudent added successfully!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("\nNo student records found.\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    printf("%-10s %-30s %-10s\n", "ID", "Name", "Grade");
    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-30s %-10.2f\n", ids[i], names[i], grades[i]);
    }
}

void search_student() {
    if (student_count == 0) {
        printf("\nNo student records found to search.\n");
        return;
    }
    
    char search_name[NAME_LENGTH];
    getchar();
    printf("\nEnter Student Name to search: ");
    fgets(search_name, NAME_LENGTH, stdin);
    search_name[strcspn(search_name, "\n")] = '\0';
    
    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (strcasecmp(names[i], search_name) == 0) {
            if (!found) {
                printf("\nStudent Found:\n");
                printf("%-10s %-30s %-10s\n", "ID", "Name", "Grade");
            }
            printf("%-10d %-30s %-10.2f\n", ids[i], names[i], grades[i]);
            found = 1;
        }
    }
    
    if (!found) {
        printf("\nStudent '%s' not found.\n", search_name);
    }
}

void calculate_average() {
    if (student_count == 0) {
        printf("\nNo data to calculate average.\n");
        return;
    }
    
    float sum = 0;
    for (int i = 0; i < student_count; i++) {
        sum += grades[i];
    }
    
    printf("\nTotal Students: %d\n", student_count);
    printf("Class Average Grade: %.2f\n", sum / student_count);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== STUDENT DATABASE MANAGEMENT SYSTEM ===\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Calculate Class Average\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Exiting program.\n");
            break;
        }
        
        if (choice == 5) {
            printf("\nExiting System. Goodbye!\n");
            break;
        }
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                calculate_average();
                break;
            default:
                printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    }
    
    return 0;
}
