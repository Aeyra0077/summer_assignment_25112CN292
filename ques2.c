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
    int rotatedleft[n];
    for (int i = 0; i < n; i++) {
        rotatedleft[i] = arr[(i + 1) % n];
    }
    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", rotatedleft[i]);
    }
    return 0;
}
