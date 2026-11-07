#include <stdio.h>

#define R 3
#define C 3

int countLessEqual(int matrix[R][C], int value) {
    int count = 0;

    for (int i = 0; i < R; i++) {
        int low = 0, high = C - 1;
        int position = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (matrix[i][mid] <= value) {
                position = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        count += position + 1;
    }

    return count;
}

int main() {
    int matrix[R][C] = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int low = matrix[0][0];
    int high = matrix[0][C - 1];

    for (int i = 1; i < R; i++) {
        if (matrix[i][0] < low)
            low = matrix[i][0];

        if (matrix[i][C - 1] > high)
            high = matrix[i][C - 1];
    }

    int required = (R * C + 1) / 2;

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (countLessEqual(matrix, mid) < required)
            low = mid + 1;
        else
            high = mid;
    }

    printf("Median: %d\n", low);

    return 0;
}