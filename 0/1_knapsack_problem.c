#include <stdio.h>

int main(void) {
    int weight[] = {1, 3, 4, 5};
    int value[]  = {1, 4, 5, 7};
    int n = 4, W = 7;

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weight[i - 1] <= w) {
                int include = value[i - 1] +
                              dp[i - 1][w - weight[i - 1]];
                int exclude = dp[i - 1][w];

                dp[i][w] = include > exclude ? include : exclude;
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("Maximum value: %d\n", dp[n][W]);
    return 0;
}