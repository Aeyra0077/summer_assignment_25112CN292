#include <stdio.h>

int main() {
    int n;
    unsigned long long a = 0, b = 1, next;

    if (scanf("%d", &n) != 1 || n < 0) {
        return 1;
    }

    if (n == 0) {
        printf("%llu\n", a);
        return 0;
    }
    if (n == 1) {
        printf("%llu\n", b);
        return 0;
    }

    for (int i = 2; i <= n; i++) {
        next = a + b;
        a = b;
        b = next;
    }

    printf("%llu\n", b);
    return 0;
}
