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

void deleteMiddle() {

    if(head == NULL) {
        return;
    }

    if(head->next == NULL) {

        free(head);
        head = NULL;

        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;
    struct Node *previous = NULL;

    while(fast != NULL && fast->next != NULL) {

        previous = slow;

        slow = slow->next;
        fast = fast->next->next;
    }

    previous->next = slow->next;

    free(slow);
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

    deleteMiddle();

    printf("After:\n");
    display();

    return 0;
}