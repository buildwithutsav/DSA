#include <stdio.h>

int main() {

    int n, i, target;
    int found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &target);

    for(i = 0; i < n; i++) {

        if(arr[i] == target) {

            printf("Element found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Element not found\n");
    }

    return 0;
}