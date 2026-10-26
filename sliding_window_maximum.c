#include <stdio.h>

void slidingWindowMax(int arr[], int n, int k) {
    if (k <= 0 || k > n) {
        printf("Invalid window size\n");
        return;
    }

    int deque[n];
    int front = 0, rear = -1;

    for (int i = 0; i < n; i++) {
        while (front <= rear && deque[front] <= i - k)
            front++;

        while (front <= rear &&
               arr[deque[rear]] <= arr[i])
            rear--;

        deque[++rear] = i;

        if (i >= k - 1)
            printf("%d ", arr[deque[front]]);
    }

    printf("\n");
}

int main(void) {
    int arr[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    slidingWindowMax(arr, n, 3);
    return 0;
}