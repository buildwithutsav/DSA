
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define HASH_SIZE 2003

typedef struct Node {
    long long diff;
    int length;
    struct Node *next;
} Node;

Node *table[MAX][HASH_SIZE];

unsigned int hashValue(long long diff) {
    unsigned long long x = (unsigned long long)diff;
    return (unsigned int)(x % HASH_SIZE);
}

int getLength(int index, long long diff) {
    unsigned int h = hashValue(diff);

    Node *current = table[index][h];

    while (current != NULL) {
        if (current->diff == diff)
            return current->length;

        current = current->next;
    }

    return 1;
}

void updateLength(int index, long long diff, int length) {
    unsigned int h = hashValue(diff);

    Node *current = table[index][h];

    while (current != NULL) {
        if (current->diff == diff) {
            if (length > current->length)
                current->length = length;
            return;
        }

        current = current->next;
    }

    Node *newNode = malloc(sizeof(Node));

    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newNode->diff = diff;
    newNode->length = length;
    newNode->next = table[index][h];

    table[index][h] = newNode;
}

void freeTable(int n) {
    for (int i = 0; i < n; i++) {
        for (int h = 0; h < HASH_SIZE; h++) {
            Node *current = table[i][h];

            while (current != NULL) {
                Node *temp = current;
                current = current->next;
                free(temp);
            }

            table[i][h] = NULL;
        }
    }
}

int longestArithmeticSubsequence(int arr[], int n) {
    if (n <= 2)
        return n;

    int answer = 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long diff = (long long)arr[i] - arr[j];

            int length = getLength(j, diff) + 1;

            updateLength(i, diff, length);

            if (length > answer)
                answer = length;
        }
    }

    return answer;
}

int main() {
    int n;
    int arr[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter array elements: ");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int answer = longestArithmeticSubsequence(arr, n);

    printf("Longest arithmetic subsequence: %d\n", answer);

    freeTable(n);

    return 0;
}
