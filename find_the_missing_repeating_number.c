
#include <stdio.h>

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    long long sum = 0;
    long long squareSum = 0;

    for (int i = 1; i <= n; i++) {
        long long x;

        printf("Enter element %d: ", i);
        scanf("%lld", &x);

        sum += x;
        squareSum += x * x;
    }

    long long expectedSum = (long long)n * (n + 1) / 2;

    long long expectedSquareSum =
        (long long)n * (n + 1) * (2LL * n + 1) / 6;

    long long difference = sum - expectedSum;
    long long squareDifference =
        squareSum - expectedSquareSum;

    if (difference == 0 || squareDifference % difference != 0) {
        printf("Input does not satisfy the required condition\n");
        return 0;
    }

    long long sumRM = squareDifference / difference;

    if ((sumRM + difference) % 2 != 0 ||
        (sumRM - difference) % 2 != 0) {
        printf("Invalid input\n");
        return 0;
    }

    long long repeating = (sumRM + difference) / 2;
    long long missing = (sumRM - difference) / 2;

    printf("Missing number: %lld\n", missing);
    printf("Repeating number: %lld\n", repeating);

    return 0;
}
