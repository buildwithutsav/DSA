
#include <stdio.h>

#define MAX 10000

int min(int a, int b) {
    return a < b ? a : b;
}

int minCostTickets(int days[], int n, int costs[]) {
    int dp[MAX + 1];

    dp[n] = 0;

    for (int i = n - 1; i >= 0; i--) {
        int j;

        // 1-day pass
        j = i;
        while (j < n && days[j] < days[i] + 1)
            j++;

        int cost1 = costs[0] + dp[j];

        // 7-day pass
        j = i;
        while (j < n && days[j] < days[i] + 7)
            j++;

        int cost7 = costs[1] + dp[j];

        // 30-day pass
        j = i;
        while (j < n && days[j] < days[i] + 30)
            j++;

        int cost30 = costs[2] + dp[j];

        dp[i] = min(cost1, min(cost7, cost30));
    }

    return dp[0];
}

int main() {
    int n;
    int days[MAX];
    int costs[3];

    printf("Enter number of travel days: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of travel days\n");
        return 0;
    }

    printf("Enter travel days in increasing order: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &days[i]);

        if (days[i] < 1 ||
            (i > 0 && days[i] <= days[i - 1])) {
            printf("Invalid travel days\n");
            return 0;
        }
    }

    printf("Enter costs of 1-day, 7-day and 30-day passes: ");

    for (int i = 0; i < 3; i++) {
        scanf("%d", &costs[i]);

        if (costs[i] < 0) {
            printf("Invalid ticket cost\n");
            return 0;
        }
    }

    printf("Minimum cost: %d\n",
           minCostTickets(days, n, costs));

    return 0;
}
