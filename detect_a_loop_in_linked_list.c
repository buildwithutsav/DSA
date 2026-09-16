#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int detectLoop(struct Node *head) {

    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {

    struct Node *first =
        (struct Node *)malloc(sizeof(struct Node));

    struct Node *second =
        (struct Node *)malloc(sizeof(struct Node));

    struct Node *third =
        (struct Node *)malloc(sizeof(struct Node));

    struct Node *fourth =
        (struct Node *)malloc(sizeof(struct Node));

    first->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;

    first->next = second;
    second->next = third;
    third->next = fourth;

    /* Creating a loop */
    fourth->next = second;

    if(detectLoop(first)) {
        printf("Loop detected\n");
    }
    else {
        printf("No loop detected\n");
    }

    return 0;
}