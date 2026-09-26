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

void deleteNode(struct Node *node) {

    if (node == NULL || node->next == NULL) {
        printf("Cannot delete this node.\n");
        return;
    }

    struct Node *temp = node->next;

    node->data = temp->data;
    node->next = temp->next;

    free(temp);
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

    struct Node *head = createNode(10);

    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Before deletion:\n");
    display(head);

    // Delete node containing 30
    deleteNode(head->next->next);

    printf("After deletion:\n");
    display(head);

    return 0;
}