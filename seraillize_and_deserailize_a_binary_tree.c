#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node *node =
        (struct Node*)malloc(sizeof(struct Node));

    node->data = data;
    node->left = node->right = NULL;

    return node;
}

void serialize(struct Node *root, FILE *file) {
    if (root == NULL) {
        fprintf(file, "# ");
        return;
    }

    fprintf(file, "%d ", root->data);

    serialize(root->left, file);
    serialize(root->right, file);
}

struct Node* deserialize(FILE *file) {
    char token[32];

    if (fscanf(file, "%31s", token) != 1)
        return NULL;

    if (strcmp(token, "#") == 0)
        return NULL;

    int value = atoi(token);

    struct Node *root = createNode(value);

    root->left = deserialize(file);
    root->right = deserialize(file);

    return root;
}

void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->right->left = createNode(4);
    root->right->right = createNode(5);

    FILE *file = tmpfile();

    if (file == NULL) {
        printf("File creation failed.");
        return 1;
    }

    serialize(root, file);

    rewind(file);

    struct Node *newRoot = deserialize(file);

    printf("Original Tree Inorder: ");
    inorder(root);

    printf("\nDeserialized Tree Inorder: ");
    inorder(newRoot);

    printf("\n");

    fclose(file);

    return 0;
}