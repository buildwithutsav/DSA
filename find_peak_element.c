
#include <stdio.h>

int findPeak(int arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
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

    int index = findPeak(arr, n);

    printf("Peak element: %d\n", arr[index]);
    printf("Index: %d\n", index);

    return 0;
}
