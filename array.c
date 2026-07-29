#include <stdio.h>


    int arr[4];
    int max = 3;
    int top = -1;
    
    void push(int element);
    int pop();

int main() {
    push(5);
    push(4);
    int de = pop();
printf("%d", de);
    return 0;
}

void push(int element)
{
  if(top == max)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        arr[top] = element;
    }
}
int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }
    else
    {
        int element = arr[top];
        top--;
        return element;
    }
}