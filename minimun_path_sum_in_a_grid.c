#include <stdio.h>

#define R 3
#define C 3

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int grid[R][C] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    int dp[R][C];

    dp[0][0] = grid[0][0];

    for (int i = 1; i < R; i++)
        dp[i][0] = dp[i - 1][0] + grid[i][0];

    for (int j = 1; j < C; j++)
        dp[0][j] = dp[0][j - 1] + grid[0][j];

    for (int i = 1; i < R; i++) {
        for (int j = 1; j < C; j++) {
            dp[i][j] = grid[i][j] +
                       min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    printf("Minimum Path Sum: %d\n",
           dp[R - 1][C - 1]);

    return 0;
}