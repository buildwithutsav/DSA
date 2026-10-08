#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void preorder(struct node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder: ");
    preorder(root);

    return 0;
}