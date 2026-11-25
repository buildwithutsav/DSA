#include <stdio.h>

#define MAX 100005

int main() {
    int n, k;

    scanf("%d", &n);

    if (n < 0 || n >= MAX) {
        printf("Invalid input\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);

    if (k < 0 || k > n) {
        printf("0\n");
        return 0;
    }

    long long freq[MAX] = {0};

    int sum = 0;
    long long answer = 0;

    // Empty prefix.
    freq[0] = 1;

    for (int i = 0; i < n; i++) {

        if (arr[i] % 2 != 0) {
            sum++;
        }

        if (sum >= k) {
            answer += freq[sum - k];
        }

        freq[sum]++;
    }

    printf("%lld\n", answer);

    return 0;
}