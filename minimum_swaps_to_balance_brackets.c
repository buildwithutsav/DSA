
#include <stdio.h>
#include <string.h>

int minSwaps(char s[]) {
    int balance = 0;
    int unmatchedClose = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '[') {
            balance++;
        } else if (s[i] == ']') {
            if (balance > 0)
                balance--;
            else
                unmatchedClose++;
        } else {
            return -1;
        }
    }

    return (unmatchedClose + 1) / 2;
}

int main() {
    char s[1000];

    printf("Enter bracket string: ");
    scanf("%999s", s);

    int n = strlen(s);
    int open = 0, close = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '[')
            open++;
        else if (s[i] == ']')
            close++;
        else {
            printf("Invalid character\n");
            return 0;
        }
    }

    if (open != close) {
        printf("Equal numbers of brackets are required\n");
        return 0;
    }

    printf("Minimum swaps: %d\n", minSwaps(s));

    return 0;
}
