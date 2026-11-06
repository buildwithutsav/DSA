#include <stdio.h>

#define MAX 100

int stack[MAX];
int minStack[MAX];

int top = -1;
int minTop = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = value;

    if (minTop == -1 || value <= minStack[minTop])
        minStack[++minTop] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }

    int value = stack[top--];

    if (value == minStack[minTop])
        minTop--;
}

int getTop() {
    if (top == -1)
        return -1;

    return stack[top];
}

int getMin() {
    if (minTop == -1)
        return -1;

    return minStack[minTop];
}

int main() {
    push(5);
    push(3);
    push(7);
    push(2);

    printf("Top Element: %d\n", getTop());
    printf("Minimum Element: %d\n", getMin());

    pop();

    printf("After Pop:\n");
    printf("Top Element: %d\n", getTop());
    printf("Minimum Element: %d\n", getMin());

    return 0;
}