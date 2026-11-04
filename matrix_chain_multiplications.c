#include <stdio.h>
#include <limits.h>

#define N 4

int main() {
    int p[N] = {10, 30, 5, 60};

    int dp[N][N] = {0};

    for (int len = 2; len < N; len++) {

        for (int i = 1; i < N - len + 1; i++) {

            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum Multiplications: %d\n",
           dp[1][N - 1]);

    return 0;
}