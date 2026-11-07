#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str[] = "ABACDC";

    int n = strlen(str);

    int palindrome[MAX][MAX] = {0};
    int cuts[MAX];

    for (int i = 0; i < n; i++)
        palindrome[i][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {

            int j = i + len - 1;

            if (str[i] == str[j] &&
                (len == 2 || palindrome[i + 1][j - 1])) {
                palindrome[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (palindrome[0][i]) {
            cuts[i] = 0;
        }
        else {
            cuts[i] = i;

            for (int j = 1; j <= i; j++) {
                if (palindrome[j][i] &&
                    cuts[j - 1] + 1 < cuts[i]) {

                    cuts[i] = cuts[j - 1] + 1;
                }
            }
        }
    }

    printf("Minimum Cuts: %d\n", cuts[n - 1]);

    return 0;
}