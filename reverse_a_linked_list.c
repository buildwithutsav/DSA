#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertEnd(int value) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void reverse() {

    struct Node *previous = NULL;
    struct Node *current = head;
    struct Node *nextNode = NULL;

    while(current != NULL) {

        nextNode = current->next;

        current->next = previous;

        previous = current;

        current = nextNode;
    }

    head = previous;
}

void display() {

    struct Node *temp = head;

    while(temp != NULL) {

        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);

    printf("Before Reverse:\n");
    display();

    reverse();

    printf("After Reverse:\n");
    display();

    return 0;
}