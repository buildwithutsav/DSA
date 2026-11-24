#include <stdio.h>

int firstPosition(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            answer = mid;
            high = mid - 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return answer;
}

int lastPosition(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int answer = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            answer = mid;
            low = mid + 1;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return answer;
}

int main() {
    int n, target;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);

    printf("%d %d\n",
           firstPosition(arr, n, target),
           lastPosition(arr, n, target));

    return 0;
}