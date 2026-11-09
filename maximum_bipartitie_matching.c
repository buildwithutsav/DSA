#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int matchR[MAX];
int visited[MAX];

int dfs(int u, int nRight) {
    for (int v = 0; v < nRight; v++) {
        if (graph[u][v] && !visited[v]) {
            visited[v] = 1;

            if (matchR[v] == -1 ||
                dfs(matchR[v], nRight)) {

                matchR[v] = u;
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int nLeft, nRight, e;
    int u, v, result = 0;

    printf("Enter left vertices, right vertices and edges: ");
    scanf("%d %d %d", &nLeft, &nRight, &e);

    printf("Enter edges (left right):\n");

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < nRight; i++)
        matchR[i] = -1;

    for (int u = 0; u < nLeft; u++) {
        for (int i = 0; i < nRight; i++)
            visited[i] = 0;

        if (dfs(u, nRight))
            result++;
    }

    printf("Maximum matching = %d\n", result);

    for (int v = 0; v < nRight; v++) {
        if (matchR[v] != -1)
            printf("Left %d - Right %d\n", matchR[v], v);
    }

    return 0;
}