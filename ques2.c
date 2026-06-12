#include <stdio.h>

int main() {
    int start, end, i, j, isPrime;

    printf("Enter the lower and upper bounds: ");
    if (scanf("%d %d", &start, &end) != 2) {
        return 1;
    }

    if (start > end) {
        int temp = start;
        start = end;
        end = temp;
    }

    printf("Prime numbers between %d and %d are: ", start, end);

    for (i = start; i <= end; i++) {
        if (i < 2) {
            continue;
        }

        isPrime = 1;

        for (j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
