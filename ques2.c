#include <stdio.h>

int main() {
    int rows, i, j;

    printf("Enter the number of rows: ");
    if (scanf("%d", &rows) != 1) {
        return 1;
    }

    for (i = rows; i >= 1; i--) {
        for (j = 0; j < rows - i; j++) {
            printf(" ");
        }
        for (j = 0; j < (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
