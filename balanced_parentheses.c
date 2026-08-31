#include <stdio.h>

#define SIZE 100

char stack[SIZE];
int top = -1;



void push(char ch){

    top++;
    stack[top] = ch;

}

char pop(){
    char ch = stack[top];
    top--;

    return ch;
}

int matching(char open , char close){
    if(open == '('&& close == ')')
    return 1;

    if(open == '{' && close == '}')
    return 1;


    if(open == '[' && close == ']')
    return 1;

    return 0;
}

int main(){
    char str[100];
    int i;
    int balanced = 1;

    printf("enter brackets:");
    scanf("%s", str);

    for(i=0; str[i] != '0' ; i++){
        char ch = str[i];

        if(ch == '(' || ch == '{' || ch == '['){

            push(ch);

        }

        else if(ch ==')' || ch == '}'  || ch == ']'){
            if(top == -1){
                balanced = 0;
                break;
            }

            char opening = pop();
            if(!matching(opening, ch)){
                balanced = 0;
                break;

            }
        }
    }

    if(top != -1){
        balanced = 0;

    }

    if(balanced == 1)
    printf("balanced");
    else
    printf("not balanced ");

    return 0 ;
}