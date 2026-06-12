#include <stdio.h>

int main() {
    double x;
    int n;
    double result = 1.0;
    
    printf("Enter base (x): ");
    if (scanf("%lf", &x) != 1) {
        return 1;
    }
    
    printf("Enter exponent (n): ");
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    
    int abs_n = n < 0 ? -n : n;
    
    for (int i = 0; i < abs_n; i++) {
        result *= x;
    }
    
    if (n < 0) {
        result = 1.0 / result;
    }
    
    printf("%.2lf^%d = %.6lf\n", x, n, result);
    
    return 0;
}
