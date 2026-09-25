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

int firstRepeating(struct Node *head) {

    struct Node *current = head;

    while (current != NULL) {

        struct Node *temp = current->next;

        while (temp != NULL) {

            if (current->data == temp->data) {
                return current->data;
            }

            temp = temp->next;
        }

        current = current->next;
    }

    return -1;
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

    printf("\nLinked List: ");
    display(head);

    int answer = firstRepeating(head);

    if (answer == -1)
        printf("No repeating element found.\n");
    else
        printf("First repeating element = %d\n", answer);

    return 0;
}