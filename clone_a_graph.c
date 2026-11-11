#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int value;
    int count;
    struct Node *neighbors[MAX];
} Node;

Node *original[MAX];
Node *clones[MAX];

Node *createNode(int value) {
    Node *node = calloc(1, sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->value = value;

    return node;
}

Node *cloneGraph(Node *node, int n) {
    if (node == NULL)
        return NULL;

    int value = node->value;

    if (clones[value] != NULL)
        return clones[value];

    Node *copy = createNode(value);

    clones[value] = copy;

    for (int i = 0; i < node->count; i++) {
        Node *neighbor = node->neighbors[i];

        copy->neighbors[copy->count++] =
            cloneGraph(neighbor, n);
    }

    return copy;
}

void printGraph(Node *node, int n, int visited[]) {
    if (node == NULL || visited[node->value])
        return;

    visited[node->value] = 1;

    printf("%d: ", node->value);

    for (int i = 0; i < node->count; i++)
        printf("%d ", node->neighbors[i]->value);

    printf("\n");

    for (int i = 0; i < node->count; i++)
        printGraph(node->neighbors[i], n, visited);
}

int main() {
    int n, m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    if (n < 1 || n > MAX || m < 0) {
        printf("Invalid graph size\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        original[i] = createNode(i);

    printf("Enter undirected edges:\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge\n");
            return 0;
        }

        if (original[u]->count >= MAX ||
            original[v]->count >= MAX) {
            printf("Too many neighbors\n");
            return 0;
        }

        original[u]->neighbors[original[u]->count++] =
            original[v];

        original[v]->neighbors[original[v]->count++] =
            original[u];
    }

    Node *copy = cloneGraph(original[0], n);

    int visited[MAX] = {0};

    printf("\nCloned graph:\n");
    printGraph(copy, n, visited);

    return 0;
}