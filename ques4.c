#include <stdio.h>
#include <string.h>

int main() {
    char str[256];
    int freq[256] = {0};
    int max = 0;
    char max_char;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > max) {
            max = freq[i];
            max_char = (char)i;
        }
    }

    if (max > 0) {
        printf("Maximum occurring character is '%c' (occurs %d times).\n", max_char, max);
    } else {
        printf("The string is empty.\n");
    }

    return 0;
}
