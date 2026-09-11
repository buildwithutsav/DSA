#include <stdio.h>

#define SIZE 100

int q1[SIZE];
int q2[SIZE];

int size1 = 0;
int size2 = 0;

void push(int value) {

    q2[size2++] = value;

    for(int i = 0; i < size1; i++) {

        q2[size2++] = q1[i];
    }

    size1 = 0;

    for(int i = 0; i < size2; i++) {

        q1[size1++] = q2[i];
    }

    size2 = 0;

    printf("%d pushed.\n", value);
}

void pop() {

    if(size1 == 0) {

        printf("Stack is Empty!\n");
        return;
    }

    printf("%d popped.\n", q1[0]);

    for(int i = 0; i < size1 - 1; i++) {

        q1[i] = q1[i + 1];
    }

    size1--;
}

void peek() {

    if(size1 == 0) {

        printf("Stack is Empty!\n");
    }
    else {

        printf("Top = %d\n", q1[0]);
    }
}

int main() {

    push(10);
    push(20);
    push(30);

    peek();

    pop();

    peek();

    return 0;
}