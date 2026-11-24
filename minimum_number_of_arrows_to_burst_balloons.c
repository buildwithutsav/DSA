#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Balloon;

int compare(const void *a, const void *b) {
    Balloon *x = (Balloon *)a;
    Balloon *y = (Balloon *)b;

    if (x->end < y->end) return -1;
    if (x->end > y->end) return 1;

    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    Balloon balloons[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &balloons[i].start,
              &balloons[i].end);
    }

    if (n == 0) {
        printf("0\n");
        return 0;
    }

    qsort(balloons, n, sizeof(Balloon), compare);

    int arrows = 1;
    int position = balloons[0].end;

    for (int i = 1; i < n; i++) {
        if (balloons[i].start > position) {
            arrows++;
            position = balloons[i].end;
        }
    }

    printf("%d\n", arrows);

    return 0;
}