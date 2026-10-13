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

struct node* LCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct node* left = LCA(root->left, n1, n2);
    struct node* right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    struct node* result = LCA(root, 4, 5);

    if (result != NULL)
        printf("LCA = %d\n", result->data);
    else
        printf("LCA not found\n");

    return 0;
}