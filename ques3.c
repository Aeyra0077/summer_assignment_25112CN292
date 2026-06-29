#include <stdio.h>

int main() {
    int i, j, k;
    int size1, size2;
    int arr1[100], arr2[100], intersection[100];
    int index = 0;

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

    for (i = 0; i < size1; i++) {
        for (j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                int already_exists = 0;
                for (k = 0; k < index; k++) {
                    if (intersection[k] == arr1[i]) {
                        already_exists = 1;
                        break;
                    }
                }
                if (!already_exists) {
                    intersection[index] = arr1[i];
                    index++;
                }
                break;
            }
        }
    }

    printf("Intersection: ");
    for (i = 0; i < index; i++) {
        printf("%d ", intersection[i]);
    }
    printf("\n");

    return 0;
}
