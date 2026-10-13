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

void printPaths(struct node* root, int path[], int length) {
    if (root == NULL)
        return;

    path[length++] = root->data;

    if (root->left == NULL && root->right == NULL) {
        for (int i = 0; i < length; i++)
            printf("%d ", path[i]);

        printf("\n");
        return;
    }

    printPaths(root->left, path, length);
    printPaths(root->right, path, length);
}

int main() {
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int path[100];

    printf("Root-to-leaf paths:\n");
    printPaths(root, path, 0);

    return 0;
}