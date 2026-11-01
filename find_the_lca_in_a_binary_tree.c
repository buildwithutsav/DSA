#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL)
        exit(EXIT_FAILURE);

    node->data = value;
    node->left = node->right = NULL;

    return node;
}

Node *LCA(Node *root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int main(void) {
    Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    Node *result = LCA(root, 4, 5);

    if (result != NULL)
        printf("LCA of 4 and 5: %d\n", result->data);
    else
        printf("LCA not found\n");

    return 0;
}