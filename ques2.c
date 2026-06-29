#include <stdio.h>
#include <string.h>

char find_first_repeating(const char *str) {
    int seen[256] = {0};
    
    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];
        if (seen[ch] == 1) {
            return ch;
        }
        seen[ch] = 1;
    }
    
    return '\0';
}

int main() {
    char str[100];
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0'; 
    char result = find_first_repeating(str);
    
    if (result != '\0') {
        printf("First repeating character: %c\n", result);
    } else {
        printf("No repeating character found.\n");
    }
    
    return 0;
}
}