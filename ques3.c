#include <stdio.h>
#include <string.h>

int main() {
    char str[500];
    char longest[500] = "";
    char current[500];
    int i = 0, j = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            current[j++] = str[i];
        } else {
            if (j > 0) {
                current[j] = '\0';
                if (strlen(current) > strlen(longest)) {
                    strcpy(longest, current);
                }
                j = 0;
            }
        }
        i++;
    }

    if (j > 0) {
        current[j] = '\0';
        if (strlen(current) > strlen(longest)) {
            strcpy(longest, current);
        }
    }

    printf("Longest word: %s\n", longest);
    printf("Length: %lu\n", (unsigned long)strlen(longest));

    return 0;
}
