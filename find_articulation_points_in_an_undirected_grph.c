#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0,1,1,0,0},
    {1,0,1,1,0},
    {1,1,0,0,0},
    {0,1,0,0,1},
    {0,0,0,1,0}
};

int disc[V], low[V], parent[V];
int articulation[V];
int timer = 0;

void dfs(int u) {
    int children = 0;

    disc[u] = low[u] = ++timer;

    for (int v = 0; v < V; v++) {
        if (!graph[u][v])
            continue;

        if (!disc[v]) {
            children++;
            parent[v] = u;

            dfs(v);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent[u] == -1 && children > 1)
                articulation[u] = 1;

            if (parent[u] != -1 && low[v] >= disc[u])
                articulation[u] = 1;

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

    printf("Articulation points: ");

    for (int i = 0; i < V; i++)
        if (articulation[i])
            printf("%d ", i);

    printf("\n");
    return 0;
}