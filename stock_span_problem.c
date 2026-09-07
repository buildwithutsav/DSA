#include <stdio.h>

int main() {

    int n, i;

    printf("Enter number of days: ");
    scanf("%d", &n);

    int price[n];
    int span[n];
    int stack[n];

    int top = -1;

    printf("Enter stock prices:\n");

    for(i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }

    for(i = 0; i < n; i++) {

        while(top >= 0 && price[stack[top]] <= price[i]) {

            top--;
        }

        if(top == -1) {

            span[i] = i + 1;
        }

        else {

            span[i] = i - stack[top];
        }

        top++;
        stack[top] = i;
    }

    printf("Stock Span: ");

    for(i = 0; i < n; i++) {

        printf("%d ", span[i]);
    }

    return 0;
}