#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int limit;
    int largestPrime = -1;

    printf("Enter the upper limit: ");
    if (scanf("%d", &limit) != 1) {
        return 1;
    }

    for (int i = limit; i >= 2; i--) {
        if (isPrime(i)) {
            largestPrime = i;
            break;
        }
    }

    if (largestPrime != -1) {
        printf("The largest prime number up to %d is: %d\n", limit, largestPrime);
    } else {
        printf("No prime number found in the given range.\n");
    }

    return 0;
}
