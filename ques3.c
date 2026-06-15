#include <stdio.h>

void printFibonacci(int n) {
    if (n <= 0) {
        return;
    }
    
    int t1 = 0;
    if (n == 1) {
        printf("%d\n", t1);
        return;
    }
    
    int t2 = 1;
    printf("%d %d ", t1, t2);
    
    for (int i = 3; i <= n; i++) {
        int nextTerm = t1 + t2;
        printf("%d ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
    }
    printf("\n");
}

int main() {
    int terms;
    printf("Enter the number of terms: ");
    if (scanf("%d", &terms) == 1) {
        printFibonacci(terms);
    }
    return 0;
}
