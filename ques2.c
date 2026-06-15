#include <stdio.h>

int findMax(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1 , num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = findMax(num1, num2);
    
    printf("The maximum is: %d\n", result);
    return 0;
}
