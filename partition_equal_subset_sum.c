#include <stdio.h>

#define N 4

int main() {
    int arr[N] = {1, 5, 11, 5};

    int total = 0;

    for (int i = 0; i < N; i++)
        total += arr[i];

    if (total % 2 != 0) {
        printf("Cannot partition into equal subsets.\n");
        return 0;
    }

    int target = total / 2;

    int dp[target + 1];

    for (int i = 0; i <= target; i++)
        dp[i] = 0;

    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = target; j >= arr[i]; j--) {
            if (dp[j - arr[i]])
                dp[j] = 1;
        }
    }

    if (dp[target])
        printf("Array can be partitioned into equal subsets.\n");
    else
        printf("Array cannot be partitioned into equal subsets.\n");

    return 0;
}