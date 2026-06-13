#include <stdio.h>

int main() {
    int i, j;
    int size = 5;

    for (i = 1; i <= size; i++) {
        for (j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
