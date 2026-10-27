#include <stdio.h>
#include <limits.h>

int main(void) {
    int coins[] = {1, 3, 4};
    int n = sizeof(coins) / sizeof(coins[0]);
    int amount = 6;

    int dp[amount + 1];

    dp[0] = 0;

    for (int a = 1; a <= amount; a++)
        dp[a] = INT_MAX;

    for (int a = 1; a <= amount; a++) {
        for (int i = 0; i < n; i++) {
            if (coins[i] > 0 && coins[i] <= a &&
                dp[a - coins[i]] != INT_MAX) {
                int candidate = dp[a - coins[i]] + 1;

                if (candidate < dp[a])
                    dp[a] = candidate;
            }
        }
    }

    if (dp[amount] == INT_MAX)
        printf("Amount cannot be formed\n");
    else
        printf("Minimum coins required: %d\n", dp[amount]);

    return 0;
}