#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int findMax(struct node* root) {
    if (root == NULL)
        return INT_MIN;

    int max = root->data;

    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);

    if (leftMax > max)
        max = leftMax;

    if (rightMax > max)
        max = rightMax;

    return max;
}

int main() {
    struct node* root = createNode(10);

    root->left = createNode(25);
    root->right = createNode(15);

    root->left->left = createNode(40);
    root->left->right = createNode(5);

    printf("Maximum = %d", findMax(root));

    return 0;
}