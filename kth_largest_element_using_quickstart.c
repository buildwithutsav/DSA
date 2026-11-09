#include <stdio.h>

#define MAX 1000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }

    swap(&arr[i], &arr[high]);

    return i;
}

int quickselect(int arr[], int low, int high, int target) {
    while (low <= high) {
        int p = partition(arr, low, high);

        if (p == target)
            return arr[p];

        if (p < target)
            low = p + 1;
        else
            high = p - 1;
    }

    return -1;
}

int main() {
    int n, k, arr[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid array size\n");
        return 0;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    if (k < 1 || k > n) {
        printf("Invalid k\n");
        return 0;
    }

    int target = n - k;

    int answer = quickselect(arr, 0, n - 1, target);

    printf("%dth largest element = %d\n", k, answer);

    return 0;
}