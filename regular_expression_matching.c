#include <stdio.h>
#include <string.h>

#define MAX 1000

int main() {
    char s[MAX], p[MAX];
    int dp[MAX][MAX] = {0};

    printf("Enter string: ");
    scanf("%999s", s);

    printf("Enter pattern: ");
    scanf("%999s", p);

    int m = strlen(s);
    int n = strlen(p);

    dp[0][0] = 1;

    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*')
            dp[0][j] = dp[0][j - 2];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (p[j - 1] == '.' ||
                p[j - 1] == s[i - 1]) {

                dp[i][j] = dp[i - 1][j - 1];
            }

            else if (p[j - 1] == '*' && j >= 2) {

                dp[i][j] = dp[i][j - 2];

                if (p[j - 2] == '.' ||
                    p[j - 2] == s[i - 1]) {

                    dp[i][j] =
                        dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }

    if (dp[m][n])
        printf("Match\n");
    else
        printf("No match\n");

    return 0;
}