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

struct Node* oddEven(struct Node *head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct Node *odd = head;
    struct Node *even = head->next;

    // Save beginning of even list
    struct Node *evenHead = even;

    while (even != NULL && even->next != NULL) {

        // Connect current odd node to next odd node
        odd->next = even->next;

        odd = odd->next;

        // Connect current even node to next even node
        even->next = odd->next;

        even = even->next;
    }

    // Attach even list after odd list
    odd->next = evenHead;

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

    head = oddEven(head);

    printf("After odd-even rearrangement: ");
    display(head);

    return 0;
}