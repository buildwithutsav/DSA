#include <stdio.h>

#define MAX 1000

int main() {
    int n, arr[MAX], dp[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid array size\n");
        return 1;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int answer = arr[0];

    for (int i = 0; i < n; i++) {
        dp[i] = arr[i];

        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] &&
                dp[j] + arr[i] > dp[i]) {

                dp[i] = dp[j] + arr[i];
            }
        }

        if (dp[i] > answer)
            answer = dp[i];
    }

    printf("Maximum increasing subsequence sum: %d\n",
           answer);

    return 0;
}