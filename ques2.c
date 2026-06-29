#include <stdio.h>

void compressString(char *src, char *dest) {
    int i = 0, j = 0;
    while (src[i] != '\0') {
        dest[j++] = src[i];
        int count = 1;
        while (src[i] == src[i + 1]) {
            count++;
            i++;
        }
        j += sprintf(&dest[j], "%d", count);
        i++;
    }
    dest[j] = '\0';
}

int main() {
    char str[100], compressed[200];
    printf("Enter the string to compress: ");
    scanf("%s", str);
    
    compressString(str, compressed);
    
    printf("Original: %s\n", str);
    printf("Compressed: %s\n", compressed);
    
    return 0;
}
