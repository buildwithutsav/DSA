#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
    int result = a < b ? a : b;
    return result < c ? result : c;
}

int main(void) {
    char s1[] = "horse";
    char s2[] = "ros";

    int m = strlen(s1);
    int n = strlen(s2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;

    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min(
                    dp[i - 1][j],
                    dp[i][j - 1],
                    dp[i - 1][j - 1]
                );
            }
        }
    }

    printf("Minimum edit distance: %d\n", dp[m][n]);

    return 0;
}