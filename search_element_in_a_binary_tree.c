#include <stdio.h>
#include <stdlib.h>

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

int search(struct node* root, int key) {
    if (root == NULL)
        return 0;

    if (root->data == key)
        return 1;

    return search(root->left, key) ||
           search(root->right, key);
}

int main() {
    struct node* root = createNode(10);

    root->left = createNode(20);
    root->right = createNode(30);

    root->left->left = createNode(40);
    root->left->right = createNode(50);

    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    if (search(root, key))
        printf("Element found");
    else
        printf("Element not found");

    return 0;
}