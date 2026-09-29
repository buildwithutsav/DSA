#include <stdio.h>

int main() {

    int n, i, target;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted elements: ");

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    int low = 0;
    int high = n - 1;
    int found = 0;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {

            printf("Element found at position %d\n", mid + 1);
            found = 1;
            break;
        }

        else if(target < arr[mid]) {

            high = mid - 1;
        }

        else {

            low = mid + 1;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}