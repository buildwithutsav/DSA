
#include <stdio.h>

double median(int a[], int n, int b[], int m) {
    int i = 0, j = 0;
    int prev = 0, curr = 0;
    int total = n + m;

    for (int count = 0; count <= total / 2; count++) {
        prev = curr;

        if (i < n && (j >= m || a[i] <= b[j]))
            curr = a[i++];
        else
            curr = b[j++];
    }

    if (total % 2 == 0)
        return ((double)prev + curr) / 2.0;

    return curr;
}

int main(void) {
    int a[] = {1, 3};
    int b[] = {2, 4};

    printf("Median: %.2f\n",
           median(a, 2, b, 2));

    return 0;
}
