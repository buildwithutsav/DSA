#include <stdio.h>

int main(void) {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int current = arr[0];
    int maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (current + arr[i] < arr[i])
            current = arr[i];
        else
            current += arr[i];

        if (current > maximum)
            maximum = current;
    }

    printf("Maximum subarray sum: %d\n", maximum);
    return 0;
}