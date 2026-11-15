#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define URL_SIZE 100

typedef struct Node {
    char url[URL_SIZE];
    struct Node *prev;
    struct Node *next;
} Node;

Node *current = NULL;

Node *createNode(char url[]) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}

void visit(char url[]) {
    Node *newNode = createNode(url);

    if (current != NULL) {
        Node *temp = current->next;

        // Delete forward history
        while (temp != NULL) {
            Node *nextNode = temp->next;
            free(temp);
            temp = nextNode;
        }

        current->next = NULL;
        newNode->prev = current;
        current->next = newNode;
    }

    current = newNode;
}

void goBack(int steps) {
    while (steps > 0 && current->prev != NULL) {
        current = current->prev;
        steps--;
    }
}

void goForward(int steps) {
    while (steps > 0 && current->next != NULL) {
        current = current->next;
        steps--;
    }
}

void display() {
    if (current == NULL)
        printf("No browser history\n");
    else
        printf("Current page: %s\n", current->url);
}

void freeHistory() {
    if (current == NULL)
        return;

    while (current->prev != NULL)
        current = current->prev;

    while (current != NULL) {
        Node *nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    int n;
    char operation[20];
    char url[URL_SIZE];
    int steps;

    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%19s", operation);

        if (strcmp(operation, "VISIT") == 0) {
            scanf("%99s", url);
            visit(url);
        }
        else if (strcmp(operation, "BACK") == 0) {
            scanf("%d", &steps);

            if (steps >= 0)
                goBack(steps);
        }
        else if (strcmp(operation, "FORWARD") == 0) {
            scanf("%d", &steps);

            if (steps >= 0)
                goForward(steps);
        }
        else {
            printf("Invalid operation\n");
        }
    }

    display();
    freeHistory();

    return 0;
}