
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* newNode(int data) {
    struct node* n = malloc(sizeof(struct node));
    if (n == NULL) exit(EXIT_FAILURE);

    n->data = data;
    n->next = NULL;
    return n;
}

int hasCycle(struct node* head) {
    struct node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return 1;
    }

    return 0;
}

int main(void) {
    struct node* a = newNode(10);
    struct node* b = newNode(20);
    struct node* c = newNode(30);
    struct node* d = newNode(40);

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = b;  // Creates a cycle

    printf("%s\n", hasCycle(a) ?
           "Cycle detected" : "No cycle");

    // Break cycle before freeing memory.
    d->next = NULL;

    free(a);
    free(b);
    free(c);
    free(d);

    return 0;
}
