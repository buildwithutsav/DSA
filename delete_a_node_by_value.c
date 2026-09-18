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

void deleteValue(int value) {

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct Node *temp = head;
    struct Node *previous = NULL;

    if(head->data == value) {

        head = head->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != value) {

        previous = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found!\n");
        return;
    }

    previous->next = temp->next;

    free(temp);
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

    printf("Before: ");
    display();

    deleteValue(30);

    printf("After: ");
    display();

    return 0;
}