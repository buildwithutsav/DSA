#include <stdio.h>
#include <string.h>

void buildLPS(const char *pattern, int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len > 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
}

int kmpSearch(const char *text, const char *pattern) {
    int n = (int)strlen(text);
    int m = (int)strlen(pattern);

    if (m == 0)
        return 0;

    int lps[m];
    buildLPS(pattern, m, lps);

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == m)
            return i - j;

        if (i < n && text[i] != pattern[j]) {
            if (j > 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return -1;
}

int main(void) {
    const char *text = "ABABDABACDABABCABAB";
    const char *pattern = "ABABCABAB";

    int index = kmpSearch(text, pattern);

    if (index == -1)
        printf("Pattern not found\n");
    else
        printf("Pattern found at index: %d\n", index);

    return 0;
}