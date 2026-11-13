#include <stdio.h>

#define MAX 100
#define INF 1000000000

typedef struct {
    int to;
    int weight;
} Edge;

Edge graph[MAX][MAX];
int degree[MAX];
int visited[MAX];
int order[MAX];
int top = 0;

void dfs(int u) {
    visited[u] = 1;

    for (int i = 0; i < degree[u]; i++) {
        int v = graph[u][i].to;

        if (!visited[v])
            dfs(v);
    }

    order[top++] = u;
}

int main() {
    int V, E;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V < 1 || V > MAX ||
        E < 0 || E > MAX * MAX) {
        printf("Invalid graph size\n");
        return 1;
    }

    printf("Enter edges (from to weight):\n");

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        if (u < 0 || u >= V || v < 0 || v >= V ||
            degree[u] >= MAX) {
            printf("Invalid edge\n");
            return 1;
        }

        graph[u][degree[u]].to = v;
        graph[u][degree[u]].weight = w;
        degree[u]++;
    }

    int source;

    printf("Enter source: ");
    scanf("%d", &source);

    if (source < 0 || source >= V) {
        printf("Invalid source\n");
        return 1;
    }

    // Topological sorting
    for (int i = 0; i < V; i++) {
        if (!visited[i])
            dfs(i);
    }

    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Process vertices in topological order
    for (int i = top - 1; i >= 0; i--) {
        int u = order[i];

        if (dist[u] == INF)
            continue;

        for (int j = 0; j < degree[u]; j++) {
            int v = graph[u][j].to;
            int w = graph[u][j].weight;

            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    printf("Shortest distances from source %d:\n", source);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("INF ");
        else
            printf("%d ", dist[i]);
    }

    printf("\n");

    return 0;
}