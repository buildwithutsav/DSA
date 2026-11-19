
#include <stdio.h>
#include <string.h>

void findAnagrams(char s[], char p[]) {
    int n = strlen(s);
    int m = strlen(p);

    if (m == 0 || m > n)
        return;

    int pattern[256] = {0};
    int window[256] = {0};

    for (int i = 0; i < m; i++) {
        pattern[(unsigned char)p[i]]++;
        window[(unsigned char)s[i]]++;
    }

    printf("Starting indices: ");

    for (int i = 0; i <= n - m; i++) {
        int match = 1;

        for (int j = 0; j < 256; j++) {
            if (pattern[j] != window[j]) {
                match = 0;
                break;
            }
        }

        if (match)
            printf("%d ", i);

        if (i < n - m) {
            window[(unsigned char)s[i]]--;
            window[(unsigned char)s[i + m]]++;
        }
    }

    printf("\n");
}

int main() {
    char s[1000], p[1000];

    printf("Enter main string: ");
    scanf("%999s", s);

    printf("Enter pattern: ");
    scanf("%999s", p);

    findAnagrams(s, p);

    return 0;
}
