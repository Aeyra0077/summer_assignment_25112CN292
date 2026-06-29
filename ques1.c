#include <stdio.h>
#include <string.h>

char findFirstUnique(char *str) {
    int count[256] = {0};
    int i;
    
    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }
    
    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] == 1) {
            return str[i];
        }
    }
    
    return '\0';
}

int main() {
    char str[100];
    char result;
    
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin)) {
        str[strcspn(str, "\n")] = '\0';
        
        result = findFirstUnique(str);
        
        if (result != '\0') {
            printf("The first non-repeating character is: %c\n", result);
        } else {
            printf("All characters are repeating or the string is empty.\n");
        }
    }
    
    return 0;
}
