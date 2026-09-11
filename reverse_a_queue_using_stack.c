#include <stdio.h>
#define SIZE 5

int main(){
    int queue[SIZE];
    int stack[SIZE];


    int front = -1;
    int rear = -1;
    int top = -1;
    int i;

    printf("enter 5 queue element:  ");

    for(i = 0; i < SIZE; i++){
        scanf("%d", &queue[i]);
        rear++;
    }

    while(front <= rear){
        top++;
        stack[top] = queue[front];
        front++;

    }

    front = 0;
    rear = -1;

    while(top >= 0 ){
        rear++;
        queue[rear] = stack[top];
        top--;
    }

    printf("reversed queue: ");

    for(i=front; i<=rear; i++){
        printf("%d ", queue[i]);
    }

    return 0 ;
}