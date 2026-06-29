#include <stdio.h>

void mergeArrays(int arr1[], int n1, int arr2[], int n2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    int m;
    printf("Enter the size of the first sorted array: ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        return 1;
    }
    int arr1[m];
    printf("Enter %d elements for the first sorted array: ", m);
    for (int i = 0; i < m; i++) {
        if (scanf("%d", &arr1[i]) != 1) {
            return 1;
        }
    }
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int n;
    printf("Enter the size of the second sorted array: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }
    int arr2[n];
    printf("Enter %d elements for the second sorted array: ", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr2[i]) != 1) {
            return 1;
        }
    }
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int merged[n1 + n2];

    mergeArrays(arr1, n1, arr2, n2, merged);

    printf("Merged sorted array: ");
    for (int i = 0; i < n1 + n2; i++) {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
