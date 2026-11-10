#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int isLeaf(Node *root) {
    return root != NULL &&
           root->left == NULL &&
           root->right == NULL;
}

void printLeaves(Node *root) {
    if (root == NULL)
        return;

    if (isLeaf(root)) {
        printf("%d ", root->data);
        return;
    }

    printLeaves(root->left);
    printLeaves(root->right);
}

void printLeftBoundary(Node *root) {
    if (root == NULL || isLeaf(root))
        return;

    printf("%d ", root->data);

    if (root->left)
        printLeftBoundary(root->left);
    else
        printLeftBoundary(root->right);
}

void printRightBoundary(Node *root) {
    if (root == NULL || isLeaf(root))
        return;

    if (root->right)
        printRightBoundary(root->right);
    else
        printRightBoundary(root->left);

    printf("%d ", root->data);
}

void boundaryTraversal(Node *root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    if (!isLeaf(root))
        printLeftBoundary(root->left);

    printLeaves(root->left);
    printLeaves(root->right);

    if (!isLeaf(root))
        printRightBoundary(root->right);
}

int main() {
    Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    root->left->right->left = createNode(8);
    root->left->right->right = createNode(9);

    printf("Boundary traversal: ");
    boundaryTraversal(root);

    printf("\n");

    return 0;
}