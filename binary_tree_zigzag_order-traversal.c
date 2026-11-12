#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int value) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void zigzagTraversal(Node *root) {
    if (root == NULL)
        return;

    Node *queue[MAX];

    int front = 0, rear = 0;
    int leftToRight = 1;

    queue[rear++] = root;

    while (front < rear) {
        int levelSize = rear - front;
        int values[MAX];

        for (int i = 0; i < levelSize; i++) {
            Node *current = queue[front++];

            values[i] = current->data;

            if (current->left)
                queue[rear++] = current->left;

            if (current->right)
                queue[rear++] = current->right;
        }

        if (leftToRight) {
            for (int i = 0; i < levelSize; i++)
                printf("%d ", values[i]);
        } else {
            for (int i = levelSize - 1; i >= 0; i--)
                printf("%d ", values[i]);
        }

        leftToRight = !leftToRight;
    }
}

int main() {
    Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Zigzag traversal: ");

    zigzagTraversal(root);

    printf("\n");

    return 0;
}