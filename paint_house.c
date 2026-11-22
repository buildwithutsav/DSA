
#include <stdio.h>

#define MAX 1000

int min(int a, int b) {
    return a < b ? a : b;
}

int minPaintingCost(int cost[][3], int n) {
    int dp[MAX][3];

    for (int j = 0; j < 3; j++)
        dp[0][j] = cost[0][j];

    for (int i = 1; i < n; i++) {
        dp[i][0] = cost[i][0] +
                   min(dp[i - 1][1], dp[i - 1][2]);

        dp[i][1] = cost[i][1] +
                   min(dp[i - 1][0], dp[i - 1][2]);

        dp[i][2] = cost[i][2] +
                   min(dp[i - 1][0], dp[i - 1][1]);
    }

    return min(dp[n - 1][0],
               min(dp[n - 1][1], dp[n - 1][2]));
}

int main() {
    int n;
    int cost[MAX][3];

    printf("Enter number of houses: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of houses\n");
        return 0;
    }

    printf("Enter painting costs (Red Blue Green):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] < 0) {
                printf("Costs cannot be negative\n");
                return 0;
            }
        }
    }

    printf("Minimum cost: %d\n",
           minPaintingCost(cost, n));

    return 0;
}
