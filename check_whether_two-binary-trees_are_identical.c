#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* n = malloc(sizeof(struct node));
    if (n == NULL) exit(1);

    n->data = data;
    n->left = n->right = NULL;
    return n;
}

int identical(struct node* a, struct node* b) {
    if (a == NULL && b == NULL)
        return 1;

    if (a == NULL || b == NULL)
        return 0;

    return a->data == b->data &&
           identical(a->left, b->left) &&
           identical(a->right, b->right);
}

int main() {
    struct node* t1 = createNode(1);
    t1->left = createNode(2);
    t1->right = createNode(3);

    struct node* t2 = createNode(1);
    t2->left = createNode(2);
    t2->right = createNode(3);

    if (identical(t1, t2))
        printf("Trees are identical\n");
    else
        printf("Trees are not identical\n");

    return 0;
}