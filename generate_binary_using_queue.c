#include <stdio.h>
#include <string.h>

#define SIZE 100

int mian(){
    int n, i ;

    char queue[SIZE][20];

    int front = 0;
    int rear = 0;

    printf("Enter N: ");
    scanf("%d",&n);

    strcpy(queue[rear],"1");
    rear++;

    for(i = 0; i<n; i++){
        char current[20];

        strcpy(current , queue[front]);
        front++;

        printf("%s\n", current);
        strcpy(queue[rear], current);
        strcat(queue[rear],"0");
        rear++;

        strcpy(queue[rear],current);
        strcat(queue[rear],"1");
        rear++;
        
    }

    return 0;
}