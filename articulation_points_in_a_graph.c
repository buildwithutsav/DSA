#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 0, 1, 0}
};

int disc[V], low[V], parent[V];
int visited[V], timer = 0;
int ap[V];

void dfs(int u) {
    visited[u] = 1;
    disc[u] = low[u] = ++timer;

    int children = 0;

    for (int v = 0; v < V; v++) {
        if (graph[u][v]) {
            if (!visited[v]) {
                children++;
                parent[v] = u;

                dfs(v);

                if (low[v] < low[u])
                    low[u] = low[v];

                if (parent[u] == -1 && children > 1)
                    ap[u] = 1;

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            }
            else if (v != parent[u] && disc[v] < low[u]) {
                low[u] = disc[v];
            }
        }
    }
}

int main() {
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    printf("Articulation Points: ");

    for (int i = 0; i < V; i++) {
        if (ap[i])
            printf("%d ", i);
    }

    printf("\n");

    return 0;
}