#include <stdio.h>
#include <limits.h>

#define MAX 100

int kadane(int arr[], int n) {
    int current = arr[0];
    int best = arr[0];

    for (int i = 1; i < n; i++) {
        if (current + arr[i] < arr[i])
            current = arr[i];
        else
            current += arr[i];

        if (current > best)
            best = current;
    }

    return best;
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX];
    int temp[MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > MAX ||
        cols < 1 || cols > MAX) {
        printf("Invalid matrix size\n");
        return 0;
    }

    printf("Enter matrix elements:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            scanf("%d", &matrix[i][j]);
    }

    int maxSum = INT_MIN;

    for (int left = 0; left < cols; left++) {
        for (int i = 0; i < rows; i++)
            temp[i] = 0;

        for (int right = left; right < cols; right++) {

            for (int i = 0; i < rows; i++)
                temp[i] += matrix[i][right];

            int current = kadane(temp, rows);

            if (current > maxSum)
                maxSum = current;
        }
    }

    printf("Maximum sum rectangle = %d\n", maxSum);

    return 0;
}