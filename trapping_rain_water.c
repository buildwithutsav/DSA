#include <stdio.h>

#define MAX 1000

int trap(int height[], int n) {
    int left = 0;
    int right = n - 1;

    int leftMax = 0;
    int rightMax = 0;

    int water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];

            left++;
        } else {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    return water;
}

int main() {
    int n, height[MAX];

    printf("Enter number of bars: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter heights:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &height[i]);

        if (height[i] < 0) {
            printf("Heights cannot be negative\n");
            return 0;
        }
    }

    printf("Trapped water = %d\n", trap(height, n));

    return 0;
}