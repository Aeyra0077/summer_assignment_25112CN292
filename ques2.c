#include <stdio.h>

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int main() {
    int m;
    printf("Enter the number of elements: ");
    scanf("%d", &m);
    int arr[m];
    printf("Enter the elements:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
