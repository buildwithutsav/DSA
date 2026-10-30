#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0}
};

int transpose[V][V];
int visited[V];
int stack[V], top = -1;

void dfs1(int u) {
    visited[u] = 1;

    for (int v = 0; v < V; v++)
        if (graph[u][v] && !visited[v])
            dfs1(v);

    stack[++top] = u;
}

void dfs2(int u) {
    visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < V; v++)
        if (transpose[u][v] && !visited[v])
            dfs2(v);
}

int main(void) {
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            transpose[j][i] = graph[i][j];

    for (int i = 0; i < V; i++)
        if (!visited[i])
            dfs1(i);

    for (int i = 0; i < V; i++)
        visited[i] = 0;

    printf("Strongly Connected Components:\n");

    while (top >= 0) {
        int u = stack[top--];

        if (!visited[u]) {
            dfs2(u);
            printf("\n");
        }
    }

    return 0;
}