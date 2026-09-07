#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ch) {

    top++;
    stack[top] = ch;
}

char pop() {

    char ch = stack[top];
    top--;

    return ch;
}

int precedence(char ch) {

    if(ch == '+' || ch == '-')
        return 1;

    if(ch == '*' || ch == '/')
        return 2;

    return 0;
}

int main() {

    char expression[100];
    int i;

    printf("Enter infix expression: ");
    scanf("%s", expression);

    printf("Postfix: ");

    for(i = 0; expression[i] != '\0'; i++) {

        char ch = expression[i];

        if(isalnum(ch)) {

            printf("%c", ch);
        }

        else if(ch == '(') {

            push(ch);
        }

        else if(ch == ')') {

            while(top != -1 && stack[top] != '(') {
                printf("%c", pop());
            }

            pop();
        }

        else {

            while(top != -1 &&
                  precedence(stack[top]) >= precedence(ch)) {

                printf("%c", pop());
            }

            push(ch);
        }
    }

    while(top != -1) {
        printf("%c", pop());
    }

    return 0;
}