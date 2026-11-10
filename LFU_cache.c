#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int key, value, freq;
    struct Node *prev, *next;
} Node;

typedef struct {
    Node *head, *tail;
} List;

Node *nodes[MAX];
List lists[MAX + 1];

int capacity, size = 0;
int minFreq = 0;

void initializeList(List *list) {
    list->head = malloc(sizeof(Node));
    list->tail = malloc(sizeof(Node));

    if (!list->head || !list->tail) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    list->head->next = list->tail;
    list->tail->prev = list->head;
}

void removeNode(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void addFront(List *list, Node *node) {
    node->next = list->head->next;
    node->prev = list->head;

    list->head->next->prev = node;
    list->head->next = node;
}

int isEmpty(List *list) {
    return list->head->next == list->tail;
}

void increaseFrequency(Node *node) {
    int oldFreq = node->freq;

    removeNode(node);
    if (isEmpty(&lists[oldFreq]) && minFreq == oldFreq)
        minFreq++;

    node->freq++;
    addFront(&lists[node->freq], node);
}

int get(int key) {
    if (key < 0 || key >= MAX || nodes[key] == NULL)
        return -1;

    Node *node = nodes[key];

    increaseFrequency(node);

    return node->value;
}

void put(int key, int value) {
    if (key < 0 || key >= MAX)
        return;

    if (capacity == 0)
        return;

    if (nodes[key] != NULL) {
        nodes[key]->value = value;
        increaseFrequency(nodes[key]);
        return;
    }

    if (size == capacity) {
        List *list = &lists[minFreq];

        Node *victim = list->tail->prev;

        removeNode(victim);
        nodes[victim->key] = NULL;

        free(victim);
        size--;
    }

    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    node->key = key;
    node->value = value;
    node->freq = 1;

    addFront(&lists[1], node);

    nodes[key] = node;
    minFreq = 1;
    size++;
}

int main() {
    printf("Enter cache capacity: ");
    scanf("%d", &capacity);

    if (capacity < 0 || capacity > MAX) {
        printf("Invalid capacity\n");
        return 0;
    }

    for (int i = 0; i <= MAX; i++)
        initializeList(&lists[i]);

    put(1, 10);
    put(2, 20);

    printf("Get 1: %d\n", get(1));

    put(3, 30);

    printf("Get 2: %d\n", get(2));
    printf("Get 3: %d\n", get(3));

    put(4, 40);

    printf("Get 1: %d\n", get(1));
    printf("Get 3: %d\n", get(3));
    printf("Get 4: %d\n", get(4));

    return 0;
}