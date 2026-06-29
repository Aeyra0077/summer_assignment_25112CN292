#include <stdio.h>

void findPair(int arr[], int size, int target) {
    int found = 0;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: %d and %d\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("No pair found with the given sum\n");
    }
}

int main() {
    int n, target;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &target);
    int size = sizeof(arr) / sizeof(arr[0]);
    findPair(arr, size, target);
    return 0;
}
