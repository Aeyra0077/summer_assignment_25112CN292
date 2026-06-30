#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("\nInventory is full!\n");
        return;
    }
    struct Item newItem;
    printf("\nEnter Item ID: ");
    scanf("%d", &newItem.id);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == newItem.id) {
            printf("Error: Item ID already exists!\n");
            return;
        }
    }
    printf("Enter Item Name: ");
    scanf("%s", newItem.name);
    printf("Enter Quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    inventory[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully!\n");
}

void displayInventory() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    printf("\n=== Current Inventory ===\n");
    printf("%-10s %-25s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    for (int i = 0; i < itemCount; i++) {
        printf("%-10d %-25s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void searchItem() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int searchId;
    printf("\nEnter Item ID to search: ");
    scanf("%d", &searchId);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found:\n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: $%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

void updateQuantity() {
    if (itemCount == 0) {
        printf("\nInventory is empty!\n");
        return;
    }
    int searchId, newQty;
    printf("\nEnter Item ID to update quantity: ");
    scanf("%d", &searchId);
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("Current Quantity: %d\n", inventory[i].quantity);
            printf("Enter New Quantity: ");
            scanf("%d", &newQty);
            inventory[i].quantity = newQty;
            printf("Quantity updated successfully!\n");
            return;
        }
    }
    printf("Item with ID %d not found.\n", searchId);
}

int main() {
    int choice;
    do {
        printf("\n*** Inventory Management System ***\n");
        printf("1. Add New Item\n");
        printf("2. Display All Items\n");
        printf("3. Search Item by ID\n");
        printf("4. Update Item Quantity\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateQuantity();
                break;
            case 5:
                printf("\nExiting system. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose between 1 and 5.\n");
        }
    } while (choice != 5);
    return 0;
}
