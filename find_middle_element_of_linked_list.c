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

void findMiddle() {

    if(head == NULL) {

        printf("List is empty!\n");
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    while(fast != NULL && fast->next != NULL) {

        slow = slow->next;

        fast = fast->next->next;
    }

    printf("Middle Element = %d\n", slow->data);
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    findMiddle();

    return 0;
}