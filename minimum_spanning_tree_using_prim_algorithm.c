#include <stdio.h>

#define MAX 100
#define INF 1000000000

int main() {
    int n, graph[MAX][MAX];
    int key[MAX], parent[MAX], visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of vertices\n");
        return 0;
    }

    printf("Enter adjacency matrix (0 means no edge):\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] < 0) {
                printf("Negative weights are not supported\n");
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {
        int u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] &&
                (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }

        if (u == -1 || key[u] == INF) {
            printf("Graph is disconnected. MST does not exist.\n");
            return 0;
        }

        visited[u] = 1;

        if (parent[u] != -1) {
            printf("%d - %d : %d\n",
                   parent[u], u, graph[parent[u]][u]);

            totalWeight += key[u];
        }

        for (int v = 0; v < n; v++) {
            if (graph[u][v] > 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("Minimum spanning tree weight = %d\n",
           totalWeight);

    return 0;
}