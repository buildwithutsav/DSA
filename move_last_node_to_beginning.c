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

void moveLastToFront() {

    if(head == NULL || head->next == NULL) {
        return;
    }

    struct Node *secondLast = NULL;
    struct Node *last = head;

    while(last->next != NULL) {

        secondLast = last;
        last = last->next;
    }

    /* Remove last node from its old position */
    secondLast->next = NULL;

    /* Connect last node before current head */
    last->next = head;

    /* Make last node the new head */
    head = last;
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
    insertEnd(50);

    printf("Before:\n");
    display();

    moveLastToFront();

    printf("After:\n");
    display();

    return 0;
}