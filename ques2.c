#include <stdio.h>

int main() {
    int n, i, j, max_count = 0, max_element = 0, count;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter the elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for(i = 0; i < n; i++) {
        count = 1;
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
            }
        }
        if(count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }
    
    printf("Maximum frequency element: %d (occurs %d times)\n", max_element, max_count);
    
    return 0;
}
