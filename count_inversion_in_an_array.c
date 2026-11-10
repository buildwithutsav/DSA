#include <stdio.h>

#define MAX 1000

long long merge(int arr[], int temp[], int left,
                int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    long long inversions = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];

            inversions += (mid - i + 1);
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inversions;
}

long long mergeSort(int arr[], int temp[],
                    int left, int right) {
    long long inversions = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inversions += mergeSort(arr, temp, left, mid);
        inversions += mergeSort(arr, temp, mid + 1, right);

        inversions += merge(arr, temp, left, mid, right);
    }

    return inversions;
}

int main() {
    int n, arr[MAX], temp[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long result = mergeSort(arr, temp, 0, n - 1);

    printf("Number of inversions = %lld\n", result);

    return 0;
}