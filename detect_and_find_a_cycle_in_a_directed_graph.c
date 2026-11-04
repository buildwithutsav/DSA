#include <stdio.h>

#define V 5

int graph[V][V] = {
    {0, 1, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0}
};

int visited[V] = {0};
int inStack[V] = {0};
int parent[V];

int cycleStart = -1;
int cycleEnd = -1;

int dfs(int u) {
    visited[u] = 1;
    inStack[u] = 1;

    for (int v = 0; v < V; v++) {

        if (graph[u][v]) {

            if (!visited[v]) {
                parent[v] = u;

                if (dfs(v))
                    return 1;
            }
            else if (inStack[v]) {
                cycleStart = v;
                cycleEnd = u;
                return 1;
            }
        }
    }

    inStack[u] = 0;
    return 0;
}

int main() {
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    int found = 0;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dfs(i)) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No cycle found.\n");
    }
    else {
        int path[V + 1];
        int count = 0;

        path[count++] = cycleEnd;

        while (path[count - 1] != cycleStart) {
            path[count] = parent[path[count - 1]];
            count++;
        }

        printf("Cycle found: ");

        printf("%d", cycleStart);

        for (int i = count - 2; i >= 0; i--)
            printf(" -> %d", path[i]);

        printf(" -> %d\n", cycleStart);
    }

    return 0;
}