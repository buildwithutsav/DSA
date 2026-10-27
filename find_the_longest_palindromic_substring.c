#include <stdio.h>
#include <string.h>

void longestPalindrome(const char *s) {
    int n = (int)strlen(s);

    if (n == 0) {
        printf("Longest palindrome: (empty)\n");
        return;
    }

    int bestStart = 0, bestLength = 1;

    for (int center = 0; center < n; center++) {
        for (int type = 0; type < 2; type++) {
            int left = center;
            int right = center + type;

            while (left >= 0 && right < n &&
                   s[left] == s[right]) {
                int length = right - left + 1;

                if (length > bestLength) {
                    bestLength = length;
                    bestStart = left;
                }

                left--;
                right++;
            }
        }
    }

    printf("Longest palindrome: ");
    for (int i = bestStart; i < bestStart + bestLength; i++)
        putchar(s[i]);

    printf("\nLength: %d\n", bestLength);
}

int main(void) {
    longestPalindrome("babad");
    return 0;
}