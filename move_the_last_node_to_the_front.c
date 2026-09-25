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

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
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

struct Node* moveLastToFront(struct Node *head) {

    // Empty list or only one node
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *secondLast = NULL;
    struct Node *last = head;

    // Find last and second-last node
    while (last->next != NULL) {

        secondLast = last;
        last = last->next;
    }

    // Remove last node
    secondLast->next = NULL;

    // Put last node at beginning
    last->next = head;
    head = last;

    return head;
}

int main() {

    struct Node *head = NULL;

    int n, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("\nOriginal list: ");
    display(head);

    head = moveLastToFront(head);

    printf("After moving last node to front: ");
    display(head);

    return 0;
}