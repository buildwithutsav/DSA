#include <stdio.h>
int main(){
    int n ,i ,j;
    int duplicate;

    printf("enter number of elements: ");
    scanf("%d" ,&n);

    int arr[n];

    printf("enter elements:\n");

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    printf("unique elements: ");

    for(i=0 ; i<n ; i++){
        duplicate = 0;

        for(j=0;j<i;j++){

            if(arr[i] == arr[j]){
                duplicate = 1;
                break;
            }
        }

        if(duplicate == 0){
            printf("%d",arr[i]);


        }
    }

    return 0;


}