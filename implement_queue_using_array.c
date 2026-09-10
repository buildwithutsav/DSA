#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int value){

    if(rear == SIZE -1){
        printf("Queue is full!\n");
    }
    else{
        if(front == -1){
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted into queue. \n", value);

    }
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue underflow!\n");

    }

    else{
        printf("%d deleted from queue. \n", queue[front]);
        front++;
        
        if(front > rear){
            front = -1;
            rear = -1;

        }
    }
}

void peak(){
    if(front == -1){
        printf("Queue is empty. \n");

    }
    else{
        printf("front element = %d\n" , queue[front]);
    }
}

void display(){
    int i;
    if(front == -1){
        printf("queue is empty. \n");
        return;
    }
    printf("queue: ");
    for(i = front; i<=rear; i++){
        printf("%d ", queue[i]);

    }
    printf("\n");


}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    peak();
    return 0;
}