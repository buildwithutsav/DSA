
#include <stdio.h>

#define MAX 10000

typedef struct {
    long long data[MAX];
    int size;
} MinHeap;

void swap(long long *a, long long *b) {
    long long temp = *a;
    *a = *b;
    *b = temp;
}

void insert(MinHeap *h, long long value) {
    if (h->size == MAX)
        return;

    int i = h->size++;
    h->data[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (h->data[parent] <= h->data[i])
            break;

        swap(&h->data[parent], &h->data[i]);
        i = parent;
    }
}

long long extractMin(MinHeap *h) {
    long long result = h->data[0];

    h->data[0] = h->data[--h->size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < h->size &&
            h->data[left] < h->data[smallest])
            smallest = left;

        if (right < h->size &&
            h->data[right] < h->data[smallest])
            smallest = right;

        if (smallest == i)
            break;

        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }

    return result;
}

long long minCost(long long arr[], int n) {
    MinHeap h;
    h.size = 0;

    for (int i = 0; i < n; i++)
        insert(&h, arr[i]);

    long long totalCost = 0;

    while (h.size > 1) {
        long long first = extractMin(&h);
        long long second = extractMin(&h);

        long long cost = first + second;

        totalCost += cost;
        insert(&h, cost);
    }

    return totalCost;
}

int main() {
    int n;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of sticks\n");
        return 0;
    }

    long long arr[n];

    printf("Enter stick lengths: ");

    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);

        if (arr[i] < 0) {
            printf("Stick lengths cannot be negative\n");
            return 0;
        }
    }

    printf("Minimum connection cost: %lld\n",
           minCost(arr, n));

    return 0;
}
