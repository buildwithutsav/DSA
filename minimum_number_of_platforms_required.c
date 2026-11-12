#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int main() {
    int n;
    int arrival[MAX], departure[MAX];

    printf("Enter number of trains: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of trains\n");
        return 0;
    }

    printf("Enter arrival times:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arrival[i]);

    printf("Enter departure times:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &departure[i]);

        if (arrival[i] < 0 || arrival[i] >= 2400 ||
            departure[i] < 0 || departure[i] >= 2400 ||
            arrival[i] % 100 >= 60 ||
            departure[i] % 100 >= 60 ||
            departure[i] < arrival[i]) {

            printf("Invalid time\n");
            return 0;
        }
    }

    qsort(arrival, n, sizeof(int), compare);
    qsort(departure, n, sizeof(int), compare);

    int i = 1, j = 0;
    int platforms = 1;
    int maximum = 1;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }

        if (platforms > maximum)
            maximum = platforms;
    }

    printf("Minimum platforms required = %d\n", maximum);

    return 0;
}