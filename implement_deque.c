#include <stdio.h>
#define SIZE 5
int deque[SIZE];
int front = -1;
int rear = -1;
void insertrear(int value){
    if(rear == SIZE -1){
        printf("deque is full!\n");
        return;
    }
    if(front == -1)
    front =0;
    rear++;
    deque[rear]=value;
}
void insertFront(int value){
    if(front == 0){
        printf("no space at front!\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;

    }

    else{
        front--;
    }
    deque[front]=value;

}

void deleteFront(){
    if(front == -1){
        printf("deque is empty!\n");
        return;
    }

    printf("%d deleted.\n",deque[front]);

    front++;

    if(front > rear){
        front = -1;
        rear = -1;

    }
}

void deleteRear(){
    if(rear == -1){
        printf("deque is empty!\n");
        return;
    }

    printf("%d deleted.\n",deque[rear]);
    rear--;

    if(rear < front){
        front = -1;
        rear = -1;
    }
}

void display(){
    if(front == -1){
        printf("deque is empty!\n");
        return;
    }

    printf("deque: ");

    for(int i = front; i<=rear ; i++){
        printf("%d",deque[i]);
    }
    printf("\n");
}

int main(){
    
    insertrear(10);
    insertrear(20);
    insertFront(5);
    display();
    deleteFront();
    display();
    deleteRear();
    display();
    return 0;
}
