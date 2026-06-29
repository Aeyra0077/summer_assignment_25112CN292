#include <stdio.h>

int main() {
    int arr1[100], arr2[100], merged[200];
    int size1, size2, total_size;
    int i;

    printf("Enter number of elements in first array: ");
    scanf("%d", &size1);

    printf("Enter %d elements: ", size1);
    for (i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter number of elements in second array: ");
    scanf("%d", &size2);

    printf("Enter %d elements: ", size2);
    for (i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    total_size = size1 + size2;

    for (i = 0; i < size1; i++) {
        merged[i] = arr1[i];
    }

    for (i = 0; i < size2; i++) {
        merged[size1 + i] = arr2[i];
    }

    printf("Merged array elements: ");
    for (i = 0; i < total_size; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
