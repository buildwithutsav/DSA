
#include <stdio.h>
#include <string.h>

#define MAX_N 15
#define MAX_STATES (1 << MAX_N)
#define MAX_QUEUE (MAX_N * MAX_STATES)

typedef struct {
    int node;
    int mask;
    int distance;
} State;

int main() {
    int n, m;
    int graph[MAX_N][MAX_N] = {0};

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    if (n < 1 || n > MAX_N || m < 0) {
        printf("Invalid input\n");
        return 0;
    }

    printf("Enter edges (u v), using 0-based indexing:\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n ||
            u == v) {
            printf("Invalid edge\n");
            return 0;
        }

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int target = (1 << n) - 1;

    static int visited[MAX_N][MAX_STATES];
    static State queue[MAX_QUEUE];

    int front = 0;
    int rear = 0;

    // Start BFS from every node
    for (int i = 0; i < n; i++) {
        int mask = 1 << i;

        visited[i][mask] = 1;

        queue[rear++] = (State){i, mask, 0};
    }

    while (front < rear) {
        State current = queue[front++];

        if (current.mask == target) {
            printf("Shortest path length: %d\n",
                   current.distance);
            return 0;
        }

        for (int next = 0; next < n; next++) {
            if (graph[current.node][next]) {
                int newMask = current.mask | (1 << next);

                if (!visited[next][newMask]) {
                    visited[next][newMask] = 1;

                    queue[rear++] = (State){
                        next,
                        newMask,
                        current.distance + 1
                    };
                }
            }
        }
    }

    printf("No path visiting all nodes exists\n");

    return 0;
}
