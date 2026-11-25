#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    int arr[n];

    int total = 0;

    int currentMax, maxSum;
    int currentMin, minSum;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        total += arr[i];

        if (i == 0) {
            currentMax = maxSum = arr[i];
            currentMin = minSum = arr[i];
        } else {
            currentMax = max(arr[i], currentMax + arr[i]);
            maxSum = max(maxSum, currentMax);

            currentMin = min(arr[i], currentMin + arr[i]);
            minSum = min(minSum, currentMin);
        }
    }

    // All elements are negative.
    if (maxSum < 0) {
        printf("%d\n", maxSum);
    } else {
        int circularSum = total - minSum;
        printf("%d\n", max(maxSum, circularSum));
    }

    return 0;
}