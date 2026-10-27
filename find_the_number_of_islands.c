#include <stdio.h>

#define ROWS 4
#define COLS 5

char grid[ROWS][COLS] = {
    {'1','1','0','0','0'},
    {'1','1','0','0','1'},
    {'0','0','1','0','1'},
    {'0','0','0','1','1'}
};

void dfs(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
        grid[r][c] != '1')
        return;

    grid[r][c] = '0';

    dfs(r - 1, c);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r, c + 1);
}

int main(void) {
    int islands = 0;

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (grid[r][c] == '1') {
                islands++;
                dfs(r, c);
            }
        }
    }

    printf("Number of islands: %d\n", islands);
    return 0;
}