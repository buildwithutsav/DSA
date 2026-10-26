#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int compare(const void *a, const void *b) {
    Interval *x = (Interval *)a;
    Interval *y = (Interval *)b;

    if (x->start < y->start) return -1;
    if (x->start > y->start) return 1;
    return 0;
}

int main(void) {
    Interval arr[] = {{1,3}, {2,6}, {8,10}, {9,12}};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(Interval), compare);

    int start = arr[0].start;
    int end = arr[0].end;

    printf("Merged intervals: ");

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= end) {
            if (arr[i].end > end)
                end = arr[i].end;
        } else {
            printf("[%d,%d] ", start, end);
            start = arr[i].start;
            end = arr[i].end;
        }
    }

    printf("[%d,%d]\n", start, end);
    return 0;
}