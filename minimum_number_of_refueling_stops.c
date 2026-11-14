#include <stdio.h>

#define MAX 1000

typedef struct {
    int position;
    int fuel;
} Station;

int heap[MAX];
int heapSize = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int value) {
    int i = heapSize++;
    heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] >= heap[i])
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

int extractMax() {
    int result = heap[0];

    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heapSize &&
            heap[left] > heap[largest])
            largest = left;

        if (right < heapSize &&
            heap[right] > heap[largest])
            largest = right;

        if (largest == i)
            break;

        swap(&heap[i], &heap[largest]);
        i = largest;
    }

    return result;
}

int main() {
    int target, fuel, n;
    Station stations[MAX];

    printf("Enter target, initial fuel and station count: ");
    scanf("%d %d %d", &target, &fuel, &n);

    if (target < 0 || fuel < 0 ||
        n < 0 || n >= MAX) {
        printf("Invalid input\n");
        return 1;
    }

    printf("Enter station position and fuel:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &stations[i].position,
              &stations[i].fuel);

        if (stations[i].position < 0 ||
            stations[i].position > target ||
            stations[i].fuel < 0) {
            printf("Invalid station\n");
            return 1;
        }

        if (i > 0 &&
            stations[i].position < stations[i - 1].position) {
            printf("Stations must be sorted by position\n");
            return 1;
        }
    }

    int currentPosition = 0;
    int stops = 0;

    for (int i = 0; i <= n; i++) {
        int nextPosition =
            (i == n) ? target : stations[i].position;

        int distance = nextPosition - currentPosition;

        while (fuel < distance) {
            if (heapSize == 0) {
                printf("Cannot reach target\n");
                return 0;
            }

            fuel += extractMax();
            stops++;
        }

        fuel -= distance;
        currentPosition = nextPosition;

        if (i < n)
            insert(stations[i].fuel);
    }

    printf("Minimum refueling stops: %d\n", stops);

    return 0;
}