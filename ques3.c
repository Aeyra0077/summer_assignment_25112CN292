#include <stdio.h>
#include <string.h>

int main() {
    int choice;
    char str1[200];
    char str2[100];

    do {
        printf("\n=== STRING OPERATIONS MENU ===\n");
        printf("1. Find String Length\n");
        printf("2. Copy String\n");
        printf("3. Concatenate Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse String\n");
        printf("6. Exit\n");
        printf("Enter your choice (1-6): ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Length of the string: %lu\n", strlen(str1));
                break;

            case 2:
                printf("Enter source string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                strcpy(str2, str1);
                printf("Copied target string: %s\n", str2);
                break;

            case 3:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter first string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                printf("Enter second string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                int res = strcmp(str1, str2);
                if (res == 0) {
                    printf("Strings are equal.\n");
                } else if (res > 0) {
                    printf("First string is greater.\n");
                } else {
                    printf("Second string is greater.\n");
                }
                break;

            case 5:
                printf("Enter a string: ");
                fgets(str1, sizeof(str1), stdin);
                str1[strcspn(str1, "\n")] = '\0';
                long len = strlen(str1);
                printf("Reversed string: ");
                for (long i = len - 1; i >= 0; i--) {
                    putchar(str1[i]);
                }
                printf("\n");
                break;

            case 6:
                printf("Exiting the system.\n");
                break;

            default:
                printf("Invalid selection! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
