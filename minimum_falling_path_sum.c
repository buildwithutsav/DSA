
#include <stdio.h>

#define MAX 100

int min(int a, int b) {
    return a < b ? a : b;
}

int minFallingPathSum(int matrix[MAX][MAX], int n) {
    int dp[MAX][MAX];

    // First row is the starting point
    for (int j = 0; j < n; j++)
        dp[0][j] = matrix[0][j];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int best = dp[i - 1][j];

            if (j > 0)
                best = min(best, dp[i - 1][j - 1]);

            if (j < n - 1)
                best = min(best, dp[i - 1][j + 1]);

            dp[i][j] = matrix[i][j] + best;
        }
    }

    int answer = dp[n - 1][0];

    for (int j = 1; j < n; j++)
        answer = min(answer, dp[n - 1][j]);

    return answer;
}

int main() {
    int n;
    int matrix[MAX][MAX];

    printf("Enter matrix size: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid matrix size\n");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }

    printf("Minimum falling path sum: %d\n",
           minFallingPathSum(matrix, n));

    return 0;
}
