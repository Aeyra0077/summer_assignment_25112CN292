#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    } 
    int movezero[n];
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            movezero[index++] = arr[i];
        }
    }
    while (index < n) {
        movezero[index++] = 0;
    }
    printf("Array with zeros moved to the end:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", movezero[i]);
    }
return 0;
}