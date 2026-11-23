
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000
#define LEN 100

int compareWords(const void *a, const void *b) {
    const char *x = (const char *)a;
    const char *y = (const char *)b;

    int lx = strlen(x);
    int ly = strlen(y);

    return (lx > ly) - (lx < ly);
}

int isPredecessor(char *shorter, char *longer) {
    int i = 0, j = 0;
    int skipped = 0;

    int n = strlen(shorter);
    int m = strlen(longer);

    if (m != n + 1)
        return 0;

    while (i < n && j < m) {
        if (shorter[i] == longer[j]) {
            i++;
            j++;
        } else {
            if (skipped)
                return 0;

            skipped = 1;
            j++;
        }
    }

    return 1;
}

int longestStringChain(char words[][LEN], int n) {
    qsort(words, n, sizeof(words[0]), compareWords);

    int dp[MAX];
    int answer = 0;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;

        for (int j = 0; j < i; j++) {
            if (isPredecessor(words[j], words[i]) &&
                dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
            }
        }

        if (dp[i] > answer)
            answer = dp[i];
    }

    return answer;
}

int main() {
    int n;
    char words[MAX][LEN];

    printf("Enter number of words: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
        return 0;

    printf("Enter words:\n");

    for (int i = 0; i < n; i++)
        scanf("%99s", words[i]);

    printf("Longest chain length: %d\n",
           longestStringChain(words, n));

    return 0;
}
