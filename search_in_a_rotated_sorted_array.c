
#include <stdio.h>

int searchRotated(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
            return mid;

        // Left half is sorted
        if (arr[low] <= arr[mid]) {
            if (target >= arr[low] &&
                target < arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > arr[mid] &&
                target <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {
    int n, target;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    int arr[n];

    printf("Enter rotated sorted array: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target: ");
    scanf("%d", &target);

    int index = searchRotated(arr, n, target);

    if (index == -1)
        printf("Target not found\n");
    else
        printf("Index: %d\n", index);

    return 0;
}
