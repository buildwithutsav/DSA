#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

struct Node *merge(struct Node *list1, struct Node *list2) {

    struct Node dummy;
    struct Node *temp = &dummy;

    dummy.next = NULL;

    while(list1 != NULL && list2 != NULL) {

        if(list1->data <= list2->data) {

            temp->next = list1;
            list1 = list1->next;
        }
        else {

            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if(list1 != NULL) {
        temp->next = list1;
    }
    else {
        temp->next = list2;
    }

    return dummy.next;
}

void display(struct Node *head) {

    while(head != NULL) {

        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *list1 = createNode(10);
    list1->next = createNode(30);
    list1->next->next = createNode(50);

    struct Node *list2 = createNode(20);
    list2->next = createNode(40);
    list2->next->next = createNode(60);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node *merged = merge(list1, list2);

    printf("Merged List: ");
    display(merged);

    return 0;
}