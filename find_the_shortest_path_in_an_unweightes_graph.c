#include <stdio.h>

#define V 6
#define INF -1

int graph[V][V] = {
    {0, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {1, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1},
    {0, 1, 1, 0, 0, 1},
    {0, 0, 0, 1, 1, 0}
};

int main(void) {
    int distance[V];
    int queue[V];
    int front = 0, rear = 0;
    int source = 0;

    for (int i = 0; i < V; i++)
        distance[i] = INF;

    distance[source] = 0;
    queue[rear++] = source;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && distance[v] == INF) {
                distance[v] = distance[u] + 1;
                queue[rear++] = v;
            }
        }
    }

    printf("Vertex  Distance from source\n");

    for (int i = 0; i < V; i++) {
        if (distance[i] == INF)
            printf("%d       Unreachable\n", i);
        else
            printf("%d       %d\n", i, distance[i]);
    }

    return 0;
}