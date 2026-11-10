#include <stdio.h>

#define MAX 1000

typedef struct {
    int data[MAX];
    int size;
    int isMax;
} Heap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int higherPriority(Heap *h, int a, int b) {
    if (h->isMax)
        return a > b;

    return a < b;
}

void insertHeap(Heap *h, int value) {
    int i = h->size++;

    h->data[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (!higherPriority(h, h->data[i],
                            h->data[parent]))
            break;

        swap(&h->data[i], &h->data[parent]);
        i = parent;
    }
}

int removeRoot(Heap *h) {
    int result = h->data[0];

    h->data[0] = h->data[--h->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int best = i;

        if (left < h->size &&
            higherPriority(h, h->data[left],
                           h->data[best]))
            best = left;

        if (right < h->size &&
            higherPriority(h, h->data[right],
                           h->data[best]))
            best = right;

        if (best == i)
            break;

        swap(&h->data[i], &h->data[best]);
        i = best;
    }

    return result;
}

int main() {
    int n, x;

    Heap lower = {{0}, 0, 1};
    Heap upper = {{0}, 0, 0};

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (lower.size == 0 || x <= lower.data[0])
            insertHeap(&lower, x);
        else
            insertHeap(&upper, x);

        if (lower.size > upper.size + 1)
            insertHeap(&upper, removeRoot(&lower));

        else if (upper.size > lower.size)
            insertHeap(&lower, removeRoot(&upper));

        double median;

        if (lower.size == upper.size) {
            median = ((double)lower.data[0] +
                      upper.data[0]) / 2.0;
        } else {
            median = lower.data[0];
        }

        printf("Median after insertion: %.2f\n", median);
    }

    return 0;
}