#include <stdio.h>

int main() {
    int n, k, x;

    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &k, &x);

    if (k <= 0 || k > n) {
        printf("Invalid k\n");
        return 0;
    }

    int low = 0;
    int high = n - k;

    while (low < high) {
        int mid = low + (high - low) / 2;

        long long leftDistance =
            (long long)x - arr[mid];

        long long rightDistance =
            (long long)arr[mid + k] - x;

        if (leftDistance > rightDistance) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    for (int i = low; i < low + k; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}