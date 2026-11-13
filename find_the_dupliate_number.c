#include <stdio.h>

#define MAX 100005

int findDuplicate(int nums[], int n) {
    int slow = nums[0];
    int fast = nums[0];

    // Phase 1: Find intersection point
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Phase 2: Find cycle entrance
    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

int main() {
    int n, nums[MAX];

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 1 || n >= MAX) {
        printf("Invalid size\n");
        return 1;
    }

    printf("Enter %d elements:\n", n + 1);

    for (int i = 0; i <= n; i++) {
        scanf("%d", &nums[i]);

        if (nums[i] < 1 || nums[i] > n) {
            printf("Invalid element\n");
            return 1;
        }
    }

    printf("Duplicate number: %d\n",
           findDuplicate(nums, n + 1));

    return 0;
}