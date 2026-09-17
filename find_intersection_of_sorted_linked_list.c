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

void insertEnd(struct Node **head, int value) {

    struct Node *newNode = createNode(value);

    if(*head == NULL) {

        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

struct Node *findIntersection(
    struct Node *list1,
    struct Node *list2) {

    struct Node *result = NULL;

    while(list1 != NULL && list2 != NULL) {

        if(list1->data == list2->data) {

            insertEnd(&result, list1->data);

            list1 = list1->next;
            list2 = list2->next;
        }

        else if(list1->data < list2->data) {

            list1 = list1->next;
        }

        else {

            list2 = list2->next;
        }
    }

    return result;
}

void display(struct Node *head) {

    while(head != NULL) {

        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main() {

    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    insertEnd(&list1, 10);
    insertEnd(&list1, 20);
    insertEnd(&list1, 30);
    insertEnd(&list1, 40);
    insertEnd(&list1, 50);

    insertEnd(&list2, 20);
    insertEnd(&list2, 30);
    insertEnd(&list2, 50);
    insertEnd(&list2, 60);

    printf("List 1: ");
    display(list1);

    printf("List 2: ");
    display(list2);

    struct Node *result =
        findIntersection(list1, list2);

    printf("Intersection: ");
    display(result);

    return 0;
}