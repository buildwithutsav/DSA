#include <stdio.h>

#define V 5
#define MAX 100
#define INF 999999

struct Edge {
    int to, weight;
};

struct Edge graph[V][V] = {
    {{1, 0}, {2, 1}},
    {{2, 0}, {3, 1}},
    {{3, 1}},
    {{4, 0}},
    {{0, 1}}
};

int degree[V] = {2, 2, 1, 1, 1};

int main() {
    int dist[V];

    int deque[MAX];
    int front = MAX / 2;
    int rear = MAX / 2;

    for (int i = 0; i < V; i++)
        dist[i] = INF;

    int source = 0;
    dist[source] = 0;

    deque[rear++] = source;

    while (front < rear) {
        int u = deque[front++];

        for (int i = 0; i < degree[u]; i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if (w == 0)
                    deque[--front] = v;
                else
                    deque[rear++] = v;
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", source);

    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d: Unreachable\n", i);
        else
            printf("%d: %d\n", i, dist[i]);
    }

    return 0;
}