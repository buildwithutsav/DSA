
#include <stdio.h>

#define MAX_VALUE 1000
#define MAX_OPS 10000

typedef struct {
    int data[MAX_OPS];
    int top;
} Stack;

typedef struct {
    int frequency[MAX_VALUE];
    Stack groups[MAX_OPS + 1];
    int maxFrequency;
} FreqStack;

void pushStack(Stack *s, int value) {
    s->data[++s->top] = value;
}

int popStack(Stack *s) {
    return s->data[s->top--];
}

void initialize(FreqStack *fs) {
    fs->maxFrequency = 0;

    for (int i = 0; i < MAX_VALUE; i++)
        fs->frequency[i] = 0;

    for (int i = 0; i <= MAX_OPS; i++)
        fs->groups[i].top = -1;
}

void push(FreqStack *fs, int value) {
    if (value < 0 || value >= MAX_VALUE)
        return;

    int freq = ++fs->frequency[value];

    pushStack(&fs->groups[freq], value);

    if (freq > fs->maxFrequency)
        fs->maxFrequency = freq;
}

int pop(FreqStack *fs) {
    if (fs->maxFrequency == 0)
        return -1;

    int value = popStack(&fs->groups[fs->maxFrequency]);

    fs->frequency[value]--;

    if (fs->groups[fs->maxFrequency].top == -1)
        fs->maxFrequency--;

    return value;
}

int main() {
    FreqStack fs;
    initialize(&fs);

    push(&fs, 5);
    push(&fs, 7);
    push(&fs, 5);
    push(&fs, 7);
    push(&fs, 4);
    push(&fs, 5);

    printf("Pop: %d\n", pop(&fs));
    printf("Pop: %d\n", pop(&fs));
    printf("Pop: %d\n", pop(&fs));
    printf("Pop: %d\n", pop(&fs));

    return 0;
}
