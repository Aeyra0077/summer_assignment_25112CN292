#include <stdio.h>
#include <stdlib.h>

int main() {
    int num, temp;
    long long product = 1;

    printf("Enter any number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (num == 0) {
        product = 0;
    } else {
        
        temp = abs(num);

        while (temp > 0) {
            product *= (temp % 10); 
            temp /= 10;            
    
    }
    }
    printf("Product of digits = %lld\n", product);

    return 0;
}
