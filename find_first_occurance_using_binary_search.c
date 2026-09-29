#include <stdio.h>

int main() {

    int arr[] = {10, 20, 20, 20, 30, 40};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target;

    printf("Enter target: ");
    scanf("%d", &target);

    int low = 0;
    int high = n - 1;

    int result = -1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {

            result = mid;

            /* Continue searching towards left */
            high = mid - 1;
        }

        else if(arr[mid] < target) {

            low = mid + 1;
        }

        else {

            high = mid - 1;
        }
    }

    if(result == -1) {
        printf("Element not found\n");
    }
    else {
        printf("First occurrence = position %d\n", result + 1);
    }

    return 0;
}