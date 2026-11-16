#include <stdio.h>

#define MAX 100

int main() {
    int n;
    int triangle[MAX][MAX];
    int dp[MAX];

    printf("Enter number of rows: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of rows\n");
        return 1;
    }

    printf("Enter triangle elements:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }

    // Initialize DP with bottom row
    for (int j = 0; j < n; j++)
        dp[j] = triangle[n - 1][j];

    // Bottom-up calculation
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            int minimum = (dp[j] < dp[j + 1])
                          ? dp[j] : dp[j + 1];

            dp[j] = triangle[i][j] + minimum;
        }
    }

    printf("Minimum path sum: %d\n", dp[0]);

    return 0;
}