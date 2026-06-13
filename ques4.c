#include <stdio.h>

int main() {
    int rows;
    char ch = 'A';

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1) {
        return 1;
    }

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("%c", ch);
        }
        ch++;
        printf("\n");
    }

    return 0;
}

