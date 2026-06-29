#include <stdio.h>

int main() {
    int n1, n2;

    printf("Enter number of elements for first array: ");
    if (scanf("%d", &n1) != 1 || n1 <= 0) return 1;
    int arr1[n1];
    printf("Enter %d elements: ", n1);
    for (int i = 0; i < n1; i++) {
        if (scanf("%d", &arr1[i]) != 1) return 1;
    }

    printf("Enter number of elements for second array: ");
    if (scanf("%d", &n2) != 1 || n2 <= 0) return 1;
    int arr2[n2];
    printf("Enter %d elements: ", n2);
    for (int i = 0; i < n2; i++) {
        if (scanf("%d", &arr2[i]) != 1) return 1;
    }

    printf("Common elements: ");
    int foundAny = 0;
    for (int i = 0; i < n1; i++) {
        int isDuplicate = 0;
        for (int k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate) continue;

        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d ", arr1[i]);
                foundAny = 1;
                break;
            }
        }
    }

    if (!foundAny) {
        printf("None");
    }
    printf("\n");

    return 0;
}
