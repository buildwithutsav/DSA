#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int data;
    struct Node *left, *right;
};

struct QueueItem {
    struct Node *node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node *newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

void verticalOrder(struct Node *root) {
    if (root == NULL)
        return;

    struct QueueItem q[MAX];
    int front = 0, rear = 0;

    int values[MAX][MAX] = {0};
    int counts[MAX] = {0};

    q[rear++] = (struct QueueItem){root, 50};

    while (front < rear) {
        struct QueueItem item = q[front++];

        struct Node *node = item.node;
        int hd = item.hd;

        values[hd][counts[hd]++] = node->data;

        if (node->left != NULL)
            q[rear++] = (struct QueueItem){node->left, hd - 1};

        if (node->right != NULL)
            q[rear++] = (struct QueueItem){node->right, hd + 1};
    }

    printf("Vertical Order Traversal:\n");

    for (int i = 0; i < MAX; i++) {
        if (counts[i] > 0) {
            for (int j = 0; j < counts[i]; j++)
                printf("%d ", values[i][j]);

            printf("\n");
        }
    }
}

int main() {
    struct Node *root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    verticalOrder(root);

    return 0;
}