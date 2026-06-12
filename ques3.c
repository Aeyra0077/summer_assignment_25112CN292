#include <stdio.h>

int find_gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        return 1;
    }
    
    printf("GCD of %d and %d is %d\n", num1, num2, find_gcd(num1, num2));
    
    return 0;
}
