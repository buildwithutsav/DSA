#include <stdio.h>

#define SIZE 101

typedef struct {
    int key;
    int index;
    int used;
} Entry;

Entry table[SIZE] = {0};

int hash(int key) {
    unsigned int x = (unsigned int)key;
    return (int)(x % SIZE);
}

int search(int key) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (h + i) % SIZE;

        if (!table[pos].used)
            return -1;

        if (table[pos].key == key)
            return table[pos].index;
    }

    return -1;
}

void insert(int key, int index) {
    int h = hash(key);

    for (int i = 0; i < SIZE; i++) {
        int pos = (h + i) % SIZE;

        if (!table[pos].used) {
            table[pos].key = key;
            table[pos].index = index;
            table[pos].used = 1;
            return;
        }
    }
}

int main(void) {
    int arr[] = {2, 7, 11, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        int index = search(complement);

        if (index != -1) {
            printf("Indices: %d and %d\n", index, i);
            printf("Values: %d and %d\n", arr[index], arr[i]);
            return 0;
        }

        insert(arr[i], i);
    }

    printf("No solution found\n");
    return 0;
}