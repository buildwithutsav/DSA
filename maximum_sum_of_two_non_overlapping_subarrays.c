#include <stdio.h>
#include <limits.h>

#define MAX 100005

long long prefix[MAX];

long long rangeSum(int left, int right) {
    return prefix[right] - prefix[left];
}

long long max(long long a, long long b) {
    return a > b ? a : b;
}

int main() {
    int n, L, M;

    scanf("%d", &n);

    if (n <= 0 || n >= MAX) {
        printf("Invalid input\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d %d", &L, &M);

    if (L <= 0 || M <= 0 || L + M > n) {
        printf("Invalid lengths\n");
        return 0;
    }

    prefix[0] = 0;

    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];

    long long bestL = LLONG_MIN;
    long long bestM = LLONG_MIN;
    long long answer = LLONG_MIN;

    for (int i = L + M; i <= n; i++) {

        // L-length subarray before M-length subarray.
        bestL = max(
            bestL,
            rangeSum(i - M - L, i - M)
        );

        long long currentM = rangeSum(i - M, i);

        answer = max(answer, bestL + currentM);

        // M-length subarray before L-length subarray.
        bestM = max(
            bestM,
            rangeSum(i - L - M, i - L)
        );

        long long currentL = rangeSum(i - L, i);

        answer = max(answer, bestM + currentL);
    }

    printf("%lld\n", answer);

    return 0;
}