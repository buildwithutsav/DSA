#include <stdio.h>

#define N 6

int largestRectangle(int h[]) {
    int stack[N + 1];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= N; i++) {

        int currentHeight = (i == N) ? 0 : h[i];

        while (top != -1 &&
               h[stack[top]] > currentHeight) {

            int height = h[stack[top--]];

            int width;

            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            int area = height * width;

            if (area > maxArea)
                maxArea = area;
        }

        if (i < N)
            stack[++top] = i;
    }

    return maxArea;
}

int main() {
    int heights[N] = {2, 1, 5, 6, 2, 3};

    printf("Largest Rectangle Area: %d\n",
           largestRectangle(heights));

    return 0;
}