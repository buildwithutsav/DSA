#include <stdio.h>
#include <string.h>

#define MAX 100005

int main() {
    char num[MAX];
    int k;

    scanf("%100000s", num);
    scanf("%d", &k);

    int n = strlen(num);

    if (k < 0 || k > n) {
        printf("Invalid k\n");
        return 0;
    }

    if (k == n) {
        printf("0\n");
        return 0;
    }

    char stack[MAX];
    int top = -1;

    for (int i = 0; i < n; i++) {

        while (top >= 0 &&
               k > 0 &&
               stack[top] > num[i]) {
            top--;
            k--;
        }

        stack[++top] = num[i];
    }

    // Remove remaining digits from the end.
    while (k > 0 && top >= 0) {
        top--;
        k--;
    }

    // Remove leading zeroes.
    int start = 0;

    while (start <= top && stack[start] == '0') {
        start++;
    }

    if (start > top) {
        printf("0\n");
    } else {
        for (int i = start; i <= top; i++) {
            printf("%c", stack[i]);
        }

        printf("\n");
    }

    return 0;
}