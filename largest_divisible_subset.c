
#include <stdio.h>
#include <stdlib.h>

void largestDivisibleSubset(int arr[], int n) {
    if (n == 0)
        return;

    // Sort array
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int dp[n];
    int parent[n];

    int maxLength = 1;
    int lastIndex = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        parent[i] = -1;

        for (int j = 0; j < i; j++) {
            if (arr[i] % arr[j] == 0 &&
                dp[j] + 1 > dp[i]) {

                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if (dp[i] > maxLength) {
            maxLength = dp[i];
            lastIndex = i;
        }
    }

    int result[maxLength];
    int count = 0;

    int current = lastIndex;

    while (current != -1) {
        result[count++] = arr[current];
        current = parent[current];
    }

    printf("Largest divisible subset: ");

    for (int i = count - 1; i >= 0; i--)
        printf("%d ", result[i]);

    printf("\nSubset size: %d\n", maxLength);
}

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    int arr[n];

    printf("Enter positive distinct integers: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] <= 0) {
            printf("All elements must be positive\n");
            return 0;
        }
    }

    largestDivisibleSubset(arr, n);

    return 0;
}
