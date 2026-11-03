#include <stdio.h>
#include <string.h>

#define V 6

int bfs(int residual[V][V], int source,
        int sink, int parent[]) {

    int visited[V] = {0};
    int queue[V];

    int front = 0, rear = 0;

    queue[rear++] = source;
    visited[source] = 1;
    parent[source] = -1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;

                if (v == sink)
                    return 1;
            }
        }
    }

    return 0;
}

int maxFlow(int graph[V][V], int source, int sink) {
    int residual[V][V];
    int parent[V];

    memcpy(residual, graph, sizeof(residual));

    int flow = 0;

    while (bfs(residual, source, sink, parent)) {
        int pathFlow = 999999;

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];

            if (residual[u][v] < pathFlow)
                pathFlow = residual[u][v];
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];

            residual[u][v] -= pathFlow;
            residual[v][u] += pathFlow;
        }

        flow += pathFlow;
    }

    return flow;
}

int main() {
    int graph[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };

    printf("Maximum Flow: %d\n",
           maxFlow(graph, 0, 5));

    return 0;
}