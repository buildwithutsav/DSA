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

void insertPosition(int value, int position) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if(position == 1) {

        newNode->next = head;
        head = newNode;

        return;
    }

    struct Node *temp = head;

    int i;

    for(i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {

        printf("Invalid position!\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
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
    insertEnd(40);

    insertPosition(30, 3);

    display();

    return 0;
}