#include <stdio.h>

int main() {
    int n1, n2;

    printf("Enter size of first array: ");
    scanf("%d", &n1);
    int arr1[n1];
    printf("Enter elements of first array: ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of second array: ");
    scanf("%d", &n2);
    int arr2[n2];
    printf("Enter elements of second array: ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    int uni[n1 + n2];
    int k = 0;

    for (int i = 0; i < n1; i++) {
        int duplicate = 0;
        for (int j = 0; j < k; j++) {
            if (arr1[i] == uni[j]) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            uni[k++] = arr1[i];
        }
    }

    for (int i = 0; i < n2; i++) {
        int duplicate = 0;
        for (int j = 0; j < k; j++) {
            if (arr2[i] == uni[j]) {
                duplicate = 1;
                break;
            }
        }
        if (!duplicate) {
            uni[k++] = arr2[i];
        }
    }

    printf("Union of the arrays: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", uni[i]);
    }
    printf("\n");

    return 0;
}
