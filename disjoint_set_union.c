#include <stdio.h>

#define N 7

int parent[N];
int size[N];

void initialize(void) {
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);

    return parent[x];
}

void unite(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB)
        return;

    if (size[rootA] < size[rootB]) {
        int temp = rootA;
        rootA = rootB;
        rootB = temp;
    }

    parent[rootB] = rootA;
    size[rootA] += size[rootB];
}

int main(void) {
    initialize();

    unite(0, 1);
    unite(1, 2);
    unite(3, 4);
    unite(5, 6);

    printf("0 and 2 connected? %s\n",
           find(0) == find(2) ? "Yes" : "No");

    printf("0 and 4 connected? %s\n",
           find(0) == find(4) ? "Yes" : "No");

    unite(2, 4);

    printf("After merging groups, 0 and 4 connected? %s\n",
           find(0) == find(4) ? "Yes" : "No");

    return 0;
}