
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int data) {
    struct node* n = malloc(sizeof(struct node));
    if (n == NULL) exit(EXIT_FAILURE);

    n->data = data;
    n->left = n->right = NULL;
    return n;
}

struct node* lca(struct node* root, int a, int b) {
    if (root == NULL || root->data == a || root->data == b)
        return root;

    struct node* left = lca(root->left, a, b);
    struct node* right = lca(root->right, a, b);

    if (left != NULL && right != NULL)
        return root;

    return left != NULL ? left : right;
}

int contains(struct node* root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;

    return contains(root->left, key) ||
           contains(root->right, key);
}

int main(void) {
    struct node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int a = 4, b = 5;

    if (contains(root, a) && contains(root, b)) {
        struct node* ans = lca(root, a, b);
        printf("LCA of %d and %d: %d\n", a, b, ans->data);
    } else {
        printf("One or both nodes not found\n");
    }

    return 0;
}
