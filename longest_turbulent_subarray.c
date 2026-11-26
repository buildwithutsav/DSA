#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int up = 1, down = 1;
    int answer = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            up = down + 1;
            down = 1;
        } else if (arr[i] < arr[i - 1]) {
            down = up + 1;
            up = 1;
        } else {
            up = down = 1;
        }

        answer = max(answer, max(up, down));
    }

    printf("%d\n", answer);

    return 0;
}