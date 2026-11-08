#include <stdio.h>

#define MAX 100

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void enqueue(int value) {
    if (top1 == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }

    stack1[++top1] = value;
}

void transfer() {
    if (top2 == -1) {
        while (top1 != -1) {
            stack2[++top2] = stack1[top1--];
        }
    }
}

int dequeue() {
    transfer();

    if (top2 == -1) {
        printf("Queue Underflow\n");
        return -1;
    }

    return stack2[top2--];
}

int front() {
    transfer();

    if (top2 == -1)
        return -1;

    return stack2[top2];
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Front Element: %d\n", front());

    printf("Dequeued: %d\n", dequeue());

    printf("Front After Dequeue: %d\n", front());

    enqueue(40);

    printf("Dequeued: %d\n", dequeue());
    printf("Dequeued: %d\n", dequeue());

    return 0;
}