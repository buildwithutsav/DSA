#include <stdio.h>

#define N 6

int bit[N + 1];

void update(int index, int value) {
    while (index <= N) {
        bit[index] += value;
        index += index & -index;
    }
}

int prefixSum(int index) {
    int sum = 0;

    while (index > 0) {
        sum += bit[index];
        index -= index & -index;
    }

    return sum;
}

int rangeSum(int left, int right) {
    return prefixSum(right) - prefixSum(left - 1);
}

int main() {
    int arr[N] = {2, 4, 1, 7, 3, 5};

    for (int i = 0; i < N; i++)
        update(i + 1, arr[i]);

    printf("Prefix Sum (1 to 4): %d\n", prefixSum(4));

    printf("Range Sum (2 to 5): %d\n", rangeSum(2, 5));

    // Increase element at index 3 by 5
    arr[2] += 5;
    update(3, 5);

    printf("Updated Range Sum (2 to 5): %d\n",
           rangeSum(2, 5));

    return 0;
}