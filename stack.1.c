//stack program in c using fixed size array

/*#include <stdio.h>
#include <stdlib.h>
int top=-1 ,max=3 , arr[4];
int main(){

    int i,de;
    void push(int);
    int pop(void);

    push(1);
    push(2);
    push(3);

    de= pop();
    printf("popped element%d\n",de);

    push(4);

    for(i=0;i<=top;i++)
    printf("%d",arr[i]);

    return 0;

}
void push(int e)
{
    if(top==max)
    {
        printf("overflow");
        exit(1);
    }

    top=top++;
    arr[top]=e;

}

int pop()
{
    int de;
    if(top==-1)
    {
        printf("underflow");
        exit(1);
    }

    de=arr[top];

    top=top--;
    return de;
}*/


//stack program in c using dynamic size array

#include <stdio.h>
#include <stdlib.h>

int top=-1 , max , *arr;
int main(){
    int n,i,de;
    void push(int);
    int pop(void);

    printf("enter size of array");
    scanf("&d",&n);
    max=n-1;
    arr = malloc(sizeof(int)*n);

    push(1);
    push(2);
    push(3);


    de=pop();
    printf("popped element &d\n",de);
    printf("current top = &d\n",top);

    de=pop();
    printf("popped element &d\n",de);
    printf("current top = &d\n",top);

    de=pop();
    printf("popped element &d\n",de);
    printf("current top = &d\n",top);

    for(i=0;i<=top;i++)
    printf("%d",arr[i]);

    return 0;
}

void push(int e)
{
    if(top==max)
    {
        printf("overflow");
        exit(1);
    }
    top=top++;
    arr[top]=e;
}

int pop()
{
    int de;
    if(top==-1)
    {
        printf("under flow");
        exit(1);
    }
    de=arr[top];
    top=top--;
    return de;
}

