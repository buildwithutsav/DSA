#include <stdio.h>

#define MAX 100

int rows, cols;
int matrix[MAX][MAX];
int dp[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int dfs(int x, int y) {

    if (dp[x][y] != 0)
        return dp[x][y];

    dp[x][y] = 1;

    for (int d = 0; d < 4; d++) {

        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx >= 0 && nx < rows &&
            ny >= 0 && ny < cols &&
            matrix[nx][ny] > matrix[x][y]) {

            int length = 1 + dfs(nx, ny);

            dp[x][y] = max(dp[x][y], length);
        }
    }

    return dp[x][y];
}

int main() {
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
        }
    }

    int answer = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            answer = max(answer, dfs(i, j));
        }
    }

    printf("Longest increasing path length: %d\n",
           answer);

    return 0;
}