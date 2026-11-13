#include <stdio.h>
#include <stdlib.h>

#define MAX 102

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n, c;
    int cuts[MAX];
    int dp[MAX][MAX] = {0};

    printf("Enter stick length and number of cuts: ");
    scanf("%d %d", &n, &c);

    if (n <= 0 || c < 0 || c > MAX - 2) {
        printf("Invalid input\n");
        return 1;
    }

    cuts[0] = 0;
    cuts[c + 1] = n;

    printf("Enter cut positions:\n");

    for (int i = 1; i <= c; i++) {
        scanf("%d", &cuts[i]);

        if (cuts[i] <= 0 || cuts[i] >= n) {
            printf("Invalid cut position\n");
            return 1;
        }
    }

    qsort(cuts, c + 2, sizeof(int), compare);

    for (int i = 1; i <= c; i++) {
        if (cuts[i] == cuts[i - 1]) {
            printf("Duplicate cut position\n");
            return 1;
        }
    }

    // len is the number of gaps between endpoints
    for (int len = 2; len <= c + 1; len++) {

        for (int i = 0; i + len <= c + 1; i++) {

            int j = i + len;
            dp[i][j] = 1000000000;

            for (int k = i + 1; k < j; k++) {

                int cost = cuts[j] - cuts[i]
                         + dp[i][k]
                         + dp[k][j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum cutting cost: %d\n", dp[0][c + 1]);

    return 0;
}