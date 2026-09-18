#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void secondLargest() {

    if(head == NULL || head->next == NULL) {
        printf("Not enough elements!\n");
        return;
    }

    int largest = INT_MIN;
    int second = INT_MIN;

    struct Node *temp = head;

    while(temp != NULL) {

        if(temp->data > largest) {

            second = largest;
            largest = temp->data;
        }

        else if(temp->data > second &&
                temp->data != largest) {

            second = temp->data;
        }

        temp = temp->next;
    }

    if(second == INT_MIN) {
        printf("No second largest distinct element.\n");
    }
    else {
        printf("Largest = %d\n", largest);
        printf("Second Largest = %d\n", second);
    }
}

int main() {

    insertEnd(10);
    insertEnd(50);
    insertEnd(30);
    insertEnd(80);
    insertEnd(60);

    secondLargest();

    return 0;
}