#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct Node {
    int data;
    struct Node *left, *right;
};

int maxSum = -1000000000;

struct Node* createNode(int data) {
    struct Node *node =
        (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = node->right = NULL;

    return node;
}

int maxGain(struct Node *root) {
    if (root == NULL)
        return 0;

    int leftGain = MAX(0, maxGain(root->left));
    int rightGain = MAX(0, maxGain(root->right));

    int currentPath =
        root->data + leftGain + rightGain;

    maxSum = MAX(maxSum, currentPath);

    return root->data + MAX(leftGain, rightGain);
}

int main() {
    struct Node *root = createNode(-10);

    root->left = createNode(9);
    root->right = createNode(20);

    root->right->left = createNode(15);
    root->right->right = createNode(7);

    maxGain(root);

    printf("Maximum Path Sum: %d\n", maxSum);

    return 0;
}