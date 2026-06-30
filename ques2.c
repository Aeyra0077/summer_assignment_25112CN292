#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void display(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int deleteElement(int arr[], int n, int key) {
    int pos = search(arr, n, key);
    if (pos == -1) {
        return n;
    }
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int insertElement(int arr[], int n, int value) {
    if (n >= MAX_SIZE) {
        printf("Array is full. Cannot insert more elements.\n");
        return n;
    }
    arr[n] = value;
    return n + 1;
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;
    int choice;
    int value;
    int result;

    do {
        printf("\nMenu:\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Search element\n");
        printf("4. Display array\n");
        printf("5. Sort array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input.\n");
                    break;
                }
                n = insertElement(arr, n, value);
                break;
            case 2:
                if (n == 0) {
                    printf("Array is empty. Nothing to delete.\n");
                } else {
                    printf("Enter value to delete: ");
                    if (scanf("%d", &value) != 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    int newSize = deleteElement(arr, n, value);
                    if (newSize == n) {
                        printf("Element %d not found.\n", value);
                    } else {
                        n = newSize;
                        printf("Element %d deleted.\n", value);
                    }
                }
                break;
            case 3:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Enter value to search: ");
                    if (scanf("%d", &value) != 1) {
                        printf("Invalid input.\n");
                        break;
                    }
                    result = search(arr, n, value);
                    if (result == -1) {
                        printf("Element %d not found.\n", value);
                    } else {
                        printf("Element %d found at index %d.\n", value, result);
                    }
                }
                break;
            case 4:
                display(arr, n);
                break;
            case 5:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    sortArray(arr, n);
                    printf("Array sorted.\n");
                }
                break;
            case 6:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
