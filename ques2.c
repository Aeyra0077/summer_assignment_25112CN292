#include <stdio.h>

int main() {
    int num, original_num, remainder, sum = 0;
    long fact;

    printf("Enter an integer: ");
    scanf("%d", &num);

    original_num = num;

    while (num > 0) {
        remainder = num % 10;
        fact = 1;

        for (int i = 1; i <= remainder; i++) {
            fact *= i;
        }

        sum += fact;
        num /= 10;
    }

    if (sum == original_num) {
        printf("%d is a strong number.\n", original_num);
    } else {
        printf("%d is not a strong number.\n", original_num);
    }

    return 0;
}
