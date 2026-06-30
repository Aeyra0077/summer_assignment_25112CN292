#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[50];
};

void addContact() {
    FILE *fp = fopen("contacts.dat", "ab");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct Contact c;
    printf("Enter Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Phone: ");
    scanf(" %[^\n]", c.phone);
    printf("Enter Email: ");
    scanf(" %[^\n]", c.email);
    fwrite(&c, sizeof(struct Contact), 1, fp);
    fclose(fp);
    printf("Contact added successfully!\n");
}

void listContacts() {
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }
    struct Contact c;
    printf("\n--- Contact List ---\n");
    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        printf("Name : %s\n", c.name);
        printf("Phone: %s\n", c.phone);
        printf("Email: %s\n", c.email);
        printf("--------------------\n");
    }
    fclose(fp);
}

void searchContact() {
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }
    char searchName[50];
    struct Contact c;
    int found = 0;
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcasecmp(c.name, searchName) == 0) {
            printf("\nContact Found:\n");
            printf("Name : %s\n", c.name);
            printf("Phone: %s\n", c.phone);
            printf("Email: %s\n", c.email);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
    fclose(fp);
}

void deleteContact() {
    FILE *fp = fopen("contacts.dat", "rb");
    if (fp == NULL) {
        printf("No contacts found.\n");
        return;
    }
    FILE *temp = fopen("temp.dat", "wb");
    if (temp == NULL) {
        printf("Error opening temporary file!\n");
        fclose(fp);
        return;
    }
    char deleteName[50];
    struct Contact c;
    int found = 0;
    printf("Enter name to delete: ");
    scanf(" %[^\n]", deleteName);
    while (fread(&c, sizeof(struct Contact), 1, fp)) {
        if (strcasecmp(c.name, deleteName) == 0) {
            found = 1;
        } else {
            fwrite(&c, sizeof(struct Contact), 1, temp);
        }
    }
    fclose(fp);
    fclose(temp);
    if (found) {
        remove("contacts.dat");
        rename("temp.dat", "contacts.dat");
        printf("Contact deleted successfully!\n");
    } else {
        remove("temp.dat");
        printf("Contact not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n*** Contact Management System ***\n");
        printf("1. Add Contact\n");
        printf("2. List All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Delete Contact\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                listContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
