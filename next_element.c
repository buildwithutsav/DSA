#include <stdio.h>

#define MAX 1000

int main() {
    int n, arr[MAX];
    int stack[MAX], top = -1;
    int result[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        while (top >= 0 && arr[i] > arr[stack[top]]) {
            result[stack[top]] = arr[i];
            top--;
        }

        stack[++top] = i;
    }

    while (top >= 0) {
        result[stack[top--]] = -1;
    }

    printf("Next greater elements: ");

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    printf("\n");

    return 0;
}