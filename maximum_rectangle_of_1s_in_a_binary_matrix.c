#include <stdio.h>

#define MAX 100

int largestHistogram(int height[], int n) {
    int stack[MAX + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int current = (i == n) ? 0 : height[i];

        while (top != -1 &&
               height[stack[top]] > current) {

            int h = height[stack[top--]];

            int width;

            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            int area = h * width;

            if (area > maxArea)
                maxArea = area;
        }

        stack[++top] = i;
    }

    return maxArea;
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    int height[MAX] = {0};

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > MAX ||
        cols < 1 || cols > MAX) {
        printf("Invalid dimensions\n");
        return 1;
    }

    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);

            if (matrix[i][j] != 0 &&
                matrix[i][j] != 1) {
                printf("Invalid matrix element\n");
                return 1;
            }
        }
    }

    int maxArea = 0;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }

        int area = largestHistogram(height, cols);

        if (area > maxArea)
            maxArea = area;
    }

    printf("Maximum rectangle area: %d\n", maxArea);

    return 0;
}