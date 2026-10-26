#include <stdio.h>

typedef struct {
    int value;
    int frequency;
} Item;

int main(void) {
    int arr[] = {1, 1, 1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    Item items[100];
    int distinct = 0;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < distinct; j++) {
            if (items[j].value == arr[i]) {
                items[j].frequency++;
                found = 1;
                break;
            }
        }

        if (!found) {
            items[distinct].value = arr[i];
            items[distinct].frequency = 1;
            distinct++;
        }
    }

    if (k <= 0 || k > distinct) {
        printf("Invalid k\n");
        return 0;
    }

    for (int i = 0; i < distinct - 1; i++) {
        for (int j = i + 1; j < distinct; j++) {
            if (items[j].frequency > items[i].frequency) {
                Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("Top %d frequent elements: ", k);
    for (int i = 0; i < k; i++)
        printf("%d ", items[i].value);

    printf("\n");
    return 0;
}