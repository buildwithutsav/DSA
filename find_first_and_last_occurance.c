#include <stdio.h>

int firstOccurrence(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;
    int result = -1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {

            result = mid;
            high = mid - 1;
        }

        else if(arr[mid] < target) {

            low = mid + 1;
        }

        else {

            high = mid - 1;
        }
    }

    return result;
}

int lastOccurrence(int arr[], int n, int target) {

    int low = 0;
    int high = n - 1;
    int result = -1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] == target) {

            result = mid;
            low = mid + 1;
        }

        else if(arr[mid] < target) {

            low = mid + 1;
        }

        else {

            high = mid - 1;
        }
    }

    return result;
}

int main() {

    int arr[] = {10, 20, 20, 20, 30, 40, 50};

    int n = sizeof(arr) / sizeof(arr[0]);

    int target;

    printf("Enter target: ");
    scanf("%d", &target);

    int first = firstOccurrence(arr, n, target);
    int last = lastOccurrence(arr, n, target);

    if(first == -1) {

        printf("Element not found\n");
    }
    else {

        printf("First occurrence = %d\n", first + 1);
        printf("Last occurrence = %d\n", last + 1);
    }

    return 0;
}