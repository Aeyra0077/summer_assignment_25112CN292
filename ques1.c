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
    int reversed[n];
    for (int i = 0; i < n; i++) {
        reversed[i] = arr[n - 1 - i];
    }
    printf("Reversed array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", reversed[i]);
    }
    return 0;
}