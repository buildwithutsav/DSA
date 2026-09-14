#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value) {

    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = head;

    head = newNode;
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

    insertBeginning(30);
    insertBeginning(20);
    insertBeginning(10);

    display();

    insertBeginning(5);

    display();

    return 0;
}