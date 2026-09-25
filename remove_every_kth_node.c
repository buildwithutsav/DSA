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

struct Node* removeEveryKth(struct Node *head, int k) {

    if (head == NULL || k <= 0)
        return head;

    struct Node *current = head;
    struct Node *previous = NULL;

    int count = 1;

    while (current != NULL) {

        if (count % k == 0) {

            // Remove current node
            previous->next = current->next;

            struct Node *temp = current;

            current = current->next;

            free(temp);
        }
        else {

            previous = current;
            current = current->next;
        }

        count++;
    }

    return head;
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

    head = removeEveryKth(head, k);

    printf("After removing every %d-th node: ", k);
    display(head);

    return 0;
}