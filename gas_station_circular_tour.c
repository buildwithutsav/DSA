#include <stdio.h>

#define MAX 100000

int main() {
    int n;
    int gas[MAX], cost[MAX];

    printf("Enter number of stations: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of stations\n");
        return 1;
    }

    printf("Enter gas amounts:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &gas[i]);

        if (gas[i] < 0) {
            printf("Invalid gas amount\n");
            return 1;
        }
    }

    printf("Enter travel costs:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &cost[i]);

        if (cost[i] < 0) {
            printf("Invalid travel cost\n");
            return 1;
        }
    }

    long long total = 0;
    long long current = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
        long long difference =
            (long long)gas[i] - cost[i];

        total += difference;
        current += difference;

        if (current < 0) {
            start = i + 1;
            current = 0;
        }
    }

    if (total < 0 || start == n)
        printf("Starting station: -1\n");
    else
        printf("Starting station: %d\n", start);

    return 0;
}