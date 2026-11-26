#include <stdio.h>
#include <string.h>

#define MAX 100005

int main() {
    char s[MAX];

    scanf("%100000s", s);

    int freq[256] = {0};
    int used[MAX] = {0};

    for (int i = 0; s[i] != '\0'; i++)
        freq[(unsigned char)s[i]]++;

    int deletions = 0;

    for (int i = 0; i < 256; i++) {
        int f = freq[i];

        while (f > 0 && used[f]) {
            f--;
            deletions++;
        }

        if (f > 0)
            used[f] = 1;
    }

    printf("%d\n", deletions);

    return 0;
}