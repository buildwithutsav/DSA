#include <stdio.h>

#define MAX 1000

int main() {
    int n, arr[MAX];
    int lis[MAX], lds[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++)
        lis[i] = lds[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] &&
                lis[j] + 1 > lis[i]) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i] &&
                lds[j] + 1 > lds[i]) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < n; i++) {
        int length = lis[i] + lds[i] - 1;

        if (length > answer)
            answer = length;
    }

    printf("Longest bitonic subsequence = %d\n", answer);

    return 0;
}