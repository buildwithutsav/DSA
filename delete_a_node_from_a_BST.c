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

struct node* findMinNode(struct node* root) {
    while (root != NULL && root->left != NULL)
        root = root->left;

    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1 and Case 2
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct node* temp = findMinNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void inorder(struct node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void freeTree(struct node* root) {
    if (root == NULL)
        return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        root = insert(root, arr[i]);

    printf("Before deletion: ");
    inorder(root);

    root = deleteNode(root, 30);

    printf("\nAfter deletion: ");
    inorder(root);

    printf("\n");

    freeTree(root);

    return 0;
}