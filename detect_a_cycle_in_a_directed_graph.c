#include <stdio.h>

#define V 4

int graph[V][V] = {
    {0, 1, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 1},
    {1, 0, 0, 0}
};

int visited[V] = {0};
int inStack[V] = {0};

int hasCycle(int node) {
    visited[node] = 1;
    inStack[node] = 1;

    for (int next = 0; next < V; next++) {
        if (graph[node][next]) {
            if (!visited[next]) {
                if (hasCycle(next))
                    return 1;
            } else if (inStack[next]) {
                return 1;
            }
        }
    }

    inStack[node] = 0;
    return 0;
}

int main(void) {
    for (int i = 0; i < V; i++) {
        if (!visited[i] && hasCycle(i)) {
            printf("Cycle detected\n");
            return 0;
        }
    }

    printf("No cycle detected\n");
    return 0;
}