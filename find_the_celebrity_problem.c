#include <stdio.h>

#define N 4

int knows[N][N] = {
    {0, 1, 1, 1},
    {0, 0, 1, 1},
    {0, 0, 0, 0},
    {0, 1, 1, 0}
};

int findCelebrity() {
    int candidate = 0;

    // Eliminate candidates
    for (int i = 1; i < N; i++) {
        if (knows[candidate][i])
            candidate = i;
    }

    // Verify candidate
    for (int i = 0; i < N; i++) {
        if (i == candidate)
            continue;

        if (knows[candidate][i] ||
            !knows[i][candidate])
            return -1;
    }

    return candidate;
}

int main() {
    int celebrity = findCelebrity();

    if (celebrity == -1)
        printf("No celebrity found.\n");
    else
        printf("Celebrity is person %d\n", celebrity);

    return 0;
}