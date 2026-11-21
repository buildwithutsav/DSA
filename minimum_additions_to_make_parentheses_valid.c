
#include <stdio.h>
#include <string.h>

int minAdditions(char s[]) {
    int open = 0;
    int additions = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            open++;
        }
        else if (s[i] == ')') {
            if (open > 0)
                open--;
            else
                additions++;
        }
        else {
            return -1;
        }
    }

    return additions + open;
}

int main() {
    char s[1000];

    printf("Enter parentheses string: ");
    scanf("%999s", s);

    int result = minAdditions(s);

    if (result == -1)
        printf("Invalid characters in input\n");
    else
        printf("Minimum additions required: %d\n", result);

    return 0;
}
