#include <stdio.h>
#include <string.h>

#define N 6
#define LEN 4

char words[N][LEN] = {
    "hot", "dot", "dog", "lot", "log", "cog"
};

int visited[N];

int isAdjacent(char a[], char b[]) {
    int diff = 0;

    for (int i = 0; a[i]; i++) {
        if (a[i] != b[i])
            diff++;
    }

    return diff == 1;
}

int wordLadder(char start[], char end[]) {
    char queue[N + 1][LEN];
    int distance[N + 1];

    int front = 0, rear = 0;

    strcpy(queue[rear], start);
    distance[rear++] = 1;

    while (front < rear) {
        char current[LEN];
        strcpy(current, queue[front]);

        int currentDistance = distance[front++];

        if (strcmp(current, end) == 0)
            return currentDistance;

        for (int i = 0; i < N; i++) {
            if (!visited[i] && isAdjacent(current, words[i])) {
                visited[i] = 1;

                strcpy(queue[rear], words[i]);
                distance[rear++] = currentDistance + 1;
            }
        }
    }

    return 0;
}

int main() {
    char start[] = "hit";
    char end[] = "cog";

    int result = wordLadder(start, end);

    if (result)
        printf("Minimum Transformation Length: %d\n", result);
    else
        printf("Transformation not possible.\n");

    return 0;
}