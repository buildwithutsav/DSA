#include <stdio.h>

#define MAX 105

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, nums[MAX];
    int dp[MAX][MAX] = {0};

    printf("Enter number of balloons: ");
    scanf("%d", &n);

    printf("Enter balloon values:\n");

    for (int i = 1; i <= n; i++)
        scanf("%d", &nums[i]);

    nums[0] = nums[n + 1] = 1;

    for (int len = 1; len <= n; len++) {
        for (int left = 1; left <= n - len + 1; left++) {
            int right = left + len - 1;

            for (int k = left; k <= right; k++) {
                int coins =
                    nums[left - 1] * nums[k] * nums[right + 1]
                    + dp[left][k - 1]
                    + dp[k + 1][right];

                dp[left][right] =
                    max(dp[left][right], coins);
            }
        }
    }

    printf("Maximum coins = %d\n", dp[1][n]);

    return 0;
}