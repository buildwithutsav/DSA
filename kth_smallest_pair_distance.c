
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

long long countPairs(int arr[], int n, int distance) {
    long long count = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        while ((long long)arr[right] - arr[left] > distance)
            left++;

        count += right - left;
    }

    return count;
}

int kthSmallestDistance(int arr[], int n, long long k) {
    qsort(arr, n, sizeof(int), compare);

    int low = 0;
    int high = arr[n - 1] - arr[0];

    while (low < high) {
        int mid = low + (high - low) / 2;

        long long count = countPairs(arr, n, mid);

        if (count >= k)
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}

int main() {
    int n;
    long long k;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 2)
        return 0;

    int arr[n];

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long totalPairs = (long long)n * (n - 1) / 2;

    printf("Enter k: ");
    scanf("%lld", &k);

    if (k < 1 || k > totalPairs) {
        printf("Invalid k\n");
        return 0;
    }

    printf("Kth smallest distance: %d\n",
           kthSmallestDistance(arr, n, k));

    return 0;
}
