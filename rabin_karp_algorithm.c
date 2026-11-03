#include <stdio.h>
#include <string.h>

#define BASE 256
#define MOD 101

void rabinKarp(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);

    if (m == 0 || m > n)
        return;

    int patternHash = 0;
    int textHash = 0;
    int h = 1;

    for (int i = 0; i < m - 1; i++)
        h = (h * BASE) % MOD;

    for (int i = 0; i < m; i++) {
        patternHash = (BASE * patternHash +
                       pattern[i]) % MOD;

        textHash = (BASE * textHash +
                    text[i]) % MOD;
    }

    for (int i = 0; i <= n - m; i++) {

        if (patternHash == textHash) {
            if (strncmp(text + i, pattern, m) == 0)
                printf("Pattern found at index %d\n", i);
        }

        if (i < n - m) {
            textHash = (BASE *
                       (textHash - text[i] * h) +
                       text[i + m]) % MOD;

            if (textHash < 0)
                textHash += MOD;
        }
    }
}

int main() {
    char text[] = "ABCCDDAEFG";
    char pattern[] = "CDD";

    rabinKarp(text, pattern);

    return 0;
}