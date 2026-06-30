#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[50];
    char author[50];
    int is_issued;
};

struct Book library[MAX_BOOKS];
int book_count = 0;

void add_book() {
    if (book_count >= MAX_BOOKS) {
        printf("\nLibrary capacity reached!\n");
        return;
    }
    
    struct Book new_book;
    printf("\nEnter Book ID: ");
    scanf("%d", &new_book.id);
    getchar();
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == new_book.id) {
            printf("Error: A book with this ID already exists.\n");
            return;
        }
    }
    
    printf("Enter Book Title: ");
    fgets(new_book.title, sizeof(new_book.title), stdin);
    new_book.title[strcspn(new_book.title, "\n")] = 0;
    
    printf("Enter Author Name: ");
    fgets(new_book.author, sizeof(new_book.author), stdin);
    new_book.author[strcspn(new_book.author, "\n")] = 0;
    
    new_book.is_issued = 0;
    library[book_count] = new_book;
    book_count++;
    
    printf("Book added successfully!\n");
}

void display_books() {
    if (book_count == 0) {
        printf("\nNo books available in the library.\n");
        return;
    }
    
    printf("\n%-10s %-30s %-25s %-10s\n", "ID", "Title", "Author", "Status");
    printf("------------------------------------------------------------------------\n");
    for (int i = 0; i < book_count; i++) {
        printf("%-10d %-30s %-25s %-10s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

void search_book() {
    if (book_count == 0) {
        printf("\nNo books available to search.\n");
        return;
    }
    
    int search_id;
    printf("\nEnter Book ID to search: ");
    scanf("%d", &search_id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == search_id) {
            printf("\nBook Found:\n");
            printf("ID: %d\n", library[i].id);
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Status: %s\n", library[i].is_issued ? "Issued" : "Available");
            return;
        }
    }
    printf("Book with ID %d not found.\n", search_id);
}

void issue_book() {
    if (book_count == 0) {
        printf("\nNo books available to issue.\n");
        return;
    }
    
    int issue_id;
    printf("\nEnter Book ID to issue: ");
    scanf("%d", &issue_id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == issue_id) {
            if (library[i].is_issued) {
                printf("Book is already issued to someone else.\n");
            } else {
                library[i].is_issued = 1;
                printf("Book issued successfully!\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", issue_id);
}

void return_book() {
    if (book_count == 0) {
        printf("\nNo books checked out to return.\n");
        return;
    }
    
    int return_id;
    printf("\nEnter Book ID to return: ");
    scanf("%d", &return_id);
    
    for (int i = 0; i < book_count; i++) {
        if (library[i].id == return_id) {
            if (!library[i].is_issued) {
                printf("This book is already marked as available in the library.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book returned successfully!\n");
            }
            return;
        }
    }
    printf("Book with ID %d not found.\n", return_id);
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=================================");
        printf("\n    LIBRARY MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Book by ID");
        printf("\n4. Issue Book");
        printf("\n5. Return Book");
        printf("\n6. Exit");
        printf("\nEnter your choice (1-6): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                display_books();
                break;
            case 3:
                search_book();
                break;
            case 4:
                issue_book();
                break;
            case 5:
                return_book();
                break;
            case 6:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please select between 1 and 6.\n");
        }
    }
    
    return 0;
}
