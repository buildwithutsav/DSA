
#include <stdio.h>

int minJumps(int arr[], int n) {
    if (n <= 1)
        return 0;

    if (arr[0] == 0)
        return -1;

    int jumps = 0;
    int currentEnd = 0;
    int maxReach = 0;

    for (int i = 0; i < n - 1; i++) {
        if (i > maxReach)
            return -1;

        if (i + arr[i] > maxReach)
            maxReach = i + arr[i];

        if (i == currentEnd) {
            jumps++;
            currentEnd = maxReach;

            if (currentEnd >= n - 1)
                return jumps;

            if (currentEnd == i)
                return -1;
        }
    }

    return -1;
}

int main() {
    int n;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    int arr[n];

    printf("Enter array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Minimum jumps: %d\n", minJumps(arr, n));

    return 0;
}
