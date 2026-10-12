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

void mirror(struct node* root) {
    if (root == NULL) return;

    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirror(root->left);
    mirror(root->right);
}

void inorder(struct node* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Before mirror: ");
    inorder(root);

    mirror(root);

    printf("\nAfter mirror: ");
    inorder(root);

    return 0;
}