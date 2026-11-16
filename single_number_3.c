#include <stdio.h>

#define MAX 100000

int main() {
    int n, arr[MAX];
    int xorResult = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 2 || n > MAX || n % 2 != 0) {
        printf("Invalid array size\n");
        return 1;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        xorResult ^= arr[i];
    }

    if (xorResult == 0) {
        printf("Invalid input: unique elements cannot be determined\n");
        return 1;
    }

    // Isolate the rightmost set bit
    unsigned int bit =
        (unsigned int)xorResult &
        (0u - (unsigned int)xorResult);

    int first = 0;
    int second = 0;

    for (int i = 0; i < n; i++) {
        if (((unsigned int)arr[i] & bit) != 0)
            first ^= arr[i];
        else
            second ^= arr[i];
    }

    printf("Unique elements: %d %d\n", first, second);

    return 0;
}