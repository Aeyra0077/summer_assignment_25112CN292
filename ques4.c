#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    char words[50][50];
    int i = 0, j = 0, k = 0, word_count = 0;

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == ' ') {
            words[word_count][j] = '\0';
            word_count++;
            j = 0;
        } else {
            words[word_count][j++] = str[i];
        }
    }
    words[word_count][j] = '\0';
    word_count++;

    for(i = 0; i < word_count - 1; i++) {
        for(j = 0; j < word_count - i - 1; j++) {
            if(strlen(words[j]) > strlen(words[j+1])) {
                char temp[50];
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for(i = 0; i < word_count; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}
