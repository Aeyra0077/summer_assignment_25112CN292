#include <stdio.h>

int main() {
    int age;

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    if (age < 0) {
        printf("Age cannot be negative.\n");
    } else if (age >= 18) {
        printf("You are eligible to vote.\n");
    } else {
        printf("You are not eligible to vote. You need to wait %d more year(s).\n", 18 - age);
    }

    return 0;
}
