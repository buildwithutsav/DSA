#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *random;
};

struct Node* createNode(int data) {
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    newNode->random = NULL;

    return newNode;
}

void printList(struct Node *head) {
    while (head != NULL) {
        printf("Node: %d, Random: ", head->data);

        if (head->random != NULL)
            printf("%d", head->random->data);
        else
            printf("NULL");

        printf("\n");

        head = head->next;
    }
}

struct Node* cloneList(struct Node *head) {

    if (head == NULL)
        return NULL;

    struct Node *current = head;

    // Step 1: Insert copied nodes
    while (current != NULL) {
        struct Node *copy = createNode(current->data);

        copy->next = current->next;
        current->next = copy;

        current = copy->next;
    }

    // Step 2: Set random pointers
    current = head;

    while (current != NULL) {

        if (current->random != NULL)
            current->next->random = current->random->next;

        current = current->next->next;
    }

    // Step 3: Separate original and copied list
    current = head;

    struct Node *cloneHead = head->next;

    while (current != NULL) {

        struct Node *copy = current->next;

        current->next = copy->next;

        if (copy->next != NULL)
            copy->next = copy->next->next;

        current = current->next;
    }

    return cloneHead;
}

int main() {

    struct Node *head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);

    // Random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    printf("Original List:\n");
    printList(head);

    struct Node *clone = cloneList(head);

    printf("\nCloned List:\n");
    printList(clone);

    return 0;
}