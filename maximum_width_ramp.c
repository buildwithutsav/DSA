
#include <stdio.h>

int maxWidthRamp(int arr[], int n) {
    int stack[n];
    int top = -1;

    // Build decreasing prefix minimum indices
    for (int i = 0; i < n; i++) {
        if (top == -1 || arr[i] < arr[stack[top]]) {
            stack[++top] = i;
        }
    }

    int maxWidth = 0;

    // Traverse from right to left
    for (int j = n - 1; j >= 0; j--) {
        while (top >= 0 &&
               arr[j] >= arr[stack[top]]) {

            int width = j - stack[top];

            if (width > maxWidth)
                maxWidth = width;

            top--;
        }
    }

    return maxWidth;
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

    printf("Maximum width ramp: %d\n",
           maxWidthRamp(arr, n));

    return 0;
}
