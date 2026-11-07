#include <stdio.h>
#include <stdlib.h>

#define CAPACITY 3
#define SIZE 101

struct Node {
    int key, value;
    struct Node *prev, *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

struct Node *hash[SIZE] = {NULL};

int hashFunction(int key) {
    int h = key % SIZE;
    return h < 0 ? h + SIZE : h;
}

struct Node* search(int key) {
    struct Node *temp = hash[hashFunction(key)];

    while (temp != NULL) {
        if (temp->key == key)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void removeNode(struct Node *node) {
    if (node->prev)
        node->prev->next = node->next;
    else
        head = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        tail = node->prev;
}

void insertFront(struct Node *node) {
    node->prev = NULL;
    node->next = head;

    if (head)
        head->prev = node;
    else
        tail = node;

    head = node;
}

void deleteHash(struct Node *node) {
    int h = hashFunction(node->key);

    struct Node **p = &hash[h];

    while (*p != NULL) {
        if (*p == node) {
            *p = node->next;
            return;
        }

        p = &((*p)->prev);
    }
}

int get(int key) {
    struct Node *node = search(key);

    if (!node)
        return -1;

    removeNode(node);
    insertFront(node);

    return node->value;
}

void put(int key, int value) {
    struct Node *node = search(key);

    if (node) {
        node->value = value;
        removeNode(node);
        insertFront(node);
        return;
    }

    int count = 0;

    for (int i = 0; i < SIZE; i++) {
        struct Node *temp = hash[i];

        while (temp) {
            count++;
            temp = temp->prev;
        }
    }

    if (count == CAPACITY) {
        struct Node *old = tail;

        removeNode(old);
        deleteHash(old);
        free(old);
    }

    node = (struct Node*)malloc(sizeof(struct Node));

    node->key = key;
    node->value = value;

    int h = hashFunction(key);

    node->prev = hash[h];
    hash[h] = node;

    insertFront(node);
}

int main() {
    put(1, 10);
    put(2, 20);
    put(3, 30);

    printf("Get 1: %d\n", get(1));

    put(4, 40);

    printf("Get 2: %d\n", get(2));
    printf("Get 3: %d\n", get(3));
    printf("Get 4: %d\n", get(4));

    return 0;
}