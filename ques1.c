#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int size, target, result;

    printf("Enter number of elements: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        return 1;
    }

    int arr[size];
    printf("Enter %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1;
        }
    }

    printf("Enter value to search: ");
    if (scanf("%d", &target) != 1) {
        return 1;
    }

    result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
