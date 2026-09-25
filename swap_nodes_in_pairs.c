#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* swapPairs(struct Node *head) {

    if (head == NULL || head->next == NULL)
        return head;

    struct Node *prev = NULL;
    struct Node *first = head;
    struct Node *second = head->next;

    head = second;

    while (first != NULL && second != NULL) {

        // Swap the two nodes
        first->next = second->next;
        second->next = first;

        // Connect previous pair to current pair
        if (prev != NULL)
            prev->next = second;

        // Move to next pair
        prev = first;
        first = first->next;

        if (first != NULL)
            second = first->next;
    }

    return head;
}