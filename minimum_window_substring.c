#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    char s[1000], t[1000];
    int need[256] = {0};
    int window[256] = {0};

    printf("Enter source string: ");
    scanf("%999s", s);

    printf("Enter target string: ");
    scanf("%999s", t);

    int m = strlen(s);
    int n = strlen(t);

    if (n > m) {
        printf("Minimum window: Not found\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        need[(unsigned char)t[i]]++;

    int required = n;
    int left = 0;
    int minLen = INT_MAX;
    int start = 0;

    for (int right = 0; right < m; right++) {
        unsigned char c = (unsigned char)s[right];

        if (window[c] < need[c])
            required--;

        window[c]++;

        while (required == 0) {
            int len = right - left + 1;

            if (len < minLen) {
                minLen = len;
                start = left;
            }

            unsigned char x = (unsigned char)s[left];

            window[x]--;

            if (window[x] < need[x])
                required++;

            left++;
        }
    }

    if (minLen == INT_MAX) {
        printf("Minimum window: Not found\n");
    } else {
        printf("Minimum window: ");

        for (int i = start; i < start + minLen; i++)
            putchar(s[i]);

        printf("\n");
    }

    return 0;
}