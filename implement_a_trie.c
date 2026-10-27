#include <stdio.h>
#include <stdlib.h>

#define ALPHABET 26

typedef struct TrieNode {
    struct TrieNode *children[ALPHABET];
    int isEnd;
} TrieNode;

TrieNode *createNode(void) {
    TrieNode *node = calloc(1, sizeof(TrieNode));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    return node;
}

void insert(TrieNode *root, const char *word) {
    TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (index < 0 || index >= ALPHABET)
            return;

        if (current->children[index] == NULL)
            current->children[index] = createNode();

        current = current->children[index];
    }

    current->isEnd = 1;
}

int search(TrieNode *root, const char *word) {
    TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';

        if (index < 0 || index >= ALPHABET ||
            current->children[index] == NULL)
            return 0;

        current = current->children[index];
    }

    return current->isEnd;
}

void freeTrie(TrieNode *root) {
    if (root == NULL)
        return;

    for (int i = 0; i < ALPHABET; i++)
        freeTrie(root->children[i]);

    free(root);
}

int main(void) {
    TrieNode *root = createNode();

    insert(root, "apple");
    insert(root, "app");
    insert(root, "bat");

    printf("Search app: %s\n",
           search(root, "app") ? "Found" : "Not found");

    printf("Search appl: %s\n",
           search(root, "appl") ? "Found" : "Not found");

    printf("Search bat: %s\n",
           search(root, "bat") ? "Found" : "Not found");

    freeTrie(root);
    return 0;
}