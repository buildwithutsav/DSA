#include <stdio.h>

#define MAX 100

int min3(int a, int b, int c) {
    int min = a;

    if (b < min) min = b;
    if (c < min) min = c;

    return min;
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    int dp[MAX][MAX] = {0};

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

    int maxSide = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (matrix[i][j] == 1) {

                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min3(
                        dp[i - 1][j],
                        dp[i][j - 1],
                        dp[i - 1][j - 1]
                    );
                }

                if (dp[i][j] > maxSide)
                    maxSide = dp[i][j];
            }
        }
    }

    printf("Maximum square area: %d\n",
           maxSide * maxSide);

    return 0;
}