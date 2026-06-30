#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[100];
    int is_issued;
};

void addBook(struct Book library[], int *count) {
    if (*count >= 100) {
        printf("\nLibrary is full!\n");
        return;
    }
    printf("\nEnter Book ID: ");
    scanf("%d", &library[*count].id);
    getchar();
    printf("Enter Book Title: ");
    fgets(library[*count].title, sizeof(library[*count].title), stdin);
    library[*count].title[strcspn(library[*count].title, "\n")] = 0;
    printf("Enter Author Name: ");
    fgets(library[*count].author, sizeof(library[*count].author), stdin);
    library[*count].author[strcspn(library[*count].author, "\n")] = 0;
    library[*count].is_issued = 0;
    (*count)++;
    printf("Book added successfully!\n");
}

void displayBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("\nNo books in the library.\n");
        return;
    }
    printf("\nID\t%-30s\t%-30s\tStatus\n", "Title", "Author");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-30s\t%-30s\t%s\n", 
               library[i].id, 
               library[i].title, 
               library[i].author, 
               library[i].is_issued ? "Issued" : "Available");
    }
}

void searchBook(struct Book library[], int count) {
    if (count == 0) {
        printf("\nNo books to search.\n");
        return;
    }
    char searchTitle[100];
    int found = 0;
    getchar();
    printf("\nEnter Book Title to Search: ");
    fgets(searchTitle, sizeof(searchTitle), stdin);
    searchTitle[strcspn(searchTitle, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcasecmp(library[i].title, searchTitle) == 0) {
            printf("\nBook Found:\nID: %d\nTitle: %s\nAuthor: %s\nStatus: %s\n",
                   library[i].id, library[i].title, library[i].author,
                   library[i].is_issued ? "Issued" : "Available");
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nBook not found.\n");
    }
}

void issueBook(struct Book library[], int count) {
    int id, found = 0;
    printf("\nEnter Book ID to Issue: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued == 1) {
                printf("Book is already issued.\n");
            } else {
                library[i].is_issued = 1;
                printf("Book issued successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book ID not found.\n");
    }
}

void returnBook(struct Book library[], int count) {
    int id, found = 0;
    printf("\nEnter Book ID to Return: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (library[i].id == id) {
            found = 1;
            if (library[i].is_issued == 0) {
                printf("Book was not issued.\n");
            } else {
                library[i].is_issued = 0;
                printf("Book returned successfully!\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Book ID not found.\n");
    }
}

int main() {
    struct Book library[100];
    int count = 0;
    int choice;

    while (1) {
        printf("\n=== Mini Library System ===\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book by Title\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &count);
                break;
            case 2:
                displayBooks(library, count);
                break;
            case 3:
                searchBook(library, count);
                break;
            case 4:
                issueBook(library, count);
                break;
            case 5:
                returnBook(library, count);
                break;
            case 6:
                printf("\nExiting system.\n");
                exit(0);
            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }
    return 0;
}
