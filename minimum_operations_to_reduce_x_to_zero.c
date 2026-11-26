#include <stdio.h>

int main() {
    int n;
    long long x;

    scanf("%d", &n);

    if (n <= 0) {
        printf("-1\n");
        return 0;
    }

    int arr[n];
    long long total = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] <= 0) {
            printf("Invalid input\n");
            return 0;
        }

        total += arr[i];
    }

    scanf("%lld", &x);

    long long target = total - x;

    if (target < 0) {
        printf("-1\n");
        return 0;
    }

    int left = 0;
    int longest = -1;
    long long sum = 0;

    for (int right = 0; right < n; right++) {

        sum += arr[right];

        while (left <= right && sum > target) {
            sum -= arr[left];
            left++;
        }

        if (sum == target) {
            int length = right - left + 1;

            if (length > longest)
                longest = length;
        }
    }

    // If target is zero, keep the empty subarray.
    if (target == 0)
        longest = 0;

    if (longest == -1)
        printf("-1\n");
    else
        printf("%d\n", n - longest);

    return 0;
}