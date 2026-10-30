#include <stdio.h>

#define N 5

int arr[N] = {1, 3, 5, 7, 9};
int tree[4 * N];

void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return 0;

    if (l <= start && end <= r)
        return tree[node];

    int mid = (start + end) / 2;

    return query(2 * node, start, mid, l, r) +
           query(2 * node + 1, mid + 1, end, l, r);
}

void update(int node, int start, int end, int index, int value) {
    if (start == end) {
        arr[index] = value;
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;

    if (index <= mid)
        update(2 * node, start, mid, index, value);
    else
        update(2 * node + 1, mid + 1, end, index, value);

    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main(void) {
    build(1, 0, N - 1);

    printf("Sum from index 1 to 3: %d\n",
           query(1, 0, N - 1, 1, 3));

    update(1, 0, N - 1, 2, 10);

    printf("After update: %d\n",
           query(1, 0, N - 1, 1, 3));

    return 0;
}