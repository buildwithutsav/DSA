#include <stdio.h>
#include <string.h>

#define MAX 1000

void minimumWindow(char S[], char T[]) {
    int n = strlen(S);
    int m = strlen(T);

    int minLength = n + 1;
    int start = -1;

    int i = 0;

    while (i < n) {
        int j = 0;

        // Forward matching
        while (i < n) {
            if (S[i] == T[j])
                j++;

            if (j == m)
                break;

            i++;
        }

        if (i == n)
            break;

        int end = i;
        j = m - 1;

        // Backward matching
        while (j >= 0) {
            if (S[i] == T[j])
                j--;

            i--;
        }

        int currentStart = i + 1;
        int currentLength = end - currentStart + 1;

        if (currentLength < minLength) {
            minLength = currentLength;
            start = currentStart;
        }

        // Continue after the beginning of this window
        i = currentStart + 1;
    }

    if (start == -1) {
        printf("No valid window found\n");
    } else {
        printf("Minimum window: ");
        for (int k = start; k < start + minLength; k++)
            putchar(S[k]);

        printf("\nLength: %d\n", minLength);
    }
}

int main() {
    char S[MAX], T[MAX];

    printf("Enter main string: ");
    scanf("%999s", S);

    printf("Enter target string: ");
    scanf("%999s", T);

    minimumWindow(S, T);

    return 0;
}