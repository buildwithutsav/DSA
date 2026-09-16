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

void removeDuplicates() {

    struct Node *current = head;

    while(current != NULL && current->next != NULL) {

        if(current->data == current->next->data) {

            struct Node *duplicate = current->next;

            current->next = current->next->next;

            free(duplicate);
        }
        else {
            current = current->next;
        }
    }
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
    insertEnd(10);
    insertEnd(20);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(40);

    printf("Before: ");
    display();

    removeDuplicates();

    printf("After: ");
    display();

    return 0;
}