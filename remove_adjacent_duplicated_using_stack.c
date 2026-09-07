#include <stdio.h>

int main() {

    char str[100];
    char stack[100];

    int top = -1;
    int i;

    printf("Enter string: ");
    scanf("%s", str);

    for(i = 0; str[i] != '\0'; i++) {

        if(top >= 0 && stack[top] == str[i]) {

            top--;
        }

        else {

            top++;
            stack[top] = str[i];
        }
    }

    printf("Result: ");

    for(i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }

    return 0;
}