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

struct Node* findMergePoint(struct Node *headA,
                            struct Node *headB) {

    struct Node *p = headA;
    struct Node *q = headB;

    while (p != q) {

        if (p == NULL)
            p = headB;
        else
            p = p->next;

        if (q == NULL)
            q = headA;
        else
            q = q->next;
    }

    return p;
}

int main() {

    struct Node *headA = createNode(1);
    headA->next = createNode(2);
    headA->next->next = createNode(3);

    struct Node *merge = createNode(7);
    merge->next = createNode(8);
    merge->next->next = createNode(9);

    headA->next->next->next = merge;

    struct Node *headB = createNode(4);
    headB->next = createNode(5);

    headB->next->next = merge;

    struct Node *result = findMergePoint(headA, headB);

    if (result != NULL)
        printf("Merge point = %d\n", result->data);
    else
        printf("No merge point\n");

    return 0;
}