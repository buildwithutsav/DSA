
#include <stdio.h>

#define MAX 1000

int countLessEqual(int matrix[MAX][MAX],
                   int n, int value) {
    int row = n - 1;
    int col = 0;
    int count = 0;

    while (row >= 0 && col < n) {
        if (matrix[row][col] <= value) {
            count += row + 1;
            col++;
        } else {
            row--;
        }
    }

    return count;
}

int kthSmallest(int matrix[MAX][MAX], int n, int k) {
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];

    while (low < high) {
        int mid = low + (high - low) / 2;

        int count = countLessEqual(matrix, n, mid);

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    int n, k;
    int matrix[MAX][MAX];

    printf("Enter matrix size and k: ");
    scanf("%d %d", &n, &k);

    if (n <= 0 || n > MAX ||
        k < 1 || (long long)k > (long long)n * n) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter sorted matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            if (i > 0 && matrix[i][j] < matrix[i - 1][j]) {
                printf("Columns are not sorted\n");
                return 0;
            }

            if (j > 0 && matrix[i][j] < matrix[i][j - 1]) {
                printf("Rows are not sorted\n");
                return 0;
            }
        }
    }

    printf("Kth smallest element: %d\n",
           kthSmallest(matrix, n, k));

    return 0;
}
