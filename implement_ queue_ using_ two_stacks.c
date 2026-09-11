#include <stdio.h>
#define SIZE 100

int stack1[SIZE], stack2[SIZE];
int top1 = -1, top2 = -1;

void enqueue(int value){
    top1++;
    stack1[top1]=value;

    printf("%d inserted. \n",value);

}
void dequeue(){
    if(top1 == -1 && top2 == -1){
        printf("queue is empty!\n");
        return;

    }
    if(top2 == -1){
        while(top1!=-1){
            top2++;
            stack2[top2]=stack1[top1];

            top1--;
        }
    }

    printf("%d deleted.\nstack2[top2]");

    top2--;
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    dequeue();
    dequeue();
    dequeue();

    enqueue(40);
    dequeue();

    return 0;

}