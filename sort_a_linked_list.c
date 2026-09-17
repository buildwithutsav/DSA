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

void sortList() {

    struct Node *i;
    struct Node *j;

    int temp;

    for(i = head; i != NULL; i = i->next) {

        for(j = i->next; j != NULL; j = j->next) {

            if(i->data > j->data) {

                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
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

    insertEnd(40);
    insertEnd(10);
    insertEnd(30);
    insertEnd(20);

    printf("Before Sorting:\n");
    display();

    sortList();

    printf("After Sorting:\n");
    display();

    return 0;
}