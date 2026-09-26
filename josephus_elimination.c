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

struct Node* createCircularList(int n) {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    for (int i = 1; i <= n; i++) {
        struct Node *newNode = createNode(i);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    tail->next = head;

    return head;
}

int josephus(struct Node *head, int k) {
    struct Node *current = head;
    struct Node *previous = NULL;

    while (current->next != current) {

        for (int i = 1; i < k; i++) {
            previous = current;
            current = current->next;
        }

        printf("Eliminated: %d\n", current->data);

        previous->next = current->next;
        free(current);

        current = previous->next;
    }

    int survivor = current->data;
    free(current);

    return survivor;
}

int main() {
    int n, k;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter k: ");
    scanf("%d", &k);

    struct Node *head = createCircularList(n);

    int survivor = josephus(head, k);

    printf("Survivor: %d\n", survivor);

    return 0;
}