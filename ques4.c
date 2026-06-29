#include <stdio.h>
#include <string.h>

void remove_duplicates(char *str) {
    int hash[256] = {0};
    int current_index = 0;
    int unique_index = 0;

    while (str[current_index] != '\0') {
        unsigned char temp = str[current_index];
        if (hash[temp] == 0) {
            hash[temp] = 1;
            str[unique_index] = str[current_index];
            unique_index++;
        }
        current_index++;
    }
    str[unique_index] = '\0';
}

int main() {
    char text[100];

    printf("Enter a string: ");
    if (fgets(text, sizeof(text), stdin)) {
        text[strcspn(text, "\n")] = '\0';
        remove_duplicates(text);
        printf("Result: %s\n", text);
    }

    return 0;
}
