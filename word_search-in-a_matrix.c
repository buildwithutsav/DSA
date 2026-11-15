#include <stdio.h>
#include <string.h>

#define MAX 100

int rows, cols;
char board[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y, char word[], int index) {
    if (word[index] == '\0')
        return 1;

    if (x < 0 || x >= rows ||
        y < 0 || y >= cols)
        return 0;

    if (board[x][y] != word[index])
        return 0;

    char original = board[x][y];

    // Mark as visited
    board[x][y] = '#';

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (dfs(nx, ny, word, index + 1)) {
            board[x][y] = original;
            return 1;
        }
    }

    // Backtracking
    board[x][y] = original;

    return 0;
}

int main() {
    char word[MAX];

    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    if (rows < 1 || rows > MAX ||
        cols < 1 || cols > MAX) {
        printf("Invalid dimensions\n");
        return 1;
    }

    printf("Enter matrix characters:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    printf("Enter word: ");
    scanf("%99s", word);

    int found = 0;

    for (int i = 0; i < rows && !found; i++) {
        for (int j = 0; j < cols && !found; j++) {
            if (dfs(i, j, word, 0))
                found = 1;
        }
    }

    if (found)
        printf("Word found\n");
    else
        printf("Word not found\n");

    return 0;
}