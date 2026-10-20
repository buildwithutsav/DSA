
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

void kthSmallest(struct node* root, int k,
                 int* count, int* result) {
    if (root == NULL || *count >= k)
        return;

    kthSmallest(root->left, k, count, result);

    (*count)++;

    if (*count == k) {
        *result = root->data;
        return;
    }

    kthSmallest(root->right, k, count, result);
}

int main() {
    struct node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    int k = 3, count = 0, result = 0;

    if (k < 1 || k > n) {
        printf("Invalid k\n");
    } else {
        kthSmallest(root, k, &count, &result);
        printf("%dth smallest element: %d\n", k, result);
    }

    return 0;
}
