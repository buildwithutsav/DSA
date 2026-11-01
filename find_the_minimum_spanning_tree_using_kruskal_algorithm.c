#include <stdio.h>
#include <stdlib.h>

#define V 4
#define E 5

typedef struct {
    int src, dest, weight;
} Edge;

int parent[V], size[V];

int compare(const void *a, const void *b) {
    Edge *x = (Edge *)a;
    Edge *y = (Edge *)b;

    return (x->weight > y->weight) -
           (x->weight < y->weight);
}

void initialize(void) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    if (size[a] < size[b]) {
        int temp = a;
        a = b;
        b = temp;
    }

    parent[b] = a;
    size[a] += size[b];

    return 1;
}

int main(void) {
    Edge edges[E] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    initialize();
    qsort(edges, E, sizeof(Edge), compare);

    int total = 0, count = 0;

    printf("MST edges:\n");

    for (int i = 0; i < E && count < V - 1; i++) {
        if (unite(edges[i].src, edges[i].dest)) {
            printf("%d - %d : %d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);

            total += edges[i].weight;
            count++;
        }
    }

    if (count != V - 1)
        printf("Graph is disconnected; no spanning tree exists\n");
    else
        printf("Minimum cost: %d\n", total);

    return 0;
}