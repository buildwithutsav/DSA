#include <stdio.h>

#define V 6

int main(void) {
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0}
    };

    int indegree[V] = {0};
    int queue[V], front = 0, rear = 0;
    int order[V], count = 0;

    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            if (graph[u][v])
                indegree[v]++;

    for (int i = 0; i < V; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    while (front < rear) {
        int u = queue[front++];
        order[count++] = u;

        for (int v = 0; v < V; v++) {
            if (graph[u][v]) {
                indegree[v]--;

                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    if (count != V) {
        printf("Graph contains a cycle; topological sort impossible\n");
    } else {
        printf("Topological order: ");
        for (int i = 0; i < count; i++)
            printf("%d ", order[i]);
        printf("\n");
    }

    return 0;
}