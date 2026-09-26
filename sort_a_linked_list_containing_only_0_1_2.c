#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node **head, int data) {

    struct Node *newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* sort012(struct Node *head) {

    struct Node *zero = NULL;
    struct Node *one = NULL;
    struct Node *two = NULL;

    struct Node *current = head;

    while (current != NULL) {

        if (current->data == 0)
            insertEnd(&zero, 0);

        else if (current->data == 1)
            insertEnd(&one, 1);

        else
            insertEnd(&two, 2);

        current = current->next;
    }

    struct Node *result = NULL;
    struct Node *tail = NULL;

    struct Node *lists[] = {zero, one, two};

    for (int i = 0; i < 3; i++) {

        struct Node *temp = lists[i];

        while (temp != NULL) {

            struct Node *newNode = createNode(temp->data);

            if (result == NULL) {
                result = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            temp = temp->next;
        }
    }

    return result;
}

void display(struct Node *head) {

    while (head != NULL) {
        printf("%d", head->data);

        if (head->next != NULL)
            printf(" -> ");

        head = head->next;
    }

    printf("\n");
}

int main() {

    struct Node *head = NULL;

    insertEnd(&head, 2);
    insertEnd(&head, 1);
    insertEnd(&head, 0);
    insertEnd(&head, 2);
    insertEnd(&head, 1);
    insertEnd(&head, 0);

    printf("Original: ");
    display(head);

    head = sort012(head);

    printf("Sorted: ");
    display(head);

    return 0;
}