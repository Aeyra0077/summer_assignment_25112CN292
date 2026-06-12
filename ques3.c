#include <stdio.h>

int countSetBits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    int num;
    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        return 1;
    }
    printf("Number of set bits: %d\n", countSetBits(num));
    return 0;
}
