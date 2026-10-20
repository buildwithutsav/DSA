
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode =
        (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

bool hasPathSum(struct node* root, int target) {
    if (root == NULL)
        return false;

    if (root->left == NULL && root->right == NULL)
        return root->data == target;

    int remaining = target - root->data;

    return hasPathSum(root->left, remaining) ||
           hasPathSum(root->right, remaining);
}

int main() {
    struct node* root = createNode(5);

    root->left = createNode(4);
    root->right = createNode(8);

    root->left->left = createNode(11);
    root->left->left->left = createNode(7);
    root->left->left->right = createNode(2);

    root->right->left = createNode(13);
    root->right->right = createNode(4);
    root->right->right->right = createNode(1);

    int target = 22;

    if (hasPathSum(root, target))
        printf("Path with sum %d exists\n", target);
    else
        printf("Path with sum %d does not exist\n", target);

    return 0;
}
