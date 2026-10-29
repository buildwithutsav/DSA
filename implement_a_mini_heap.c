#include <stdio.h>

#define CAPACITY 100

int heap[CAPACITY];
int size = 0;

void insert(int value) {
    if (size == CAPACITY) {
        printf("Heap is full\n");
        return;
    }

    int i = size++;
    heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i])
            break;

        int temp = heap[parent];
        heap[parent] = heap[i];
        heap[i] = temp;

        i = parent;
    }
}

int extractMin(void) {
    int result = heap[0];
    heap[0] = heap[--size];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i)
            break;

        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;

        i = smallest;
    }

    return result;
}

int main(void) {
    insert(40);
    insert(10);
    insert(30);
    insert(5);
    insert(20);

    printf("Minimum: %d\n", extractMin());
    printf("Next minimum: %d\n", extractMin());

    return 0;
}