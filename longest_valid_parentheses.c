#include <stdio.h>
#include <string.h>

#define MAX 100005

int longestValidParentheses(char s[]) {
    int stack[MAX];
    int top = -1;
    int maxLength = 0;

    stack[++top] = -1;

    for (int i = 0; s[i] != '\0'; i++) {

        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;

            if (top == -1) {
                stack[++top] = i;
            } else {
                int length = i - stack[top];

                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }
    }

    return maxLength;
}

int main() {
    char s[MAX];

    scanf("%100000s", s);

    printf("%d\n", longestValidParentheses(s));

    return 0;
}