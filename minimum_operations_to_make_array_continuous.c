#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int n;
    int arr[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    // Remove duplicates
    int m = 0;

    for (int i = 0; i < n; i++) {
        if (m == 0 || arr[i] != arr[m - 1])
            arr[m++] = arr[i];
    }

    int maxWindow = 0;
    int j = 0;

    for (int i = 0; i < m; i++) {

        while (j < m &&
               (long long)arr[j] - arr[i] <= n - 1) {
            j++;
        }

        int windowSize = j - i;

        if (windowSize > maxWindow)
            maxWindow = windowSize;
    }

    printf("Minimum replacements: %d\n",
           n - maxWindow);

    return 0;
}