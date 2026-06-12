#include <stdio.h>
#include <math.h>

int main() {
    int start, end, i, temp1, temp2, remainder, digits, sum;

    printf("Enter lower and upper limits: ");
    scanf("%d %d", &start, &end);

    printf("Armstrong numbers between %d and %d are: ", start, end);

    if (start > end) {
        temp1 = start;
        start = end;
        end = temp1;
    }

    for (i = start; i <= end; i++) {
        temp1 = i;
        temp2 = i;
        digits = 0;
        sum = 0;

        while (temp1 != 0) {
            temp1 /= 10;
            digits++;
        }

        while (temp2 != 0) {
            remainder = temp2 % 10;
            sum += round(pow(remainder, digits));
            temp2 /= 10;
        }

        if (sum == i) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}

        