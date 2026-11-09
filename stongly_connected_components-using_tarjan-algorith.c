#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];
int disc[MAX], low[MAX], stack[MAX];
int inStack[MAX];
int top = -1, timer = 0;

void tarjan(int u, int n) {
    disc[u] = low[u] = ++timer;

    stack[++top] = u;
    inStack[u] = 1;

    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
            if (disc[v] == 0) {
                tarjan(v, n);

                if (low[v] < low[u])
                    low[u] = low[v];
            }
            else if (inStack[v] && disc[v] < low[u]) {
                low[u] = disc[v];
            }
        }
    }

    if (low[u] == disc[u]) {
        printf("SCC: ");

        int v;
        do {
            v = stack[top--];
            inStack[v] = 0;
            printf("%d ", v);
        } while (v != u);

        printf("\n");
    }
}

int main() {
    int n, m, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter directed edges:\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    for (int i = 0; i < n; i++) {
        if (disc[i] == 0)
            tarjan(i, n);
    }

    return 0;
}