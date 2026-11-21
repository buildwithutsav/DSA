
#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int n;
    char words[MAX][100];

    printf("Enter number of words: ");
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid input\n");
        return 0;
    }

    int masks[MAX] = {0};
    int lengths[MAX];

    printf("Enter words (lowercase letters only):\n");

    for (int i = 0; i < n; i++) {
        scanf("%99s", words[i]);

        lengths[i] = strlen(words[i]);

        for (int j = 0; words[i][j] != '\0'; j++) {
            if (words[i][j] < 'a' || words[i][j] > 'z') {
                printf("Invalid character\n");
                return 0;
            }

            int bit = words[i][j] - 'a';
            masks[i] |= (1 << bit);
        }
    }

    int maxProduct = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((masks[i] & masks[j]) == 0) {
                int product = lengths[i] * lengths[j];

                if (product > maxProduct)
                    maxProduct = product;
            }
        }
    }

    printf("Maximum product: %d\n", maxProduct);

    return 0;
}
