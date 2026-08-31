#include <stdio.h>
#include <string.h>


int main(){
    char str[100];
    char stack[100];

    int top = -1;
    int i;

    printf("Enter a string: ");
    fgets(str , sizeof(str), stdin);

    str[strcspn(str ,"\n")] = '\0';

    for(i = 0; str[i] != '\0'; i++){
        top++;
        stack[top] = str[i];

    }

    printf("Reversed string: ");
    while(top >= 0){
        printf("%c" , stack[top]);

        top--;
    }

    return 0;
}