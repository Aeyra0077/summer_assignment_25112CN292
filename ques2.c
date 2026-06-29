#include <stdio.h>
#include <string.h>

void findCommonCharacters(char *str1, char *str2) {
    int count1[256] = {0};
    int count2[256] = {0};
    
    for (int i = 0; str1[i] != '\0'; i++) {
        count1[(unsigned char)str1[i]]++;
    }
    
    for (int i = 0; str2[i] != '\0'; i++) {
        count2[(unsigned char)str2[i]]++;
    }
    
    printf("Common characters: ");
    int found = 0;
    for (int i = 0; i < 256; i++) {
        if (count1[i] > 0 && count2[i] > 0) {
            int min_count = (count1[i] < count2[i]) ? count1[i] : count2[i];
            for (int j = 0; j < min_count; j++) {
                printf("%c ", i);
            }
            found = 1;
        }
    }
    
    if (!found) {
        printf("None");
    }
    printf("\n");
}

int main() {
    char str1[256];
    char str2[256];
    
    printf("Enter first string: ");
    if (fgets(str1, sizeof(str1), stdin)) {
        str1[strcspn(str1, "\n")] = '\0';
    }
    
    printf("Enter second string: ");
    if (fgets(str2, sizeof(str2), stdin)) {
        str2[strcspn(str2, "\n")] = '\0';
    }
    
    findCommonCharacters(str1, str2);
    
    return 0;
}
