#include <stdio.h>
#include <limits.h>

#define MAX 105

long long dp[MAX][MAX];
long long prefix[MAX];

long long minCost(int piles[], int n, int K) {

    if (n == 1) {
        return 0;
    }

    if (K < 2 || (n - 1) % (K - 1) != 0) {
        return -1;
    }

    // Build prefix sums.
    prefix[0] = 0;

    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + piles[i];
    }

    // Initialize DP.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }

    // Process intervals of increasing length.
    for (int len = 2; len <= n; len++) {

        for (int i = 0; i + len <= n; i++) {

            int j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            // Try valid split positions.
            for (int m = i; m < j; m += K - 1) {

                long long cost =
                    dp[i][m] + dp[m + 1][j];

                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }

            // Merge the remaining K piles into one.
            if ((len - 1) % (K - 1) == 0) {

                long long sum =
                    prefix[j + 1] - prefix[i];

                dp[i][j] += sum;
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n, K;

    scanf("%d", &n);
    scanf("%d", &K);

    if (n < 1 || n >= MAX || K < 2) {
        printf("-1\n");
        return 0;
    }

    int piles[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }

    printf("%lld\n", minCost(piles, n, K));

    return 0;
}