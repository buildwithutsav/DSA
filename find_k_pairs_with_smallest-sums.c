#include <stdio.h>

#define MAX 1000

typedef struct {
    int i;
    int j;
    int sum;
} Pair;

Pair heap[MAX];
int heapSize = 0;

void swap(Pair *a, Pair *b) {
    Pair temp = *a;
    *a = *b;
    *b = temp;
}

void insert(Pair p) {
    int i = heapSize++;
    heap[i] = p;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].sum <= heap[i].sum)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

Pair extractMin() {
    Pair result = heap[0];

    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize &&
            heap[left].sum < heap[smallest].sum)
            smallest = left;

        if (right < heapSize &&
            heap[right].sum < heap[smallest].sum)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }

    return result;
}

int main() {
    int n, m, k;
    int A[MAX], B[MAX];

    printf("Enter sizes of arrays and k: ");
    scanf("%d %d %d", &n, &m, &k);

    if (n < 1 || n > MAX ||
        m < 1 || m > MAX ||
        k < 0) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter first sorted array:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);

        if (i > 0 && A[i] < A[i - 1]) {
            printf("First array is not sorted\n");
            return 1;
        }
    }

    printf("Enter second sorted array:\n");

    for (int i = 0; i < m; i++) {
        scanf("%d", &B[i]);

        if (i > 0 && B[i] < B[i - 1]) {
            printf("Second array is not sorted\n");
            return 1;
        }
    }

    int initial = (k < n) ? k : n;

    for (int i = 0; i < initial; i++) {
        Pair p = {i, 0, A[i] + B[0]};
        insert(p);
    }

    int produced = 0;

    while (heapSize > 0 && produced < k) {
        Pair p = extractMin();

        printf("(%d,%d)\n", A[p.i], B[p.j]);
        produced++;

        if (p.j + 1 < m) {
            Pair next = {
                p.i,
                p.j + 1,
                A[p.i] + B[p.j + 1]
            };

            insert(next);
        }
    }

    return 0;
}