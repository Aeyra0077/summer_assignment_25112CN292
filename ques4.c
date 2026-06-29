#include <stdio.h>

void remove_spaces(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}

int main() {
    char text[1000];
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);
    
    printf("Original: %s\n", text);
    remove_spaces(text);
    printf("Modified: %s\n", text);
    return 0;
}
