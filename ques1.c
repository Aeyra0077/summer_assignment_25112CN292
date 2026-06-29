#include <stdio.h>

int findMissingNumber(int arr[], int n) {
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;
    for (int i = 0; i < n - 1; i++) {
        arraySum += arr[i];
    }
    return totalSum - arraySum;
}

int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int n = 6; 
    int missingNumber = findMissingNumber(arr, n);
    printf("The missing number is: %d\n", missingNumber);
    return 0;
}
 