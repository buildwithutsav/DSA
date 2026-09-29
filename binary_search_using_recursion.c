#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {

    if(low > high) {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if(arr[mid] == target) {
        return mid;
    }

    if(target < arr[mid]) {
        return binarySearch(arr, low, mid - 1, target);
    }

    return binarySearch(arr, mid + 1, high, target);
}

int main() {

    int arr[] = {10, 20, 30, 40, 50, 60, 70};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target;

    printf("Enter target: ");
    scanf("%d", &target);

    int result = binarySearch(arr, 0, n - 1, target);

    if(result == -1) {
        printf("Element not found\n");
    }
    else {
        printf("Element found at position %d\n", result + 1);
    }

    return 0;
}