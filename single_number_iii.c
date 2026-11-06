#include <stdio.h>

int main() {
    int arr[] = {2, 4, 6, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int xorAll = 0;

    for (int i = 0; i < n; i++)
        xorAll ^= arr[i];

    // Isolate the rightmost set bit
    unsigned int bit =
        (unsigned int)xorAll & (0u - (unsigned int)xorAll);

    int num1 = 0, num2 = 0;

    for (int i = 0; i < n; i++) {
        if (((unsigned int)arr[i] & bit) != 0)
            num1 ^= arr[i];
        else
            num2 ^= arr[i];
    }

    printf("Unique Elements: %d %d\n", num1, num2);

    return 0;
}