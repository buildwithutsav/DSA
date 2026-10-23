
#include <stdio.h>

int longestConsecutive(int a[], int n) {
    int best = 0;

    for (int i = 0; i < n; i++) {
        int isStart = 1;

        for (int j = 0; j < n; j++) {
            if ((long long)a[j] == (long long)a[i] - 1) {
                isStart = 0;
                break;
            }
        }

        if (!isStart)
            continue;

        int length = 1;
        long long next = (long long)a[i] + 1;

        while (next <= 2147483647LL) {
            int found = 0;

            for (int j = 0; j < n; j++) {
                if (a[j] == next) {
                    found = 1;
                    break;
                }
            }

            if (!found)
                break;

            length++;
            next++;
        }

        if (length > best)
            best = length;
    }

    return best;
}

int main(void) {
    int a[] = {100, 4, 200, 1, 3, 2};
    int n = sizeof(a) / sizeof(a[0]);

    printf("Longest consecutive sequence: %d\n",
           longestConsecutive(a, n));

    return 0;
}
