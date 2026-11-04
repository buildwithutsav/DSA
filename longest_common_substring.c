#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char s1[] = "ABCDGH";
    char s2[] = "ACDGHR";

    int m = strlen(s1);
    int n = strlen(s2);

    int dp[MAX + 1][MAX + 1] = {0};

    int maxLength = 0;
    int endIndex = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;

                if (dp[i][j] > maxLength) {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }

    printf("Longest Common Substring Length: %d\n",
           maxLength);

    printf("Substring: ");

    for (int i = endIndex - maxLength; i < endIndex; i++)
        printf("%c", s1[i]);

    printf("\n");

    return 0;
}