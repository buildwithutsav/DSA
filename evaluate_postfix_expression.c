#include <stdio.h>
#include <ctype.h>

int stack[100];
int top = -1;

void push(int value){
    top++;
    stack[top] = value;

}

int pop(){
    int value = stack[top];
    top--;
    return value;

}

int main(){

    char expression[100];
    int i;
    printf("Enter postfix expression: ");
    scanf("%s", expression);

    for(i =0;expression[i] !='0';i++){
        char ch = expression[i];

        if(isdigit(ch)){
            push(ch - '0');

        }

        else {
            int b = pop();
            int a = pop();

            switch(ch){
                case '+':
                push(a+b);

                break;

                case '-':
                push(a-b);
                break;

                case'*':
                push(a*b);
                break;

                case'/':
                push(a/b);
                break;

            }

        }
    }

    printf("Result = %d",pop());
     return 0;
}