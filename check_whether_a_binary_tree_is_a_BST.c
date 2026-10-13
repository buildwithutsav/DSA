#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int isBST(struct node* root, long long min,
          long long max) {
    if (root == NULL)
        return 1;

    if (root->data <= min || root->data >= max)
        return 0;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main() {
    struct node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);

    if (isBST(root, LLONG_MIN, LLONG_MAX))
        printf("Valid BST\n");
    else
        printf("Not a BST\n");

    return 0;
}