#include <stdio.h>

int main(void) {
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    int dp[n];
    int answer = arr[0];

    for (int i = 0; i < n; i++)
        dp[i] = arr[i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] &&
                dp[j] + arr[i] > dp[i]) {
                dp[i] = dp[j] + arr[i];
            }
        }

        if (dp[i] > answer)
            answer = dp[i];
    }

    printf("Maximum increasing subsequence sum: %d\n",
           answer);

    return 0;
}