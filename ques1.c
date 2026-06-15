#include <stdio.h>

int findSum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int a, b, sum;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    sum = findSum(a, b);

    printf("Sum: %d\n", sum);

    return 0;
}
