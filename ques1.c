#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_number, guess, attempts = 0;

    srand(time(NULL));
    secret_number = (rand() % 100) + 1;

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have picked a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess > secret_number) {
            printf("Too high! Try again.\n");
        } else if (guess < secret_number) {
            printf("Too low! Try again.\n");
        } else {
            printf("\nCongratulations! You guessed the number %d correctly!\n", secret_number);
            printf("Total attempts: %d\n", attempts);
        }
    } while (guess != secret_number);

    return 0;
}
