#include <stdio.h>

int main() {
    int pin = 1234;
    int entered_pin;
    int choice;
    int attempts = 0;
    float balance = 5000.0;
    float amount;

    printf("=== Welcome to the ATM ===\n");

    while (attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        scanf("%d", &entered_pin);

        if (entered_pin == pin) {
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. Attempts remaining: %d\n\n", 3 - attempts);
        }
    }

    if (attempts == 3) {
        printf("Too many incorrect attempts. Your card has been blocked.\n");
        return 0;
    }

    while (1) {
        printf("\n=== ATM Main Menu ===\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nYour current balance is: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter the amount to deposit: $");
                scanf("%f", &amount);
                if (amount > 0) {
                    balance += amount;
                    printf("$%.2f successfully deposited.\n", amount);
                } else {
                    printf("Invalid deposit amount.\n");
                }
                break;

            case 3:
                printf("\nEnter the amount to withdraw: $");
                scanf("%f", &amount);
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("$%.2f successfully withdrawn.\n", amount);
                } else if (amount > balance) {
                    printf("Insufficient balance.\n");
                } else {
                    printf("Invalid withdrawal amount.\n");
                }
                break;

            case 4:
                printf("\nThank you for using the ATM. Goodbye!\n");
                return 0;

            default:
                printf("\nInvalid option. Please choose between 1 and 4.\n");
        }
    }

    return 0;
}
