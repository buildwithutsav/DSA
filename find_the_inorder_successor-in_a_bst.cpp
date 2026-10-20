
#include <stdio.h>
#include <stdlib.h>

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

struct node* insert(struct node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

struct node* findSuccessor(struct node* root, int key) {
    struct node* successor = NULL;

    while (root != NULL) {
        if (key < root->data) {
            successor = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return successor;
}

int main() {
    struct node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    int key = 40;
    struct node* result = findSuccessor(root, key);

    if (result != NULL)
        printf("Successor of %d: %d\n", key, result->data);
    else
        printf("No successor exists\n");

    return 0;
}
