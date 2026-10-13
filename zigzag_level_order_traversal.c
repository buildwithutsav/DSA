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

int height(struct node* root) {
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

void printLevel(struct node* root, int level, int leftToRight) {
    if (root == NULL)
        return;

    if (level == 1) {
        printf("%d ", root->data);
    }
    else if (leftToRight) {
        printLevel(root->left, level - 1, leftToRight);
        printLevel(root->right, level - 1, leftToRight);
    }
    else {
        printLevel(root->right, level - 1, leftToRight);
        printLevel(root->left, level - 1, leftToRight);
    }
}

void zigzag(struct node* root) {
    int h = height(root);

    for (int level = 1; level <= h; level++) {
        printLevel(root, level, level % 2 == 1);
        printf("\n");
    }
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    zigzag(root);

    return 0;
}