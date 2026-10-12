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

/* Returns -1 if unbalanced; otherwise returns height. */
int checkHeight(struct node* root) {
    if (root == NULL)
        return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1)
        return -1;

    int difference = leftHeight - rightHeight;

    if (difference > 1 || difference < -1)
        return -1;

    return 1 + (leftHeight > rightHeight
                    ? leftHeight : rightHeight);
}

int isBalanced(struct node* root) {
    return checkHeight(root) != -1;
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    if (isBalanced(root))
        printf("Tree is balanced\n");
    else
        printf("Tree is not balanced\n");

    return 0;
}