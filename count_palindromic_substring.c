#include <stdio.h>
#include <string.h>

#define MAX 1000

int expand(char s[], int left, int right, int n) {
    int count = 0;

    while (left >= 0 && right < n &&
           s[left] == s[right]) {
        count++;
        left--;
        right++;
    }

    return count;
}

int main() {
    char s[MAX];

    printf("Enter a string: ");
    scanf("%999s", s);

    int n = strlen(s);
    int count = 0;

    for (int i = 0; i < n; i++) {
        // Odd-length palindromes
        count += expand(s, i, i, n);

        // Even-length palindromes
        count += expand(s, i, i + 1, n);
    }

    printf("Total palindromic substrings: %d\n", count);

    return 0;
}