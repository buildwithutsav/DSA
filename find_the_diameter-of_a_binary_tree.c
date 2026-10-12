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

int max(int a, int b) {
    return a > b ? a : b;
}

int heightAndDiameter(struct node* root, int* diameter) {
    if (root == NULL)
        return 0;

    int leftHeight =
        heightAndDiameter(root->left, diameter);

    int rightHeight =
        heightAndDiameter(root->right, diameter);

    int path = leftHeight + rightHeight;

    if (path > *diameter)
        *diameter = path;

    return 1 + max(leftHeight, rightHeight);
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int diameter = 0;

    heightAndDiameter(root, &diameter);

    printf("Diameter = %d edges\n", diameter);

    return 0;
}