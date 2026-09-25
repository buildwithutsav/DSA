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

struct Node* rotateRight(struct Node *head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node *tail = head;

    int length = 1;

    // Find last node and length
    while (tail->next != NULL) {

        tail = tail->next;
        length++;
    }

    // Avoid unnecessary rotations
    k = k % length;

    if (k == 0)
        return head;

    // Make list circular
    tail->next = head;

    // Find new tail
    int steps = length - k;

    struct Node *newTail = head;

    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }

    // Node after newTail becomes new head
    struct Node *newHead = newTail->next;

    // Break circular connection
    newTail->next = NULL;

    return newHead;
}

int main() {

    struct Node *head = NULL;

    int n, value, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {

        scanf("%d", &value);
        insertEnd(&head, value);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    printf("\nOriginal list: ");
    display(head);

    head = rotateRight(head, k);

    printf("After rotation: ");
    display(head);

    return 0;
}