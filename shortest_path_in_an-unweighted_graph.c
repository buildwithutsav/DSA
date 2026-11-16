#include <stdio.h>

#define MAX 100
#define INF -1

int graph[MAX][MAX];
int visited[MAX];
int dist[MAX];
int queue[MAX];

int main() {
    int V, E;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    if (V < 1 || V > MAX ||
        E < 0 || E > V * (V - 1) / 2) {
        printf("Invalid graph size\n");
        return 1;
    }

    printf("Enter undirected edges:\n");

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= V || v < 0 || v >= V) {
            printf("Invalid edge\n");
            return 1;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int source;

    printf("Enter source: ");
    scanf("%d", &source);

    if (source < 0 || source >= V) {
        printf("Invalid source\n");
        return 1;
    }

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    int front = 0, rear = 0;

    queue[rear++] = source;
    visited[source] = 1;
    dist[source] = 0;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = 1;
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    printf("Shortest distances:\n");

    for (int i = 0; i < V; i++)
        printf("%d ", dist[i]);

    printf("\n");

    return 0;
}