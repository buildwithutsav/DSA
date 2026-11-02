#include <stdio.h>
#include <string.h>

int wordBreak(char str[], char dict[][20], int n) {
    int len = strlen(str);
    int dp[len + 1];

    dp[0] = 1;

    for (int i = 1; i <= len; i++)
        dp[i] = 0;

    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < n; j++) {

            int wordLen = strlen(dict[j]);

            if (wordLen <= i && dp[i - wordLen] &&
                strncmp(str + i - wordLen,
                        dict[j], wordLen) == 0) {

                dp[i] = 1;
                break;
            }
        }
    }

    return dp[len];
}

int main() {
    char str[] = "applepen";

    char dict[][20] = {
        "apple", "pen", "app", "le"
    };

    int n = 4;

    if (wordBreak(str, dict, n))
        printf("Yes, string can be segmented.");
    else
        printf("No, string cannot be segmented.");

    return 0;
}