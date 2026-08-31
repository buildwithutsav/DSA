#include <stdio.h>
#define SIZE 5

int stack[SIZE];

int top = -1;

void push(int value){
    if(top == SIZE -1){
        printf("Stack Overflow!\n");

    }
    else{
        top++;
        stack[top]= value;

        printf("%d pushed into stack.\n", value);

    }
}

void pop(){
    if(top == -1){
        printf("stack underflow!\n");
    }

    else{
        printf("%d popped from stack,\n",stack[top]);
        top--;
    }
}

void peak(){
    if(top == -1){
        printf("stack is empty,\n");
    }

    else{
        printf("Top element = %d\n", stack[top]);
    }
}

void display(){
    int i;
    if(top == -1){
        printf("stack is empty.\n");
        return;
    }

    printf("Stack: ");

    for(i = top; i>=0; i--){
        printf("%d ",stack[i]);
    }

    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);

    display();

    peak();

    pop();

    display();

    return 0;
}