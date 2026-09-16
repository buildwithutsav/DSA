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

void findNthFromEnd(int n) {

    struct Node *first = head;
    struct Node *second = head;

    int i;

    for(i = 0; i < n; i++) {

        if(first == NULL) {
            printf("Invalid value of N!\n");
            return;
        }

        first = first->next;
    }

    while(first != NULL) {

        first = first->next;
        second = second->next;
    }

    printf("%dth node from end = %d\n", n, second->data);
}

int main() {

    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertEnd(40);
    insertEnd(50);

    findNthFromEnd(2);

    return 0;
}