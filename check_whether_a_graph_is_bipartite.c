#include <stdio.h>

#define V 4

int graph[V][V] = {
    {0, 1, 0, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 0, 1, 0}
};

int isBipartite(void) {
    int color[V];
    int queue[V];

    for (int i = 0; i < V; i++)
        color[i] = -1;

    for (int start = 0; start < V; start++) {
        if (color[start] != -1)
            continue;

        int front = 0, rear = 0;
        queue[rear++] = start;
        color[start] = 0;

        while (front < rear) {
            int u = queue[front++];

            for (int v = 0; v < V; v++) {
                if (!graph[u][v])
                    continue;

                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    queue[rear++] = v;
                } else if (color[v] == color[u]) {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int main(void) {
    printf("Graph is %sbipartite\n",
           isBipartite() ? "" : "not ");
    return 0;
}