#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    char stack[100];

    int top =-1;
    int i;
    int palindrome = 1;

    printf("Enter a string: ");
    scanf("%s",str);

    for(i=0; str[i] !='0';i++){
        top++;
        stack[top]=str[i];

    }

    for(i=0;str[i] != '0'; i++){
        if(str[i] != stack[top]){
            palindrome =0;
            break;
        }

        top--;

    }

    if(palindrome == 1){
        printf("palindrome");
    }
    else{
        printf("not palindrome");

    }

    return 0;

    }

