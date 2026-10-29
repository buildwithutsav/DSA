#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1},
    {0, 0, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int disc[V], low[V], parent[V];
int timer = 0;

void dfs(int u) {
    disc[u] = low[u] = ++timer;

    for (int v = 0; v < V; v++) {
        if (!graph[u][v])
            continue;

        if (!disc[v]) {
            parent[v] = u;
            dfs(v);

            if (low[v] < low[u])
                low[u] = low[v];

            if (low[v] > disc[u])
                printf("Bridge: %d - %d\n", u, v);
        } else if (v != parent[u] && disc[v] < low[u]) {
            low[u] = disc[v];
        }
    }
}

int main(void) {
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; i < V; i++)
        if (!disc[i])
            dfs(i);

    return 0;
}