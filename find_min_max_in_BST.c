#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* createNode(int data) {
    struct node* newNode = malloc(sizeof(struct node));

    if (newNode == NULL)
        exit(1);

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

int findMin(struct node* root) {
    while (root->left != NULL)
        root = root->left;

    return root->data;
}

int findMax(struct node* root) {
    while (root->right != NULL)
        root = root->right;

    return root->data;
}

int main() {
    struct node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    if (root == NULL) {
        printf("Tree is empty\n");
        return 0;
    }

    printf("Minimum = %d\n", findMin(root));
    printf("Maximum = %d\n", findMax(root));

    return 0;
}