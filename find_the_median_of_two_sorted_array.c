#include <stdio.h>

double findMedian(int a[], int n, int b[], int m) {
    if (n > m)
        return findMedian(b, m, a, n);

    int low = 0, high = n;
    int half = (n + m + 1) / 2;

    while (low <= high) {
        int i = (low + high) / 2;
        int j = half - i;

        int leftA = (i == 0) ? -2147483647 : a[i - 1];
        int rightA = (i == n) ? 2147483647 : a[i];

        int leftB = (j == 0) ? -2147483647 : b[j - 1];
        int rightB = (j == m) ? 2147483647 : b[j];

        if (leftA <= rightB && leftB <= rightA) {
            int leftMax = leftA > leftB ? leftA : leftB;

            if ((n + m) % 2)
                return leftMax;

            int rightMin = rightA < rightB ? rightA : rightB;

            return ((double)leftMax + rightMin) / 2.0;
        }

        if (leftA > rightB)
            high = i - 1;
        else
            low = i + 1;
    }

    return -1;
}

int main(void) {
    int a[] = {1, 3};
    int b[] = {2};

    printf("Median: %.2f\n",
           findMedian(a, 2, b, 1));

    return 0;
}