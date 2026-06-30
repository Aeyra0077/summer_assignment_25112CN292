#include <stdio.h>
#include <string.h>

struct BankAccount {
    int accNumber;
    char name[50];
    float balance;
};

void createAccount(struct BankAccount *acc) {
    printf("\n--- Create Account ---\n");
    printf("Enter Account Number: ");
    scanf("%d", &acc->accNumber);
    printf("Enter Account Holder Name: ");
    scanf("%s", acc->name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &acc->balance);
    printf("Account created successfully!\n");
}

void checkBalance(struct BankAccount acc) {
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", acc.accNumber);
    printf("Holder Name: %s\n", acc.name);
    printf("Current Balance: %.2f\n", acc.balance);
}

void deposit(struct BankAccount *acc) {
    float amount;
    printf("\n--- Deposit ---\n");
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        acc->balance += amount;
        printf("Deposit successful. New Balance: %.2f\n", acc->balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(struct BankAccount *acc) {
    float amount;
    printf("\n--- Withdraw ---\n");
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= acc->balance) {
        acc->balance -= amount;
        printf("Withdrawal successful. New Balance: %.2f\n", acc->balance);
    } else if (amount > acc->balance) {
        printf("Insufficient balance.\n");
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

int main() {
    struct BankAccount account;
    int choice;
    account.accNumber = 0;

    do {
        printf("\n=== Bank Management System ===\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(&account);
                break;
            case 2:
                if (account.accNumber == 0)
                    printf("No account found. Please create an account first.\n");
                else
                    checkBalance(account);
                break;
            case 3:
                if (account.accNumber == 0)
                    printf("No account found. Please create an account first.\n");
                else
                    deposit(&account);
                break;
            case 4:
                if (account.accNumber == 0)
                    printf("No account found. Please create an account first.\n");
                else
                    withdraw(&account);
                break;
            case 5:
                printf("Thank you for using the Bank Management System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
