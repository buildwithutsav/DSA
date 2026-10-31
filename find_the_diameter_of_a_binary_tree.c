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

int max(int a, int b) {
    return a > b ? a : b;
}

int diameter(Node *root, int *result) {
    if (root == NULL)
        return 0;

    int leftHeight = diameter(root->left, result);
    int rightHeight = diameter(root->right, result);

    *result = max(*result, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}

int main(void) {
    Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int result = 0;
    diameter(root, &result);

    printf("Diameter of tree: %d edges\n", result);

    return 0;
}