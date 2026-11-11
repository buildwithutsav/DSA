#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int disc[MAX], low[MAX];
int parent[MAX], articulation[MAX];
int timer = 0;

void dfs(int u, int n) {
    int children = 0;

    disc[u] = low[u] = ++timer;

    for (int v = 0; v < n; v++) {
        if (!graph[u][v])
            continue;

        if (disc[v] == 0) {
            children++;
            parent[v] = u;

            dfs(v, n);

            if (low[v] < low[u])
                low[u] = low[v];

            if (parent[u] == -1 && children > 1)
                articulation[u] = 1;

            if (parent[u] != -1 && low[v] >= disc[u])
                articulation[u] = 1;
        }
        else if (v != parent[u] && disc[v] < low[u]) {
            low[u] = disc[v];
        }
    }
}

int main() {
    int n, m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    if (n < 1 || n > MAX || m < 0) {
        printf("Invalid graph size\n");
        return 0;
    }

    printf("Enter undirected edges:\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n) {
            printf("Invalid edge\n");
            return 0;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    for (int i = 0; i < n; i++) {
        if (disc[i] == 0)
            dfs(i, n);
    }

    printf("Articulation points: ");

    int found = 0;

    for (int i = 0; i < n; i++) {
        if (articulation[i]) {
            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");

    return 0;
}