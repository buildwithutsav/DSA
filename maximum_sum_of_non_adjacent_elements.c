#include <stdio.h>

#define N 5

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int arr[N] = {2, 7, 9, 3, 1};

    int prev2 = 0;
    int prev1 = 0;

    for (int i = 0; i < N; i++) {
        int take = arr[i] + prev2;
        int skip = prev1;

        int current = max(take, skip);

        prev2 = prev1;
        prev1 = current;
    }

    printf("Maximum Non-Adjacent Sum: %d\n", prev1);

    return 0;
}