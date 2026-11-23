
#include <stdio.h>

#define MAX 1000
#define INF 1000000000

int minFallingPathSum(int matrix[MAX][MAX], int n) {
    int prev[MAX];

    for (int j = 0; j < n; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++) {
        int min1 = INF;
        int min2 = INF;
        int minIndex = -1;

        for (int j = 0; j < n; j++) {
            if (prev[j] < min1) {
                min2 = min1;
                min1 = prev[j];
                minIndex = j;
            } else if (prev[j] < min2) {
                min2 = prev[j];
            }
        }

        int current[MAX];

        for (int j = 0; j < n; j++) {
            int best = (j == minIndex) ? min2 : min1;
            current[j] = matrix[i][j] + best;
        }

        for (int j = 0; j < n; j++)
            prev[j] = current[j];
    }

    int answer = prev[0];

    for (int j = 1; j < n; j++) {
        if (prev[j] < answer)
            answer = prev[j];
    }

    return answer;
}

int main() {
    int n;
    int matrix[MAX][MAX];

    printf("Enter matrix size: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX)
        return 0;

    printf("Enter matrix elements:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    }

    printf("Minimum falling path sum: %d\n",
           minFallingPathSum(matrix, n));

    return 0;
}
