#include <stdio.h>

#define EGGS 2
#define FLOORS 10

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int dp[EGGS + 1][FLOORS + 1] = {0};

    for (int i = 1; i <= EGGS; i++) {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }

    for (int j = 1; j <= FLOORS; j++)
        dp[1][j] = j;

    for (int i = 2; i <= EGGS; i++) {
        for (int j = 2; j <= FLOORS; j++) {

            dp[i][j] = FLOORS;

            for (int x = 1; x <= j; x++) {

                int attempts = 1 + max(
                    dp[i - 1][x - 1],
                    dp[i][j - x]
                );

                if (attempts < dp[i][j])
                    dp[i][j] = attempts;
            }
        }
    }

    printf("Minimum Attempts: %d\n",
           dp[EGGS][FLOORS]);

    return 0;
}