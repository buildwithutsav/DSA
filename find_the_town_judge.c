
#include <stdio.h>

#define MAX 1000

int findJudge(int n, int trust[][2], int m) {
    int trustGiven[MAX + 1] = {0};
    int trustReceived[MAX + 1] = {0};

    for (int i = 0; i < m; i++) {
        int a = trust[i][0];
        int b = trust[i][1];

        trustGiven[a]++;
        trustReceived[b]++;
    }

    for (int i = 1; i <= n; i++) {
        if (trustGiven[i] == 0 &&
            trustReceived[i] == n - 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    int n, m;

    printf("Enter number of people and trust relationships: ");
    scanf("%d %d", &n, &m);

    if (n < 1 || n > MAX || m < 0 ||
        m > n * (n - 1)) {
        printf("Invalid input\n");
        return 0;
    }

    int trust[m > 0 ? m : 1][2];

    printf("Enter trust relationships (a b):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &trust[i][0], &trust[i][1]);

        int a = trust[i][0];
        int b = trust[i][1];

        if (a < 1 || a > n || b < 1 || b > n || a == b) {
            printf("Invalid relationship\n");
            return 0;
        }
    }

    printf("Town judge: %d\n", findJudge(n, trust, m));

    return 0;
}
