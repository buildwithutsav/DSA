#include <stdio.h>

#define N 6
#define TARGET 9

int main() {
    int arr[N] = {3, 34, 4, 12, 5, 2};

    int dp[TARGET + 1] = {0};

    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        for (int j = TARGET; j >= arr[i]; j--) {

            if (dp[j - arr[i]])
                dp[j] = 1;
        }
    }

    if (dp[TARGET])
        printf("Subset with target sum exists.");
    else
        printf("Subset with target sum does not exist.");

    return 0;
}