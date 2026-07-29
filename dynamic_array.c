#include <stdio.h>
#include <stdlib.h>
int main(){

    int rows, columns;
    int i , j ;
    int **arr;

    printf("Enter the number of rows and columns;");
    scanf("%d %d", &rows, &columns);

    arr = (int **) malloc (rows * sizeof(int*));
    for(i=0; i<rows ; i++){
        arr[i] = (int **) malloc (columns * sizeof (int*));

    }

    printf("Enter the Elements of the array ");
    for(i=0 ; i<rows ; i++){
        for ( j=0 ; j <columns ; j++){
    scanf("%d", &arr[i][j]);

        }
    }
    
    printf("\n2D Array is :\n");
    for(i=0 ; i < rows ; i++){
        for(j=0 ; j< columns ; j++){
            printf("%d", arr[i][j]);
        }
        printf("\n");

    }

    for(i=0 ; i<rows ; i++){
        free(arr[i]);

    }
    free(arr);

    return 0;
}