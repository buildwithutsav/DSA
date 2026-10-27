#include <stdio.h>

#define V 5
#define INF 999999

int main(void) {
    int graph[V][V] = {
        {0, 10, 0, 5, 0},
        {10, 0, 1, 2, 0},
        {0, 1, 0, 9, 4},
        {5, 2, 9, 0, 2},
        {0, 0, 4, 2, 0}
    };

    int dist[V], visited[V] = {0};
    int src = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1, minDist = INF;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] > 0 &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex  Distance from source\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d       Unreachable\n", i);
        else
            printf("%d       %d\n", i, dist[i]);
    }

    return 0;
}