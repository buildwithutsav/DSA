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

struct Node* addNumbers(struct Node *l1, struct Node *l2) {

    struct Node *result = NULL;
    struct Node *tail = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {

        int sum = carry;

        // Add first number
        if (l1 != NULL) {

            sum = sum + l1->data;

            l1 = l1->next;
        }

        // Add second number
        if (l2 != NULL) {

            sum = sum + l2->data;

            l2 = l2->next;
        }

        // Find digit and carry
        int digit = sum % 10;

        carry = sum / 10;

        // Create new node
        struct Node *newNode = createNode(digit);

        // First node
        if (result == NULL) {

            result = newNode;
            tail = newNode;
        }

        // Add at end
        else {

            tail->next = newNode;
            tail = newNode;
        }
    }

    return result;
}

int main() {

    struct Node *list1 = NULL;
    struct Node *list2 = NULL;
    struct Node *result = NULL;

    int n1, n2, value;

    // First number
    printf("Enter number of nodes in first number: ");
    scanf("%d", &n1);

    printf("Enter digits of first number:\n");

    for (int i = 0; i < n1; i++) {

        scanf("%d", &value);
        insertEnd(&list1, value);
    }

    // Second number
    printf("Enter number of nodes in second number: ");
    scanf("%d", &n2);

    printf("Enter digits of second number:\n");

    for (int i = 0; i < n2; i++) {

        scanf("%d", &value);
        insertEnd(&list2, value);
    }

    printf("\nFirst number: ");
    display(list1);

    printf("Second number: ");
    display(list2);

    result = addNumbers(list1, list2);

    printf("Result: ");
    display(result);

    return 0;
}