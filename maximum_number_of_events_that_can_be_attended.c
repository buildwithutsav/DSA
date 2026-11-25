#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct {
    int start;
    int end;
} Event;

int heap[MAX];
int heapSize = 0;

int compare(const void *a, const void *b) {
    Event *x = (Event *)a;
    Event *y = (Event *)b;

    if (x->start < y->start) return -1;
    if (x->start > y->start) return 1;

    return 0;
}

void push(int value) {
    int i = ++heapSize;

    while (i > 1 && heap[i / 2] > value) {
        heap[i] = heap[i / 2];
        i /= 2;
    }

    heap[i] = value;
}

int pop() {
    int result = heap[1];
    int last = heap[heapSize--];

    int i = 1;

    while (2 * i <= heapSize) {
        int child = 2 * i;

        if (child + 1 <= heapSize &&
            heap[child + 1] < heap[child]) {
            child++;
        }

        if (last <= heap[child]) {
            break;
        }

        heap[i] = heap[child];
        i = child;
    }

    if (heapSize > 0) {
        heap[i] = last;
    }

    return result;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n < 0 || n >= MAX) {
        printf("Invalid input\n");
        return 0;
    }

    Event events[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &events[i].start,
              &events[i].end);

        if (events[i].start > events[i].end) {
            printf("Invalid event\n");
            return 0;
        }
    }

    qsort(events, n, sizeof(Event), compare);

    int i = 0;
    int attended = 0;

    while (i < n || heapSize > 0) {

        // Jump to the next event if heap is empty.
        if (heapSize == 0 && i < n) {
            // Start at the next event's start day.
            int day = events[i].start;

            while (i < n && events[i].start <= day) {
                push(events[i].end);
                i++;
            }

            // Remove expired events.
            while (heapSize > 0 && heap[1] < day) {
                pop();
            }

            if (heapSize > 0) {
                pop();
                attended++;
            }

            // Continue from the following day.
            // The next iteration derives the day from
            // the next event only if the heap is empty.
            // A separate calendar counter is used below.
            int nextDay = day + 1;

            while (heapSize > 0 && heap[1] < nextDay) {
                pop();
            }

            // Continue through the calendar.
            while (heapSize > 0 || i < n) {

                if (heapSize == 0) {
                    break;
                }

                while (i < n && events[i].start <= nextDay) {
                    push(events[i].end);
                    i++;
                }

                while (heapSize > 0 && heap[1] < nextDay) {
                    pop();
                }

                if (heapSize > 0) {
                    pop();
                    attended++;
                }

                nextDay++;
            }
        }
    }

    printf("%d\n", attended);

    return 0;
}