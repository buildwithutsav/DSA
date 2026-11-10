#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
#define BITS 31

typedef struct TrieNode {
    struct TrieNode *child[2];
} TrieNode;

TrieNode* createNode() {
    TrieNode *node = calloc(1, sizeof(TrieNode));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    return node;
}

void insert(TrieNode *root, unsigned int num) {
    TrieNode *current = root;

    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1U;

        if (current->child[bit] == NULL)
            current->child[bit] = createNode();

        current = current->child[bit];
    }
}

unsigned int findMaxXor(TrieNode *root,
                        unsigned int num) {
    TrieNode *current = root;
    unsigned int result = 0;

    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1U;
        int opposite = 1 - bit;

        if (current->child[opposite] != NULL) {
            result |= (1U << i);
            current = current->child[opposite];
        } else {
            current = current->child[bit];
        }
    }

    return result;
}

int main() {
    int n;
    unsigned int arr[MAX];

    printf("Enter array size: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid size\n");
        return 0;
    }

    printf("Enter non-negative array elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%u", &arr[i]);

        if (arr[i] > 2147483647U) {
            printf("Element out of supported range\n");
            return 0;
        }
    }

    TrieNode *root = createNode();

    insert(root, 0);

    unsigned int prefix = 0;
    unsigned int maximum = 0;

    for (int i = 0; i < n; i++) {
        prefix ^= arr[i];

        unsigned int current =
            findMaxXor(root, prefix);

        if (current > maximum)
            maximum = current;

        insert(root, prefix);
    }

    printf("Maximum XOR subarray = %u\n", maximum);

    return 0;
}