#include <stdio.h>
#include <ctype.h>

int main() {
    char *questions[] = {
        "1. What is the capital of France?",
        "2. Which planet is known as the Red Planet?",
        "3. What is 2 + 2?"
    };

    char *options[][4] = {
        {"A. Berlin", "B. Madrid", "C. Paris", "D. Rome"},
        {"A. Earth", "B. Mars", "C. Venus", "D. Jupiter"},
        {"A. 3", "B. 4", "C. 5", "D. 6"}
    };

    char keys[] = {'C', 'B', 'B'};
    int score = 0;
    int total = sizeof(questions) / sizeof(questions[0]);
    char guess;

    for(int i = 0; i < total; i++) {
        printf("%s\n", questions[i]);
        for(int j = 0; j < 4; j++) {
            printf("%s\n", options[i][j]);
        }
        
        printf("Enter your answer (A, B, C, or D): ");
        scanf(" %c", &guess);
        
        guess = toupper(guess);
        
        if(guess == keys[i]) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was %c.\n\n", keys[i]);
        }
    }

    printf("Quiz Over!\n");
    printf("Your final score is: %d out of %d\n", score, total);
    
    return 0;
}
